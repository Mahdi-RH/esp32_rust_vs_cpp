#  Concurrency & Memory Safety: C++ vs Rust

This repository contains two directoris that demonstrate concurrency and memory safety concepts:
- **`cpp_version/`** — C++ prototypes with race conditions, deadlocks, and unsafe memory examples.
- **`rust_version/`** —  Rust prototypes showing safe concurrency and memory safety guarantees.

---
Setup Instructions
To run these examples on your ESP32 hardware:

For the C++ Version (cpp_version/)
Follow the official ESP-IDF setup guide:
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/

For the Rust Version (rust_version/)
Follow the ESP-RS framework setup guide:
https://docs.espressif.com/projects/rust/book/introduction.html

Comparison Focus
Memory Safety: Rust's compile-time guarantees vs C++ manual memory management

Concurrency: Safe sharing patterns in Rust vs potential race conditions in C++

Build Systems: Cargo vs ESP-IDF build system

Requirements
ESP32 development board (ESP32, ESP32-S2, ESP32-S3, etc.)

USB cable for programming 

Platform-specific tools (Rust toolchain or ESP-IDF setup)
