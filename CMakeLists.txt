cmake_minimum_required(VERSION 3.17)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(Day1_1 day1/day1_1.cpp)
add_executable(Day1_2 day1/day1_2.cpp)
file(COPY day1/input1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/day1)

add_executable(Day2_1 day2/day2_1.cpp)
add_executable(Day2_2 day2/day2_2.cpp)
file(COPY day2/input1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/day2)

add_executable(Day3_1 day3/day3_1.cpp)
add_executable(Day3_2 day3/day3_2.cpp)
file(COPY day3/input1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/day3)

add_executable(Day4_1 day4/day4_1.cpp)
add_executable(Day4_2 day4/day4_2.cpp)
file(COPY day4/input1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/day4)