cmake_minimum_required(VERSION 2.8)

project(DoubleDispatch)

aux_source_directory(src SRC_DIR)

add_executable(doubledispatch.out ${SRC_DIR})
