cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine-src-receiver)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  ../thread_wrapper
)

add_library(multithreaded-engine-src-receiver
  receiver.cpp
)

target_compile_options(multithreaded-engine-src-receiver PRIVATE
)

