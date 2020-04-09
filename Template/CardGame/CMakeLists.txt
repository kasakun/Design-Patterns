cmake_minimum_required(VERSION 2.8)

project(CardGame)

aux_source_directory(src SRC_DIR)

add_executable(game.out ${SRC_DIR})
