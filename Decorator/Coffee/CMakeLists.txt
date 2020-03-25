cmake_minimum_required(VERSION 2.8) 

project(Coffee)

aux_source_directory(src SRC_DIRS)

add_executable(coffee.out ${SRC_DIRS})