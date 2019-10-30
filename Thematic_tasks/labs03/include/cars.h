#ifndef CARS_CLASS
#define CARS_CLASS

#include <iostream>
#include <cstdlib>

#define NUMOFCARS 4
enum CARS{SEDAN_NUM = 0, HATCHBACK_NUM, SUV_NUM, TRUCK_NUM, TESLA_NUM};

class Car{
public:
    virtual void honk(){};
};

class Sedan:public Car{
public:
    virtual void honk(){std::cout<<"*Sedan honking noises*";};

    void sedanAction(){std::cout<<"Sedan is performing an action...\n";};
};

class Hatchback:public Car{
public:
    virtual void honk(){std::cout<<"*Hatchback honking noises*";};

    void hatchbackAction(){std::cout<<"Hatchback is performing an action...\n";};
};

class SUV:public Car{
public:
    virtual void honk(){std::cout<<"*SUV honking noises*";};

    void suvAction(){std::cout<<"SUV is performing an action...\n";};
};

class Truck:public SUV{
public:
    virtual void honk(){std::cout<<"*Truck honking noises*";};

    void truckAction(){std::cout<<"Truck is performing an action...\n";};
};

class Tesla : public Car {
    public:
        virtual void honk() { std::cout << "*Tesla honking noises*"; }

        void teslaAction() { std::cout << "Tesla is performing an action...\n"; }
};


Car** randomArrayOfCars(int numOfCars){
    Car **arr = new Car*[numOfCars];
    srand((unsigned)time(0));

    for(int i = 0; i < numOfCars; i++){
        int randType = rand() % 5;
        switch (randType){
        case SEDAN_NUM:
            arr[i] = new Sedan;
            break;
        case HATCHBACK_NUM:
            arr[i] = new Hatchback;
            break;
        case SUV_NUM:
            arr[i] = new SUV;
            break;
        case TRUCK_NUM:
            arr[i] = new Truck;
            break;
        case TESLA_NUM:
            arr[i] = new Tesla;
            break;
        }
    }
    return arr;
}



#endif