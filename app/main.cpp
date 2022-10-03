/**
 * @file main.cpp
 * @author Kumara Ritvik Oruganti (okritvik@umd.edu)
 * @brief This is the main file that asks for the user inputs
 * and commputes the required velocity 
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <memory>
#include "../include/pid_controller.hpp"

int main() {
    double initial_vel;
    double dt;
    double req_vel;
    double kp;
    double kd;
    double ki;
    
    std::cout << "Welcome to PID Controller Application\n";
    std::cout << "Do you want to configure the gains [y/n]? : ";
    std::string user_in;
    std::cin >> user_in;
    std::unique_ptr<PID_Controller> pid;
    if(user_in == "y" || user_in == "Y") {
        std::cout << "Enter the initial velocity: ";
        std::cin >> initial_vel;
        std::cout << "\n Enter the time step: ";
        std::cin >> dt;
        std::cout << "\n Enter the Target Velocity: ";
        std::cin >> req_vel;

        std::cout << "\n Enter the Proportional Gain Kp: ";
        std::cin >> kp;
        std::cout << "\n Enter the Derivative Gain Kd: ";
        std::cin >> kd;
        std::cout << "\n Enter the Integral Gain Ki: ";
        std::cin >> ki;
        pid = std::make_unique<PID_Controller>(kp, kd, ki, dt);
        
    } else {
        std::cout << "Enter the initial velocity: ";
        std::cin >> initial_vel;
        std::cout << "\n Enter the Target Velocity: ";
        std::cin >> req_vel;
        pid = std::make_unique<PID_Controller>();
    }
    
    bool flag = pid -> set_required_velocity(req_vel);
    if(flag) {
        double final_vel = pid -> compute_pid(initial_vel, req_vel);
        std::cout << "The final Velocity Reached is : " << final_vel << "\n";
    }
    return 0;
}
