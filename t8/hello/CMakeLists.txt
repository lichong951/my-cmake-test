cmake_minimum_required(VERSION 3.9)
aux_source_directory(. DIR_HELLO_SRCS)

add_library(hello_lib ${DIR_HELLO_SRCS})

