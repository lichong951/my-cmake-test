cmake_minimum_required(VERSION 3.6.1)

#PROJECT(projectname [CXX] [C] [Java]) 定义工程名
#并可指定工程支持的语言，支持的语言列表是可以忽略
# 默认情况表示支持所有语言
# 预定义了 PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR 变量，他们的值分别跟 HELLO_BINARY_DIR 与 HELLO_SOURCE_DIR
PROJECT (HELLO)

# ADD_SUBDIRECTORY 指令
# ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
# 这个指令用于向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存 放的位置。
# EXCLUDE_FROM_ALL 参数的含义是将这个目录从编译过程中排除，比如，工程 # 的 example，
# 可能就需要工程构建完成后，再进入 example 目录单独进行构建(当然，你 也可以通过定义依赖来解决此类问题)
ADD_SUBDIRECTORY(src bin)

#######cmake -DCMAKE_INSTALL_PREFIX=/tmp/t2/usr ..
# make;make install，你会发现 CMAKE_INSTALL_PREFIX 的默认定义是/usr/local

# 安装 COPYRIGHT/README
INSTALL(FILES COPYRIGHT README DESTINATION share/doc/cmake/t2)
# 安装 runhello.sh
INSTALL(PROGRAMS runhelllo.sh DESTINATION bin)
# 因为 hello.txt 要安装到/<prefix>/share/doc/cmake/t2，所以我们不能直接安装 整个 doc 目录，这里采用的#方式是安装 doc 目录中的内容，也就是使用”doc/
INSTALL(DIRECTORY doc/ DESTINATION share/doc/cmake/t2)