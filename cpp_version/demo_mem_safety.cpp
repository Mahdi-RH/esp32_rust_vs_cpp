#include <memory>
#include <iostream>
#include <iostream>
#include <memory>

static const char* TAG_MEM = "MemSafety";

struct Student
{
    char name[32];
    int age;
    float score;
};

void print_student(Student s) {
    printf("Name: %s, Age: %d, Score: %.2f\n", s.name, s.age, s.score);
}

// Use-before-initialization
void demo_use_before_init() {
    std::cout << TAG_MEM << ": Running use-before-init demo" << std::endl;
    Student s; // Not initialized
    print_student(s); // Prints garbage
}

// Dangling pointer
void process_data(std::unique_ptr<int> data) {
    std::cout << TAG_MEM << ": Processing data: " << *data << std::endl;
}

void demo_dangling_pointer() {
    std::cout << TAG_MEM << ": Running dangling pointer demo" << std::endl;
    std::unique_ptr<int> a = std::make_unique<int>(42);
    std::cout << TAG_MEM << ": Original data: " << *a << std::endl;
    process_data(std::move(a)); // Ownership moved
    std::cout << TAG_MEM << ": After processing: " << *a << std::endl; //UB
}

// Raw pointer
void demo_raw_pointer() {
    std::cout << TAG_MEM << ": Running raw pointer demo" << std::endl;
    const int* ptr = nullptr;
    int value = *ptr; // UB: dereferencing null
    std::cout << TAG_MEM << ": Value: " << value << std::endl;
}


int main() {
  demo_use_before_init();
    return 0;
}
