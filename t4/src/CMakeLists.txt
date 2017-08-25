cmake_minimum_required(VERSION 3.9)

ADD_EXECUTABLE(main main.c)

FIND_PATH(myHeader hello.h)
IF(myHeader)
INCLUDE_DIRECTORIES(${myHeader})
ENDIF(myHeader)

TARGET_LINK_LIBRARIES(main libhello.a)