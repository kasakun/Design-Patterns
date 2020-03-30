cmake_minimum_required(VERSION 2.8)

project(Broker)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

aux_source_directory(src SRC_DIR)

add_executable(broker.out ${SRC_DIR})

target_link_libraries(broker.out ${Boost_INCLUDE_DIRS})
