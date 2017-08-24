cmake_minimum_required(VERSION 3.9)

# SET 指令的语法是:
# SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
# 用到的是SET(SRC_LIST main.c)
# 如果有多个源文件，也可以定义成: SET(SRC_LIST main.c t1.ct2.c)。
# SET(SRC_LIST main.c)也可以写成SET(SRC_LIST “main.c”)
# 是没有区别的，但是假设一个源文件的文件名是fu nc.c(文件名中间包含了空格)。
# 这时候就必须使用双引号，如果写成了SET(SRC_LIST fu nc.c)，就会出现错误，提示 你找不到 fu 文件和 nc.c 文件。这种情况，就必须写成:
# SET(SRC_LIST “fu nc.c”)
SET(SRC_LIST main.c)

# 定义了这个工程会生成一个文件名为 hello 的可执行文件，相关的源文件是 SRC_LIST 中
# 定义的源文件列表， 本例中你也可以直接写成ADD_EXECUTABLE(hello main.c)定义了这
# 个工程会生成一个文件名为 hello 的可执行文件，相关的源文件是 SRC_LIST 中
# 定义的源文件列表， 本例中你也可以直接写成ADD_EXECUTABLE(hello main.c)
# ${}来引用变量 有一些例外，比 如在 IF 控制语句，变量是直接使用变量名引用，而不需要${}
# 这里需要特别解释的是作为工程名的 HELLO 和生成的可执行文件 hello 是没有任何关系的
ADD_EXECUTABLE(hello ${SRC_LIST})