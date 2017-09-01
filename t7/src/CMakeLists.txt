cmake_minimum_required(VERSION 3.9)

# 添加 hs 子目录
add_subdirectory(hs)
MESSAGE(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}/src/hs")
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/hs)

add_executable(Demo main.c)



# 添加链接库
target_link_libraries(Demo His)



