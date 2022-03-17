cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine-src)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(db)
add_subdirectory(driver)
add_subdirectory(lock)
add_subdirectory(receiver)
add_subdirectory(thread_wrapper)
add_subdirectory(transmitter)
include_directories(
  db
  driver
  lock
  receiver
  thread_wrapper
  transmitter
)

add_library(multithreaded-engine-src
  src_main.cpp
)

target_compile_options(multithreaded-engine-src PRIVATE
)

target_link_libraries(multithreaded-engine-src
  multithreaded-engine-src-db
  multithreaded-engine-src-driver
  multithreaded-engine-src-lock
  multithreaded-engine-src-receiver
  multithreaded-engine-src-thread_wrapper
  multithreaded-engine-src-transmitter
)
