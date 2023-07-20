cmake_minimum_required(VERSION 3.8)

project(threading LANGUAGES C)

add_library(threading STATIC)

target_sources(threading PRIVATE
    src/threading.c
)

target_include_directories(threading PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(threading
)
