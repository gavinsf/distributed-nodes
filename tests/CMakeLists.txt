add_executable(Tests
    TestHashRing.cpp
    TestNode.cpp
)
target_link_libraries(Tests
  PRIVATE
    core
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)