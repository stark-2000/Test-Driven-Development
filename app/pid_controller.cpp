/**
 * @file pid_controller.cpp
 * @author Kumara Ritvik Oruganti (okritvik@umd.edu)
 * @brief This file is an implementation of PID_Controller
 * class.
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/pid_controller.hpp"

PID_Controller::PID_Controller() {
    // Default values for gains and time_step
    PID_Controller::kp = 2.0;
    PID_Controller::kd = 0.01;
    PID_Controller::ki = 0.05;
    PID_Controller::time_step = 0.1;
    PID_Controller::initial_vel = 0.0;
}

PID_Controller::PID_Controller(double kp, double ki, double kd, double time_step) {
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
    // Implement this method
    return 1000;
}