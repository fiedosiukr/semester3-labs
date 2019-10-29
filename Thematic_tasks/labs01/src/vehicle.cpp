#include "../include/vehicle.h"

Vehicle::Vehicle(std::string name, int doors, int engine_power, int max_torque) {
    this->name = name;
    this->doors = doors;
    this->engine_power = engine_power;
    this->max_torque = max_torque;
}