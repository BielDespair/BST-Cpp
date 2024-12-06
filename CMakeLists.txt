cmake_minimum_required(VERSION 3.30)
project(BSTProject)


#Defining Directory variables for acess
set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


add_subdirectory(${LIB_DIR}/BST)

add_executable(${PROJECT_NAME}
    main.cpp
)
target_link_libraries(${PROJECT_NAME}
    PUBLIC BST
)