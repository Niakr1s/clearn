cmake_minimum_required(VERSION 3.12)
project(clearn)

# Set the C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(src/scratchpad)

add_subdirectory(src/c_kr/e_2_4)
add_subdirectory(src/c_kr/e_2_5)