cmake_minimum_required(VERSION 2.8)

project(Point)

aux_source_directory(src SRC_DIRS)

add_executable(Point.out ${SRC_DIRS})