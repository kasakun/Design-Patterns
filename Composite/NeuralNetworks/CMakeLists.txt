cmake_minimum_required(VERSION 2.8)

project(NeuralNetwoks)

aux_source_directory(src SRC_DIRS)

add_executable(neuralnetworks.out ${SRC_DIRS})
