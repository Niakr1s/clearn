project(e_2_4)

add_library(e_2_4 e_2_4.c)

add_executable(e_2_4_test e_2_4_test.c)
target_link_libraries(e_2_4_test e_2_4)

add_test(NAME e_2_4_test COMMAND e_2_4_test)
enable_testing()