project(dcl)

add_library(dcl dcl.c)

add_executable(dcl_test dcl_test.c)
target_link_libraries(dcl_test dcl)
target_link_libraries(dcl_test e_3_4)

add_test(NAME dcl_test COMMAND dcl_test)
enable_testing()