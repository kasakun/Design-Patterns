cmake_minimum_required(VERSION 2.8)

project(expression)

aux_source_directory(src SRC_DIR)

add_executable(expression.out ${SRC_DIR})
