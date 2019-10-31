#include "cars.h"

#include <typeinfo>

#define NUMBER_OF_CARS 6

int main()
{
    Car **cars = randomArrayOfCars(NUMBER_OF_CARS);

    for (int i = 0; i < NUMBER_OF_CARS; i++) {
        Car *car = cars[i];
        cars[i]->honk();
        std::cout << " - " << typeid(car).name() << std::endl;
    }

    std::cout << "\n\n";

    for (int i = 0; i < NUMBER_OF_CARS; i++) {
        if (auto ptr = dynamic_cast<Sedan*>(cars[i])) {
            ptr->sedanAction();
            std::cout << typeid(ptr).name() << "\n";
        } else if (auto ptr = dynamic_cast<SUV*>(cars[i])) {
            ptr->suvAction();
            std::cout << typeid(ptr).name() << "\n";
        } else if (auto ptr = dynamic_cast<Truck*>(cars[i])) {
            ptr->truckAction();
            std::cout << typeid(ptr).name() << "\n";
        } else if (auto ptr = dynamic_cast<Hatchback*>(cars[i])) {
            ptr->hatchbackAction();
            std::cout << typeid(ptr).name() << "\n";
        } else if (auto ptr = dynamic_cast<Tesla*>(cars[i])) {
            ptr->teslaAction();
            std::cout << typeid(ptr).name() << "\n";
        }
    }

}