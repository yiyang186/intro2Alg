cmake_minimum_required(VERSION 3.1)

project(Intro2Alg LANGUAGES C CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(BREW_INCLUDE_DIRS /Users/pyy/brew/include)
set(BREW_LIBRARIES /Users/pyy/brew/lib)

message(${BREW_INCLUDE_DIRS})

file(GLOB SRCS ${CMAKE_CURRENT_LIST_DIR}/src/**.cpp)
file(GLOB HEADERS $CMAKE_CURRENT_LIST_DIR/include/*.hpp)
message(${SRCS})

add_library(alg SHARED ${SRCS})
set_target_properties(alg PROPERTIES PUBLIC_HEADER "${HEADERS}")

target_include_directories(alg PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    # ${BREW_INCLUDE_DIRS}
)
target_link_libraries(alg PUBLIC 
    ${BREW_LIBRARIES}/libglog.dylib
)

enable_testing()
find_package(GTest REQUIRED)
message(${GTEST_LIBRARIES})
add_executable(run_tests "${CMAKE_CURRENT_LIST_DIR}/test/main.cpp")
include(${CMAKE_SOURCE_DIR}/test/CMakeLists.txt)
target_link_libraries(run_tests PUBLIC 
    alg
    ${GTEST_LIBRARIES}
)
target_include_directories(run_tests PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    ${BREW_INCLUDE_DIRS}
)
add_test(test run_tests)
