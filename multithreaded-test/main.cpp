#include "gtest/gtest.h"

int main(int argc, char **argv) {
  //Init the google test framework and run all tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
