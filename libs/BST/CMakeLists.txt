cmake_minimum_required(VERSION 3.30)

add_library(BST STATIC
    BST.cpp
    BST.h
)
target_include_directories(BST PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)