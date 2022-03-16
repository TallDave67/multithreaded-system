cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine-src-transmitter)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
)

add_library(multithreaded-engine-src-transmitter
  transmitter.cpp
)

target_compile_options(multithreaded-engine-src-transmitter PRIVATE
)

