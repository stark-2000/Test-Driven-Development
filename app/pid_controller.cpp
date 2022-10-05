/**
 * @file pid_controller.cpp
 * @author Kumara Ritvik Oruganti (okritvik@umd.edu)
 * @author Dhinesh Rajasekaran (dhinesh@umd.edu)
 * @brief This file is an implementation of PID_Controller
 * class.
 * @version 0.2
 * @date 2022-10-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/pid_controller.hpp"

PID_Controller::PID_Controller() {
  // Default values for gains and time_step
  PID_Controller::kp = 0.5;
  PID_Controller::kd = 0.011;
  PID_Controller::ki = 0.01;
  PID_Controller::time_step = 0.1;
  PID_Controller::initial_vel = 0.0;
}

PID_Controller::PID_Controller(double kp, double ki, double kd,
                               double time_step) {
  PID_Controller::kp = kp;
  PID_Controller::kd = kd;
  PID_Controller::ki = ki;
  PID_Controller::time_step = time_step;
}

bool PID_Controller::set_required_velocity(double required_velocity) {
  PID_Controller::required_vel = required_velocity;
  return true;
}

double PID_Controller::compute_pid(double present_vel, double req_vel) {
  double perror = 0;
  double integral = 0;
  while (true) {
    // Calculating the error:
    double error = req_vel - present_vel;

    // Calculating Kp:
    double P = kp * error;

    // Calculating Ki:
    integral = integral + error * time_step;
    double I = ki * integral;

    // Calculating Kd:
    double derivative = (error - perror) / time_step;
    double D = kd * derivative;

    // Calcuating PID adjusted velocity:
    present_vel = present_vel + P + I + D;

    // Saving the previous error:
    perror = error;

    // When the error is very low, return the adjusted velocity
    if (error < 0.000000001) {
      return present_vel;
    }
  }
}
