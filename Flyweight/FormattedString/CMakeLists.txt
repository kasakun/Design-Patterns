cmake_minimum_required(VERSION 2.8) 

project(FormattedText)

aux_source_directory(src SRC_DIR)

add_executable(formattedtext.out ${SRC_DIR})