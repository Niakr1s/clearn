project(e_5_4)

add_library(e_5_4 e_5_4.c)

add_executable(e_5_4_test e_5_4_test.c)
target_link_libraries(e_5_4_test e_5_4)
target_link_libraries(e_5_4_test e_3_4)

add_test(NAME e_5_4_test COMMAND e_5_4_test)
enable_testing()