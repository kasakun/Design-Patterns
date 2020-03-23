cmake_minimum_required(VERSION 2.8)

project(PImpl)

include_directories(includes)

aux_source_directory(src SRC_DIRS)

add_executable(pimpl.out ${SRC_DIRS})
