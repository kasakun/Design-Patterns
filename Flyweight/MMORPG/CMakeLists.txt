cmake_minimum_required(VERSION 2.8)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

aux_source_directory(src SRC_DIR)

add_executable(mmorgp.out ${SRC_DIR})

target_link_libraries(mmorgp.out ${Boost_INCLUDE_DIRS})