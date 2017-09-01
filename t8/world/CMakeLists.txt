cmake_minimum_required(VERSION 3.9)
aux_source_directory(. DIR_WORLD_SRCS)
add_library(world_lib ${DIR_WORLD_SRCS})

