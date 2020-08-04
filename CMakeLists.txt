cmake_minimum_required(VERSION 3.10)
project(daily_learn)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)
find_package(Glog REQUIRED)
find_package(Gflags REQUIRED)
include_directories(BEFORE ${GLOG_INCLUDE_DIRS})
include_directories( ${EIGEN3_INCLUDE_DIR}
        ${CERES_INCLUDE_DIRS})

message(STATUS "EIGEN3_DIR:"  ${EIGEN3_INCLUDE_DIR})

message(STATUS "Ceres_Dirs:"  ${CERES_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

# add_executable(daily_learn eigen_quaternion_learn.cpp)
# add_executable(test_so3_update test_quaternion_so3_update.cpp)
# add_executable(test_queue test_queue.cpp)
# add_executable(test_dfs testdfs.cpp)
# add_executable(test_least_square_nums test_least_square_nums.cpp)
# add_executable(test_ceres  robust_curve_fitting.cc)
# target_link_libraries(test_ceres   ${CERES_LIBRARIES})

# add_executable(test_leetcode test_leetcode.cpp)
# add_executable(test_target_ways test_target_ways.cpp)
# add_executable( test_qr test_qr.cpp)
# add_executable( test_vector test_vector.cpp)

add_executable(eigen_matrix eigen_matrix.cpp)
