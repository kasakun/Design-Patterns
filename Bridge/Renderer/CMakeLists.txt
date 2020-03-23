cmake_minimum_required(VERSION 2.8)

project(Renderer)

aux_source_directory(src SRC_DIRS)

add_executable(renderer.out ${SRC_DIRS})