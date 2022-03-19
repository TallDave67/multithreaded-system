cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine-src-util)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
)

add_library(multithreaded-engine-src-util
  timer.cpp
)

target_compile_options(multithreaded-engine-src-util PRIVATE
)
