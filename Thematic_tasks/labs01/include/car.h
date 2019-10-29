#include "../include/vehicle.h"


class Car : public Vehicle {
public:
    Car(std::string name, int doors, int engine_power, int max_torque) :
        Vehicle(name, doors, engine_power, max_torque) {}
    void print();
    Car &compare(Car &car);
    std::string getName();
};