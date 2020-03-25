cmake_minimum_required(VERSION 2.8)

project(SingletonDatabase)

aux_source_directory(src SRC_DIRS)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(DataBase.out ${SRC_DIRS})

target_link_libraries(DataBase.out ${Boost_INCLUDE_DIRS})