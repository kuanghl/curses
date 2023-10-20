# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

# windows
set(PDCURSES_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(PDCURSES_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")

set(CURSES_INCLUDE_DIRS "${PDCURSES_INCLUDE_PATH}" CACHE INTERNAL"The include directories needed to use Curses.")
set(CURSES_LIBRARIES "${PDCURSES_LIB_PATH}/wincon_x86/pdcurses.lib" CACHE INTERNAL "The libraries needed to use Curses.")