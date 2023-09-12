project(e_3_3)

add_library(e_3_3 e_3_3.c)

add_executable(e_3_3_test e_3_3_test.c)
target_link_libraries(e_3_3_test e_3_3)

add_test(NAME e_3_3_test COMMAND e_3_3_test)
enable_testing()