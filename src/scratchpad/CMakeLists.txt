project(scratchpad)

add_executable(scratchpad scratchpad.c)
add_library(foo foo.c)
target_link_libraries(scratchpad foo)