cmake_minimum_required(VERSION 3.18)
project(multithreaded-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  ../multithreaded-engine/src
  ../multithreaded-engine/src/db
  ../multithreaded-engine/src/driver
  ../multithreaded-engine/src/receiver
  ../multithreaded-engine/src/thread_wrapper
  ../multithreaded-engine/src/transmitter
  ../multithreaded-engine/src/util
)

set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BUILD_DIR}/lib")

# ***** Fetch googletest
include(FetchContent)
FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# ***** end of Fetch googletest

add_executable(multithreaded-test 
  main.cpp 
  test/db/db_test.cpp
  test/driver/driver_test.cpp
  test/receiver/receiver_test.cpp
  test/thread_wrapper/thread_wrapper_test.cpp
  test/transmitter/transmitter_test.cpp
  test/util/util_test.cpp
)

target_link_libraries(multithreaded-test 
  gtest_main
)
