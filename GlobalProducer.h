//
// Created by volot on 13.03.2022.
//

#ifndef TASK2_GLOBALPRODUCER_H
#define TASK2_GLOBALPRODUCER_H
#include "Producer.h"
#include "Car.h"


class GlobalProducer {
public:
    static void sendProducts(Producer& producer, const std::string& productName, unsigned int amount);
    static void init();
    static void end();
private:
    static std::list<Car*> cars;
};


#endif //TASK2_GLOBALPRODUCER_H
