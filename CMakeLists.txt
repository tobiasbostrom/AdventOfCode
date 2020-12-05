cmake_minimum_required(VERSION 3.17)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(Day1_1 day1/day1_1.cpp)
add_executable(Day1_2 day1/day1_2.cpp)
file(COPY day1/input1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/day1)

add_executable(Day2_1 day2/day2_1.cpp)
add_executable(Day2_2 day2/day2_2.cpp)
file(COPY day2/input1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/day2)