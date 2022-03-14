//
// Created by volot on 14.03.2022.
//

#ifndef TASK2_TRUCK_H
#define TASK2_TRUCK_H


#include "Car.h"

class Truck: public Car{
public:
    Truck();
    void setCurrProductName(std::string productName) override;
};


#endif //TASK2_TRUCK_H
