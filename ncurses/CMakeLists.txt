# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 3.1)

# unix/linux lib
include(FindCurses)

if(CURSES_FOUND)
    set(CURSES_INCLUDE_DIRS "${CURSES_INCLUDE_DIRS}" CACHE INTERNAL "The include directories needed to use Curses.")
    set(CURSES_LIBRARIES "${CURSES_LIBRARIES}" CACHE INTERNAL "The libraries needed to use Curses.")
    set(CURSES_CFLAGS "${CURSES_CFLAGS}" CACHE INTERNAL "Parameters which ought be given to C/C++ compilers when using Curses.")
    set(CURSES_HAVE_CURSES_H "${CURSES_HAVE_CURSES_H}" CACHE INTERNAL "True if curses.h is available.")
else()
    message(STATUS "Error: Curses Not Founded.")
endif()