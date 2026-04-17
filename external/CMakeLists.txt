add_library(asio INTERFACE)

target_include_directories(asio
  INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/asio-1.36.0/include
)

target_compile_definitions(asio
  INTERFACE
    ASIO_STANDALONE
    ASIO_NO_DEPRECATED
)

find_package(Threads REQUIRED)
target_link_libraries(asio
  INTERFACE
    Threads::Threads
)