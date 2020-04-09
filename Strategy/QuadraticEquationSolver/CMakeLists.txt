cmake_minimum_required(VERSION 2.8)

project(QuadraticEquationSolver)

aux_source_directory(src SRC_DIR)

add_executable(solver.out ${SRC_DIR})
