cmake_minimum_required(VERSION 3.24)
project(DeliveryLesson LANGUAGES CXX)
include(CTest)
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0)
FetchContent_MakeAvailable(googletest)
add_executable(lesson_test test.cpp)
target_compile_features(lesson_test PRIVATE cxx_std_23)
target_link_libraries(lesson_test PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(lesson_test DISCOVERY_MODE PRE_TEST)