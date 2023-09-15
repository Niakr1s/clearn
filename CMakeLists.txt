cmake_minimum_required(VERSION 3.12)
project(clearn)

# Set the C++ standard
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(src/scratchpad)

add_subdirectory(src/c_kr/e_2_4)
add_subdirectory(src/c_kr/e_2_5)
add_subdirectory(src/c_kr/e_2_6)
add_subdirectory(src/c_kr/e_2_7)
add_subdirectory(src/c_kr/e_2_8)
add_subdirectory(src/c_kr/e_2_9)
add_subdirectory(src/c_kr/e_3_2)
add_subdirectory(src/c_kr/e_3_3)
add_subdirectory(src/c_kr/e_3_4)
add_subdirectory(src/c_kr/e_3_6)
add_subdirectory(src/c_kr/e_5_3)
add_subdirectory(src/c_kr/e_5_4)

add_subdirectory(src/c_kr/dcl)