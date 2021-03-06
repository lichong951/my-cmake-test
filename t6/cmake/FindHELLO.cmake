MESSAGE(STATUS "FindHELLO: start")

#命令 FIND_PATH 指明头文件查找的路径，原型如下：
#find_path(<VAR> name1 [path1 path2 ...]) 该命令在参数 path* 指示的目录中查找文件
#name1 并将查找到的路径保存在变量 VAR 中。清单5第3－8行的意思是在 /usr/include/ 和
#/usr/local/include/ 中查找文件db_cxx.h ,并将db_cxx.h 所在的路径保存在
#LIBDB_CXX_INCLUDE_DIR中。
#命令 FIND_LIBRARY 同 FIND_PATH
#类似,用于查找链接库并将结果保存在变量中。清单5第10－13行的意思是在目录 /usr/lib/ 和
#/usr/local/lib/ 中寻找名称为 db_cxx 的链接库,并将结果保存在 LIBDB_CXX_LIBRARIES。
#
FIND_PATH(HELLO_INCLUDE_DIR hello.h /cmake/usr/include/hello)
FIND_LIBRARY(HELLO_LIBRARY libhello.a PATH /cmake/usr/lib)

IF(NOT HELLO_INCLUDE_DIR)
	MESSAGE(FATAL_ERROR "HELLO_INCLUDE_DIR null")
ELSE(NOT HELLO_INCLUDE_DIR)
	MESSAGE(STATUS "HELLO_INCLUDE_DIR is reading")
ENDIF(NOT HELLO_INCLUDE_DIR)

IF(NOT HELLO_LIBRARY)
	MESSAGE(FATAL_ERROR "HELLO_LIBRARY null")
ENDIF(NOT HELLO_LIBRARY)

IF (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
   SET(HELLO_FOUND TRUE)
ELSE(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
	MESSAGE(STATUS "HELLO_INCLUDE_DIR or HELLO_LIBRARY is null")
ENDIF (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)


IF (HELLO_FOUND)
   IF (NOT HELLO_FIND_QUIETLY)
      MESSAGE(STATUS "Found Hello: ${HELLO_LIBRARY}")
   ELSE(NOT HELLO_FIND_QUIETLY)
			MESSAGE(STATUS "HELLO_FIND_QUIETLY is null")
ENDIF (NOT HELLO_FIND_QUIETLY)

ELSE (HELLO_FOUND)
   IF (HELLO_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find hello library")
   ELSE(HELLO_FIND_REQUIRED)
			MESSAGE(STATUS "HELLO_FIND_REQUIRED is null")
   ENDIF (HELLO_FIND_REQUIRED)
ENDIF (HELLO_FOUND)

MESSAGE(STATUS "FindHELLO: end")


