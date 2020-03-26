cmake_minimum_required(VERSION 2.8)

project(PropertyProxy)

aux_source_directory(src SRC_DIR)

add_executable(propertyproxy.out ${SRC_DIR})
