cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine-src-thread_wrapper)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  ../util
)

add_library(multithreaded-engine-src-thread_wrapper
  thread_wrapper.cpp
)

target_compile_options(multithreaded-engine-src-thread_wrapper PRIVATE
)

