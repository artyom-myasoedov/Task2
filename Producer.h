//
// Created by volot on 11.03.2022.
//

#ifndef TASK2_PRODUCER_H
#define TASK2_PRODUCER_H
#include "Consumer.h"
#include "Car.h"
#include <list>

class Producer: public Consumer{
public:
    Producer(std::string newName, std::string type);
    ~Producer();
    virtual void sendProductBatch(Consumer & consumer, const std::string& productName, unsigned int amounnt);
    void addCar(Car* car);
    void removeLastCar();
    std::list<Car*> getCars();
private:
    void removeProduct(const std::string& productName, unsigned int amounnt);
    bool checkCarListCapacity(unsigned int amount, const std::string &productName);
    std::list<Car*> cars;
};


#endif //TASK2_PRODUCER_H
