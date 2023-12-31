cmake_minimum_required(VERSION 3.1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "./cmake")

# Bump up warning levels appropriately for clang, gcc & msvc and build in debug mode
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

include_directories(${CURSES_INCLUDE_DIRS})

set(EXAMPLE_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/examples)

function(build_singlefile_example SOURCE)
	# use current directory of project as prefix (e.g. 01-init)
	get_filename_component(target_prefix ${CMAKE_CURRENT_SOURCE_DIR} NAME)
	string(REPLACE " " "_" target_prefix ${target_prefix})

	# use source file's name w/o extension as name (e.g. main)
	get_filename_component(target_shortname ${SOURCE} NAME_WE)

	# combine into full target name (01-init-main)
	set(TARGET ${target_prefix}-${target_shortname})

	add_executable(${TARGET} ${SOURCE})
	target_link_libraries(${TARGET} ${CURSES_LIBRARIES} ${ADDITIONAL_LIBRARIES})
endfunction()

add_subdirectory(04-initialization)
add_subdirectory(06-output-functions)
add_subdirectory(07-input-functions)
add_subdirectory(08-attributes)
add_subdirectory(09-windows)
add_subdirectory(10-colors)
add_subdirectory(11-keyboard)
add_subdirectory(12-mouse)
add_subdirectory(14-misc)
add_subdirectory(16-panels)
add_subdirectory(17-menus)
add_subdirectory(18-forms)
