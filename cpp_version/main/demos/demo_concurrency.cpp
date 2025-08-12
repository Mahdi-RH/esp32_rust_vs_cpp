#include "demo.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <vector>
#include <string>
#include <thread>
#include <mutex>

static const char* TAG_CONC = "Concurrency";

// Race condition demo
void demo_race_condition() {
    ESP_LOGI(TAG_CONC, "Starting race condition demo");

    std::string shared_data;
    std::vector<std::thread> workers;

    for (int i = 0; i < 10; ++i) {
        workers.emplace_back([&shared_data, i]() {
            shared_data += "Thread " + std::to_string(i) + " ran\n"; //  Data race
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        });
    }

    for (auto& w : workers) {
        w.join();
    }

    ESP_LOGI(TAG_CONC, "Final shared data:\n%s", shared_data.c_str());
}

// Deadlock demo
void demo_deadlock() {
    ESP_LOGI(TAG_CONC, "Starting deadlock demo");

    std::mutex mtx1, mtx2;

    auto task1 = std::thread([&]() {
        std::lock_guard<std::mutex> lock1(mtx1);
        vTaskDelay(pdMS_TO_TICKS(100));
        std::lock_guard<std::mutex> lock2(mtx2); // Waits forever if task2 owns it
    });

    auto task2 = std::thread([&]() {
        std::lock_guard<std::mutex> lock2(mtx2);
        vTaskDelay(pdMS_TO_TICKS(100));
        std::lock_guard<std::mutex> lock1(mtx1);
    });

    task1.join();
    task2.join();
}
