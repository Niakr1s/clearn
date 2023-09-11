project(e_2_5)

add_library(e_2_5 e_2_5.c)

add_executable(e_2_5_test e_2_5_test.c)
target_link_libraries(e_2_5_test e_2_5)

add_test(NAME e_2_5_test COMMAND e_2_5_test)
enable_testing()