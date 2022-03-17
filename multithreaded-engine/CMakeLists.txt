cmake_minimum_required(VERSION 3.18)
project(multithreaded-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(src)
include_directories(
  src
  src/db
  src/driver
  src/lock
  src/receiver
  src/cr_thread
  src/transmitter
)

add_executable(multithreaded-engine main.cpp)

target_link_libraries(multithreaded-engine multithreaded-engine-src)
