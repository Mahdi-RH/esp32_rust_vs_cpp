#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 10
#define BUFFER_SIZE 1024


extern "C" void concurency_unsafe_function()
{
    int workers_threads_num = 10;
    
    auto shared_data = std::make_shared<std::string>("");
    std::vector<std::thread> thread_handles;

    for (int i = 0; i < workers_threads_num; ++i) {
        auto shared_data_clone = shared_data;
        thread_handles.emplace_back([shared_data_clone, i]() {
            // This is a potential data race!
            *shared_data_clone += "Thread " + std::to_string(i) + " ran\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        });
    }

    for (auto& handle : thread_handles) {
        handle.join();
    }

    std::cout << "Final shared data:\n" << *shared_data << std::endl;
}
