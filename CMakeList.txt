cmake_minimum_required(VERSION 3.10)
project(BashHistoryMerger VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(BashHistoryMerger main.cpp)

install(TARGETS BashHistoryMerger DESTINATION bin)