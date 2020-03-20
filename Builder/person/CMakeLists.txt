cmake_minimum_required (VERSION 2.8)

project (Person)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

aux_source_directory(src DIR_SRCS)

add_executable (person.out ${DIR_SRCS})
