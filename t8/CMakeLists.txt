project(hello_prj)
cmake_minimum_required(VERSION 3.9)
# Add the source in project root directory

# PROJECT_SOURCE_DIR仍然指代工程路径
MESSAGE(STATUS "PROJECT_SOURCE_DIR : ${PROJECT_SOURCE_DIR}")

# PROJECT_BINARY_DIR 指代编译路径
MESSAGE(STATUS "PROJECT_BINARY_DIR : ${PROJECT_BINARY_DIR}")
aux_source_directory(. DIRSRCS)

# Add header file include directories

include_directories(./ ./hello ./world ./hs)

# Add block directories
add_subdirectory(hello)
add_subdirectory(world)

# Target
add_executable(hello_target ${DIRSRCS})
#add_library(hello_target ${DIRSRCS})

target_link_libraries(hello_target hello_lib world_lib)

