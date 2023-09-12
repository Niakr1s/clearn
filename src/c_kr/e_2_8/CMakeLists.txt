project(e_2_8)

add_library(e_2_8 e_2_8.c)

add_executable(e_2_8_test e_2_8_test.c)
target_link_libraries(e_2_8_test e_2_8)

add_test(NAME e_2_8_test COMMAND e_2_8_test)
enable_testing()