cmake_minimum_required(VERSION 2.8.3)
project(latency_tester)

set(CMAKE_CXX_FLAGS "-fPIC --std=c++11")

find_package(OpenCV REQUIRED)
find_package(Threads)

include_directories(
    include
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(latency_tester
    src/latency_tester.cpp
    src/main.cpp
    )
target_link_libraries(latency_tester
    ${OpenCV_LIBS}
    Threads::Threads
    )
