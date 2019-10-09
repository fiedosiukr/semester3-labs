#include <iostream>

#include "../include/car.h"

int main() {

    Car *cars[5];
    cars[0] = new Car("Fiat 500 series IV", 3, 105, 149);
    cars[1] = new Car("Renault Clio V", 5, 130, 240);
    cars[2] = new Car("Volkswagen Golf VII", 3, 184, 380);
    cars[3] = new Car("Volkswagen Passat B5", 5, 102, 148);
    cars[4] = new Car("Mercedes E-Class", 5, 136, 190);
    
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            std::cout << cars[i]->getName() << " vs " << cars[j]->getName() << std::endl;
            std::cout << "The winner is: " << cars[i]->compare(*cars[j]).getName() << std::endl << std::endl;
        }
    }


    for (int i = 0; i < 5; i++)
        delete cars[i];

    return 0;
}