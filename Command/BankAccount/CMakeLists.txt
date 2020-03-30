cmake_minimum_required(VERSION 2.8)

project(BankAccount)

aux_source_directory(src SRC_DIR)

add_executable(bankaccount.out ${SRC_DIR})
