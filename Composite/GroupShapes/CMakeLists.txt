cmake_minimum_required(VERSION 2.8)

project(GroupShapes)

aux_source_directory(src SRC_DIRS)

add_executable(group.out ${SRC_DIRS})
