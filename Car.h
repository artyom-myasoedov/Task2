//
// Created by volot on 14.03.2022.
//

#ifndef TASK2_CAR_H
#define TASK2_CAR_H


#include <string>
#include "Consumer.h"

class Car {
private:
    std::string name;
    unsigned int capacity;
    unsigned int currentProductAmount;
    std::string currProductName;
public:
    Car(std::string name, unsigned int capacity);

    std::string getName();

    unsigned int getCapacity() const;

    unsigned int getCurrAmount();

    void cleanProduct();

    void addProducts(unsigned int amount);

    std::string getCurrProductName();

    virtual void setCurrProductName(std::string productName);

    void deliver(Consumer &consumer, const std::string &producer);
};


#endif //TASK2_CAR_H
