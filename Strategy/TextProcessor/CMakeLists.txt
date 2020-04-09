cmake_minimum_required(VERSION 2.8)

project(TextProcessor)

aux_source_directory(src SRC_DIR)

add_executable(textprocessor.out ${SRC_DIR})
