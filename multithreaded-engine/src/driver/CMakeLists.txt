cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine-src-driver)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  ../cr_thread
)

add_library(multithreaded-engine-src-driver
  driver.cpp
)

target_compile_options(multithreaded-engine-src-driver PRIVATE
)

