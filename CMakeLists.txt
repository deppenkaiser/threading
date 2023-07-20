cmake_minimum_required(VERSION 3.8)

project(threading LANGUAGES C)

add_library(threading STATIC)

if (MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWINDOWS")
else (MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DLINUX")
endif (MSVC)

target_sources(threading PRIVATE
    src/threading.c
    src/socket.c
    src/string.c
)

target_include_directories(threading PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(threading
)
