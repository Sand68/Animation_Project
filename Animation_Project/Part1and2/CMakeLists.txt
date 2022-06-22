# CMakeList.txt : CMake project for FinalProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Part2  "part2.cpp"	"animation.cpp"		"animation.h"		"frame.cpp"		"frame.h")
add_executable (Part1  "part1.c")

# TODO: Add tests and install targets if needed.
