cmake_minimum_required(VERSION 2.8)

project(CombinationLock)

aux_source_directory(src SRC_DIR)

add_executable(lock.out ${SRC_DIR})
