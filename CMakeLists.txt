cmake_minimum_required(VERSION 3.28.3)
project(distributed-nodes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(asio_local INTERFACE)

target_include_directories(asio_local INTERFACE 
    "${CMAKE_CURRENT_SOURCE_DIR}/external/asio-1.36.0/include"
)

target_compile_definitions(asio_local INTERFACE ASIO_STANDALONE)

set(SOURCE_FILES
    main.cpp
    Node.cpp
    TcpConnection.cpp
    TcpServer.cpp
)

set(HEADER_FILES
    Node.h
    TcpConnection.h
    TcpServer.h
)

add_executable(distributed-nodes ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(distributed-nodes PRIVATE asio_local)

find_package(Threads REQUIRED)
target_link_libraries(distributed-nodes PRIVATE Threads::Threads)