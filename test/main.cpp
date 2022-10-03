/**
 * @file main.cpp
 * @author Kumara Ritvik Oruganti (okritvik@umd.edu)
 * @brief GTest execution file
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
