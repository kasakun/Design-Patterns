cmake_minimum_required(VERSION 2.8)

project(Broker)

aux_source_directory(src SRC_DIR)

add_executable(broker.out ${SRC_DIR})
