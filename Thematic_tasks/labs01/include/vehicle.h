#include <string>

class Vehicle {
protected:
    Vehicle(std::string name, int doors, int engine_power, int max_torque);

protected:
    std::string name;
    int doors;
    int engine_power;
    int max_torque;
};