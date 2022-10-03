/**
 * @file pid_controller.hpp
 * @author Kumara Ritvik Oruganti (okritvik@umd.edu)
 * @brief This is developed as a task for Test Driven Development
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/**
 * @brief This class constitutes of required attributes and functionalities
 to compute the target velocity for a given initial velocity using PID control.
 * 
 */
class PID_Controller {
    public:
        
        /**
        * @brief Construct a new pid controller object with default
        Kp, Kd, Ki and time step.
        * 
        */
        PID_Controller();
        
        /**
         * @brief Construct a new pid controller object with user given
         * gains and time steps
         * @param kp Proportional gain
         * @param ki Integral gain
         * @param kd Derivative gain
         * @param time_step time interval
         */
        PID_Controller(double kp, double ki, double kd, double time_step);

        /**
         * @brief Set the required velocity
         * 
         * @param required_velocity target velocity
         * @return true if the target velocity is set
         * @return false if the target velocity is not set
         */
        bool set_required_velocity(double required_velocity);

        /**
         * @brief Reach the target velocity from the initial/present
         * velocity using PID controller implementation
         * @param present_vel Initial Velocity
         * @param req_vel Target velocity
         * @return double Final velocity computed after iterating
         * PID control algorithm.
         */
        double compute_pid(double present_vel, double req_vel);

    private:
        double kp; // Proportional Gain
        double ki; // Integral Gain
        double kd; // Derivative Gain
        double required_vel; // Target velocity
        double initial_vel; // Initial Velocity
        double time_step; // Time interval to compute PID
};
