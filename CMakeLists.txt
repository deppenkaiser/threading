cmake_minimum_required(VERSION 3.10)
include_guard(GLOBAL)

project(threading LANGUAGES C)

add_compile_definitions(_POSIX_C_SOURCE=200809L)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(
	../string
	${CMAKE_BINARY_DIR}/string_from_threading
)

add_library(threading STATIC)

target_sources(threading PRIVATE
	threading.c
)

target_include_directories(threading PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(threading
	string
)
