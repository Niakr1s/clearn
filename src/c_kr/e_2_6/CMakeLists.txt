project(e_2_6)

add_library(e_2_6 e_2_6.c)

add_executable(e_2_6_test e_2_6_test.c)
target_link_libraries(e_2_6_test e_2_6)

add_test(NAME e_2_6_test COMMAND e_2_6_test)
enable_testing()