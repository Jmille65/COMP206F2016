cmake_minimum_required(VERSION 2.8.9)
project (hello)

add_library(swapLib SHARED week8_multi_file_swap.c)

add_executable(hello week8_multi_file_main.c)
target_link_libraries(hello swapLib)



