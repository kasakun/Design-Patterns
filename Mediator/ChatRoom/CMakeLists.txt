cmake_minimum_required(VERSION 3.6)

project(ChatRoom)

aux_source_directory(src SRC_DIR)

add_executable(chatroom.out ${SRC_DIR})
