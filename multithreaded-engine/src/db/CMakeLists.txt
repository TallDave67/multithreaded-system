cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine-src-db)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
)

add_library(multithreaded-engine-src-db
  db.cpp
)

target_compile_options(multithreaded-engine-src-db PRIVATE
)

