cmake_minimum_required(VERSION 2.8)

project(PointerChain)

aux_source_directory(src SRC_DIRS)

add_executable(pointerchain.out ${SRC_DIRS})
