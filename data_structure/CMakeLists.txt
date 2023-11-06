# CMakeList.txt: data_structure 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 将源代码添加到此项目的可执行文件。
add_executable (data_structure "data_structure.cpp" "data_structure.h" "link_list/link_list.cpp" "link_list/link_list.h" "stack/stack.cpp" "stack/stack.h" "queue/loop_queue/loop_queue.h" "queue/loop_queue/loop_queue.cpp" "tree/binary_tree/binary_tree.h" "tree/binary_tree/binary_tree.cpp")

# TODO: 如有需要，请添加测试并安装目标。
