project(e_5_3)

add_library(e_5_3 e_5_3.c)

add_executable(e_5_3_test e_5_3_test.c)
target_link_libraries(e_5_3_test e_5_3)
target_link_libraries(e_5_3_test e_3_4)

add_test(NAME e_5_3_test COMMAND e_5_3_test)
enable_testing()