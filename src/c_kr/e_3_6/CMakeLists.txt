project(e_3_6)

add_library(e_3_6 e_3_6.c)

add_executable(e_3_6_test e_3_6_test.c)
target_link_libraries(e_3_6_test e_3_6)
target_link_libraries(e_3_6_test e_3_4)

add_test(NAME e_3_6_test COMMAND e_3_6_test)
enable_testing()