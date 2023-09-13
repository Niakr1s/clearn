project(e_3_4)

add_library(e_3_4 e_3_4.c)

add_executable(e_3_4_test e_3_4_test.c)
target_link_libraries(e_3_4_test e_3_4)

add_test(NAME e_3_4_test COMMAND e_3_4_test)
enable_testing()