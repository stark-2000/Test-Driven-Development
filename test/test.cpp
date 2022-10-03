/**
 * @file test.cpp
 * @author Kumara Ritvik Oruganti (okritvik@umd.edu)
 * @brief Test cases to check the functionality of PID controller.
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include "../include/pid_controller.hpp"

PID_Controller pid_default;
PID_Controller my_pid(3.0, 0.01, 0.01, 0.1);

TEST(Compute_PID, Default_Values) {
  EXPECT_NEAR(pid_default.compute_pid(0.0, 10.0), 10, 0.2);
  EXPECT_NEAR(pid_default.compute_pid(0.0, -10.0), -10, 0.1);
  EXPECT_NEAR(pid_default.compute_pid(5.0, -10.0), -10, 0.05);
}

TEST(Compute_PID, Client_Input) {
  EXPECT_NEAR(my_pid.compute_pid(0.0, 10.0), 10, 0.2);
  EXPECT_NEAR(my_pid.compute_pid(0.0, -10.0), -10, 0.1);
  EXPECT_NEAR(my_pid.compute_pid(5.0, -10.0), -10, 0.05);
}
