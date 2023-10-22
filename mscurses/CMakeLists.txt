# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

set(MSCURSESE_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(MSCURSESE_INCLUDE_DIRS "${MSCURSESE_INCLUDE_PATH}" CACHE INTERNAL "The include directories needed to use Curses.")

# diffrence curses lib for multi-envs
if(UNIX)
    set(VT_MSCURSESE_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/linuxvt/libpdcurses.so" CACHE INTERNAL "The vt libraries needed to use Curses.")
elseif(WIN32)
    set(VT_MSCURSESE_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/winlib/vt_x86/pdcursesd.lib" CACHE INTERNAL "The vt libraries needed to use Curses.")
    set(WINCON_MSCURSESE_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/winlib/wincon_x86/pdcursesd.lib" CACHE INTERNAL "The wincon libraries needed to use Curses.")
    set(WINGUI_MSCURSESE_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/winlib/wingui_x86/pdcursesd.lib" CACHE INTERNAL "The wingui libraries needed to use Curses.")
endif()