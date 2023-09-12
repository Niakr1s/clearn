project(e_2_7)

add_library(e_2_7 e_2_7.c)

add_executable(e_2_7_test e_2_7_test.c)
target_link_libraries(e_2_7_test e_2_7)

add_test(NAME e_2_7_test COMMAND e_2_7_test)
enable_testing()