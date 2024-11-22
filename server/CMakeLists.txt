cmake_minimum_required(VERSION 3.10)

project(my_util)
#
set(SOURCE_FILES main.c)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin) 

add_executable(my_util ${SOURCE_FILES})
