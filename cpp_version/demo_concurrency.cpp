#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

// Race condition demo
void demo_race_condition() {
    
    std::cout << "Starting race condition demo" << std::endl;

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
std::cout << "Final shared data:\n" << shared_data << std::endl;

}

// Deadlock demo
void demo_deadlock() {
    std::cout << "Starting deadlock demo" << std::endl;


    std::mutex mtx1, mtx2;

    auto task1 = std::thread([&]() {
        std::lock_guard<std::mutex> lock1(mtx1);
       // vTaskDelay(pdMS_TO_TICKS(100));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::lock_guard<std::mutex> lock2(mtx2); // Waits forever if task2 owns it
    });

    auto task2 = std::thread([&]() {
        std::lock_guard<std::mutex> lock2(mtx2);
        // vTaskDelay(pdMS_TO_TICKS(100));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::lock_guard<std::mutex> lock1(mtx1);
    });

    task1.join();
    task2.join();
}

int main() {
  
  demo_deadlock();
    return 0;
}