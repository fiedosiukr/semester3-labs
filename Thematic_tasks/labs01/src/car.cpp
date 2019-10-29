#include "../include/car.h"

#include <iostream>


void Car::print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Doors: " << doors << std::endl;
        std::cout << "Engine power: " << engine_power << std::endl;
        std::cout << "Max torque: " << max_torque << std::endl;
}

Car& Car::compare(Car &car) {
    if (engine_power > car.engine_power)
        return *this;
    
    return car;
}

std::string Car::getName() {
    return name;
}