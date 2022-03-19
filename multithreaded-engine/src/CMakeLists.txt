cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine-src)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(db)
add_subdirectory(driver)
add_subdirectory(receiver)
add_subdirectory(thread_wrapper)
add_subdirectory(transmitter)
add_subdirectory(util)
include_directories(
  db
  driver
  receiver
  thread_wrapper
  transmitter
  util
)

add_library(multithreaded-engine-src
  src_main.cpp
)

target_compile_options(multithreaded-engine-src PRIVATE
)

target_link_libraries(multithreaded-engine-src
  multithreaded-engine-src-db
  multithreaded-engine-src-driver
  multithreaded-engine-src-receiver
  multithreaded-engine-src-thread_wrapper
  multithreaded-engine-src-transmitter
  multithreaded-engine-src-util
)
