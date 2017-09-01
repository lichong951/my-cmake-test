cmake_minimum_required(VERSION 2.8)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

MESSAGE(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}/src/hs")
INCLUDE_DIRECTORIES(.)

# 生成链接库
add_library (His ${DIR_LIB_SRCS})

