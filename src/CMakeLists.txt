set(SOURCES
    HashRing.cpp
    Node.cpp
    TcpConnection.cpp
    TcpServer.cpp
)

add_library(core STATIC ${SOURCES})

target_link_libraries(core PUBLIC asio)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(distributed-nodes main.cpp)
target_link_libraries(distributed-nodes PRIVATE core)