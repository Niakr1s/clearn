project(e_3_2)

add_library(e_3_2 e_3_2.c)

add_executable(e_3_2_test e_3_2_test.c)
target_link_libraries(e_3_2_test e_3_2)

add_test(NAME e_3_2_test COMMAND e_3_2_test)
enable_testing()