project(e_2_9)

add_library(e_2_9 e_2_9.c)

add_executable(e_2_9_test e_2_9_test.c)
target_link_libraries(e_2_9_test e_2_9)

add_test(NAME e_2_9_test COMMAND e_2_9_test)
enable_testing()