
cmake_minimum_required(VERSION 2.8)

project(VirtualProxy)

aux_source_directory(src SRC_DIR)

add_executable(virtualproxy.out ${SRC_DIR})