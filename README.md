# ESP32 Concurrency & Memory Safety: C++ vs Rust

This repository contains two ESP32 projects that demonstrate concurrency and memory safety concepts:
- **`cpp_version/`** — ESP-IDF C++ project with race conditions, deadlocks, and unsafe memory examples.
- **`rust_version/`** — ESP-IDF Rust project showing safe concurrency and memory safety guarantees.

---

## 1. Prerequisites

- **ESP-IDF** (for C++ project): [Install ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)
- **Rust toolchain** (for Rust project): [Install Rust](https://www.rust-lang.org/tools/install)
- **esp-idf tools for Rust**:  
  ```bash
  cargo install espup
  espup install
> USB cable & supported ESP32 development board.

> esp32_rust_vs_cpp/
│
├── cpp_version/
│   ├── concurrency/
│   ├── memory_safety/
│   ├── main/
│   ├── CMakeLists.txt
│   └── README.md
│
├── rust_version/
│   ├── src/
│   ├── Cargo.toml
│   └── README.md
│
└── README.md
