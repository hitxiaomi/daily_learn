cmake_minimum_required(VERSION 3.14)
project(daily_learn)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(Eigen3 REQUIRED)
include_directories( ${EIGEN3_INCLUDE_DIR})

message(STATUS "EIGEN3_DIR:"  ${EIGEN3_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(daily_learn eigen_quaternion_learn.cpp)