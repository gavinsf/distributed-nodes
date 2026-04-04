cmake_minimum_required(VERSION 3.28.3)
project(server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCE_FILES
    main.cpp
    Coordinator.cpp
)

set(HEADER_FILES
    Coordinator.h
    Node.h
)

add_executable(server ${SOURCE_FILES} ${HEADER_FILES})