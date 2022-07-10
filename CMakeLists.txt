cmake_minimum_required(VERSION 3.22)
project(Lambdas)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Lambdas_debug main.cpp)

set(SOURCE_FILES_TESTS
        test/test_widget.cpp)

add_executable(Lambdas_test ${SOURCE_FILES_TESTS} test/main_gtest.cpp)

target_include_directories(Lambdas_test PUBLIC
        googletest-master/googlemock/include
        googletest-master/googletest/include
        mocks
        )

add_subdirectory(googletest-master)

target_link_libraries(Lambdas_test gmock)