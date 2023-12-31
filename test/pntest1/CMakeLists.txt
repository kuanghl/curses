cmake_minimum_required(VERSION 3.1)

include_directories(01-basic)

# 暴露lib和头文件
if(UNIX)
    include_directories(${CURSES_INCLUDE_DIRS})
    link_directories(${CURSES_LIBRARIES})
elseif(WIN32)
    include_directories(${CURSES_INCLUDE_DIRS})
    link_directories(${CURSES_LIBRARIES})
endif()

# executable
add_executable (pdce0 01-basic/pdce0.c)
add_executable (pdce1 01-basic/pdce1.c)
add_executable (pdce2 01-basic/pdce2.c)
add_executable (pdce3 01-basic/pdce3.c)
add_executable (pdce4 01-basic/pdce4.c)
add_executable (pdce5 01-basic/pdce5.c)
add_executable (pdce6 01-basic/pdce6.c)
add_executable (pdce7 01-basic/pdce7.c)
add_executable (pdce8 01-basic/pdce8.c)
add_executable (pdce9 01-basic/pdce9.c)
add_executable (pdce10 01-basic/pdce10.c)
add_executable (pdce11 01-basic/pdce11.c)
add_executable (pdce12 01-basic/pdce12.cpp)
add_executable (pdce13 01-basic/pdce13.cpp)
add_executable (pdce14 01-basic/pdce14.c)
add_executable (pdce15 01-basic/pdce15.c)
add_executable (pdce16 01-basic/pdce16.c)

# link
if(UNIX)
    target_link_libraries(pdce0 ${CURSES_LIBRARIES})
    target_link_libraries(pdce1 ${CURSES_LIBRARIES})
    target_link_libraries(pdce2 ${CURSES_LIBRARIES})
    target_link_libraries(pdce3 ${CURSES_LIBRARIES})
    target_link_libraries(pdce4 ${CURSES_LIBRARIES})
    target_link_libraries(pdce5 ${CURSES_LIBRARIES})
    target_link_libraries(pdce6 ${CURSES_LIBRARIES})
    target_link_libraries(pdce7 ${CURSES_LIBRARIES})
    target_link_libraries(pdce8 ${CURSES_LIBRARIES})
    target_link_libraries(pdce9 ${CURSES_LIBRARIES})
    target_link_libraries(pdce10 ${CURSES_LIBRARIES})
    target_link_libraries(pdce11 ${CURSES_LIBRARIES})
    target_link_libraries(pdce12 ${CURSES_LIBRARIES})
    target_link_libraries(pdce13 ${CURSES_LIBRARIES})
    target_link_libraries(pdce14 ${CURSES_LIBRARIES})
    target_link_libraries(pdce15 ${CURSES_LIBRARIES})
    target_link_libraries(pdce16 ${CURSES_LIBRARIES})
elseif(WIN32)
    target_link_libraries(pdce0 ${CURSES_LIBRARIES})
    target_link_libraries(pdce1 ${CURSES_LIBRARIES})
    target_link_libraries(pdce2 ${CURSES_LIBRARIES})
    target_link_libraries(pdce3 ${CURSES_LIBRARIES})
    target_link_libraries(pdce4 ${CURSES_LIBRARIES})
    target_link_libraries(pdce5 ${CURSES_LIBRARIES})
    target_link_libraries(pdce6 ${CURSES_LIBRARIES})
    target_link_libraries(pdce7 ${CURSES_LIBRARIES})
    target_link_libraries(pdce8 ${CURSES_LIBRARIES})
    target_link_libraries(pdce9 ${CURSES_LIBRARIES})
    target_link_libraries(pdce10 ${CURSES_LIBRARIES})
    target_link_libraries(pdce11 ${CURSES_LIBRARIES})
    target_link_libraries(pdce12 ${CURSES_LIBRARIES})
    target_link_libraries(pdce13 ${CURSES_LIBRARIES})
    target_link_libraries(pdce14 ${CURSES_LIBRARIES})
    target_link_libraries(pdce15 ${CURSES_LIBRARIES})
    target_link_libraries(pdce16 ${CURSES_LIBRARIES})
endif()

set(CMAKE_BUILD_TYPE Debug)
