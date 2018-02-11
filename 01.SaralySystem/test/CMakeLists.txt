cmake_minimum_required(VERSION 2.8)
include_directories(../src)
add_executable(unittests
  test_add_salaried_employee.cpp)
target_link_libraries(unittests gtest_main)