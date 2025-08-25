cmake_minimum_required(VERSION 3.10)
project(cpp_app)

set(CMAKE_CXX_STANDARD 17)

# Path to Rust library
set(RUST_LIB ${CMAKE_SOURCE_DIR}/con_lib/rust_concurrency_lib.lib)


add_executable(cpp_app main.cpp)

# Link Rust static lib + required Windows system libraries
target_link_libraries(cpp_app PRIVATE 
    ${RUST_LIB} 
    ws2_32       # Winsock networking
    userenv      # GetUserProfileDirectory
    bcrypt       # cryptography
    rpcrt4       # UUID/RPC
    kernel32     # core functions
    advapi32     # registry/security
    ntdll        # low-level NT system calls (NtReadFile, NtWriteFile, etc.)
)