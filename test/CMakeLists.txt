# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

# 编译构建子目录
if(NOT APPLE) # Linux/Windows
    add_subdirectory(pntest0)
    add_subdirectory(pntest1)
else() # Apple: ios/macos/ipados
    add_subdirectory(pntest1)
endif()

if("${MSCURSES_BUILD}" STREQUAL "ON")
    add_subdirectory(mstest)
endif()