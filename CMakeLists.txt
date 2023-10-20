# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_FLAGS_RELEASE "-DNDEBUG -fPIC -Wall -Wextra -pedantic -O3 -std=c99 -v")
set(CMAKE_C_FLAGS_DEBUG "-g -fPIC -Wall -Wextra -pedantic -O0 -v")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

project(curses_pdc)

# env name
message(STATUS "Generator: ${CMAKE_GENERATOR}")

# diffrence curses lib for multi-envs
if(UNIX)
    add_subdirectory(ncurses)
elseif(WIN32)
    add_subdirectory(pdcurses)
else()
    message(STATUS "Error: Not Support env.")
endif()

# 编译构建子目录
add_subdirectory(test)