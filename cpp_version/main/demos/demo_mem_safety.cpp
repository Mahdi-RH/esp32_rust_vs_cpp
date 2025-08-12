#include "demo.h"
#include "student.h"
#include "esp_log.h"
#include <memory>

static const char* TAG_MEM = "MemSafety";

// Use-before-initialization
void demo_use_before_init() {
    ESP_LOGI(TAG_MEM, "Running use-before-init demo");
    Student s; // ❌ Not initialized
    print_student(s); // Prints garbage
}

// Dangling pointer
void process_data(std::unique_ptr<int> data) {
    ESP_LOGI(TAG_MEM, "Processing data: %d", *data);
}

void demo_dangling_pointer() {
    ESP_LOGI(TAG_MEM, "Running dangling pointer demo");
    std::unique_ptr<int> a = std::make_unique<int>(42);
    ESP_LOGI(TAG_MEM, "Original data: %d", *a);
    process_data(std::move(a)); // Ownership moved
    ESP_LOGI(TAG_MEM, "After processing: %d", *a); // ❌ UB
}

// Raw pointer
void demo_raw_pointer() {
    ESP_LOGI(TAG_MEM, "Running raw pointer demo");
    const int* ptr = nullptr;
    int value = *ptr; // ❌ UB: dereferencing null
    ESP_LOGI(TAG_MEM, "Value: %d", value);
}
