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

add_executable(Day5_1 day5/day5_1.cpp)
add_executable(Day5_2 day5/day5_2.cpp)
file(COPY day5/input1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/day5)

add_executable(Day6_1 day6/day6_1.cpp)
add_executable(Day6_2 day6/day6_2.cpp)
file(COPY day6/input1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/day6)