idf_component_register(SRCS "main.cpp" "demos/demo_concurrency.cpp" "demos/demo_mem_safety.cpp" "demos/student.cpp"        
                       PRIV_REQUIRES spi_flash
                       INCLUDE_DIRS "." "./rust_lib")

# Link the Rust static library
target_link_libraries(${COMPONENT_LIB} INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}./rust_lib/libconcurrency_lib.a
)                       