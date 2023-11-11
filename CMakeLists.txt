cmake_minimum_required(VERSION 3.27)
project(UCSC)

set(CMAKE_CXX_STANDARD 14)

# Include GoogleTest and enable testing
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

include_directories(week3/src)

add_executable(UCSC
        week3/src/main.cpp)
       # week3/src/main.h)
