cmake_minimum_required(VERSION 2.8)

project(Drink)

aux_source_directory(src SRC_DIRS)

add_executable(Drink.out ${SRC_DIRS})
