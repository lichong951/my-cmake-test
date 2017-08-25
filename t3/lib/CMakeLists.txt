cmake_minimum_required(VERSION 3.6)
SET(LIBHELLO_SRC hello.c)

#你不需要写全 libhello.so，只需要填写 hello 即可，cmake 系统会自动为你生成 libhello.X
#SHARED，动态库
#STATIC，静态库
#MODULE，在使用 dyld 的系统有效，如果不支持 dyld，则被当作 SHARED 对待
#EXCLUDE_FROM_ALL 参数的意思是这个库不会被默认构建，除非有其他的组件依赖或者手 工构建。
ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})

#STATIC，静态库 静态库名字跟动态库名字应该是一致的，只不过后缀是.a 罢了
ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC})

#这条指令可以用来设置输出的名称，对于动态库，还可以用来指定动态库版本和 API 版本
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")


GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
MESSAGE(STATUS “This is the hello_static OUTPUT_NAME:”${OUTPUT_VALUE})

#libhello.a 已经构建完成，位于 build/lib 目录中，但是 libhello.so 去消失了。
#这个问题的原因是:cmake 在构建一
#个新的 target 时，会尝试清理掉其他使用这个名字的库，因为，在构建 libhello.a 时， 就会清理掉 libhello.so.
#为了回避这个问题，比如再次使用 SET_TARGET_PROPERTIES 定义
SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# VERSION 指代动态库版本，SOVERSION 指代 API 版本
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

#==================================六.安装共享库和头文件
INSTALL(TARGETS hello hello_static
				LIBRARY DESTINATION lib
				ARCHIVE DESTINATION lib)

INSTALL(FILES hello.h DESTINATION include/hello)


