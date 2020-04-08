cmake_minimum_required(VERSION 2.8)

project(rats)

aux_source_directory(src SRC_DIR)

add_executable(rats.out ${SRC_DIR})
