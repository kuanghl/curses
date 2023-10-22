# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 3.1)

# 编译构建子目录
if(UNIX)
    add_subdirectory(pntest0)
endif()
add_subdirectory(pntest1)  

if("${MSCURSES_BUILD}" STREQUAL "ON")
    add_subdirectory(mstest)
endif()