cmake_minimum_required(VERSION 3.10)
project(Charges)

set(CMAKE_CXX_STANDARD 17)

add_executable(Charges src/main.cpp src/charge.cpp src/charge.h src/simulator.cpp src/simulator.h src/utils.cpp src/utils.h tests/tests.cpp tests/tests.h)
