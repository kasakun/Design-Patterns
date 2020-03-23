
cmake_minimum_required(VERSION 2.8)

project(Shape)

aux_source_directory(src SRC_DIRS)

add_executable(Shape.out ${SRC_DIRS})

target_link_libraries(Shape.out ${Boost_INCLUDE_DIRS})