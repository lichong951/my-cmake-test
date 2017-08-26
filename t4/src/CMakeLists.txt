cmake_minimum_required(VERSION 3.9)

ADD_EXECUTABLE(main main.c)

FIND_PATH(myHeader hello.h)
IF(myHeader)
INCLUDE_DIRECTORIES(${myHeader})
ENDIF(myHeader)

SET(CMAKE_LIBRARY_PATH "/cmake/usr/lib ")

IF(WIN32)
MESSAGE(STATUS "This is windows.") #作一些 Windows 相关的操作
ELSEIF(APPLE)
MESSAGE(STATUS "This is APPLE.")
ELSE(WIN32)
MESSAGE(STATUS "This is not windows") #作一些非 Windows 相关的操作
ENDIF(WIN32)


FIND_LIBRARY(hello ${CMAKE_LIBRARY_PATH})
IF(NOT hello)
MESSAGE(FATAL_ERROR "${CMAKE_LIBRARY_PATH} hello not found")
ENDIF(NOT hello)

TARGET_LINK_LIBRARIES(main libhello.a)