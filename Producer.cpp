//
// Created by volot on 11.03.2022.
//

#include "Producer.h"
#include "Exception.h"

#include <utility>
#include <iostream>

Producer::Producer(std::string newName, std::string type) : Consumer(std::move(newName), std::move(type)) {
    cars = {};
}

Producer::~Producer() {}

void Producer::sendProductBatch(Consumer &consumer, const std::string &productName, unsigned int amounnt) {
    if (containsProduct(productName) && getProductAmount(productName) > amounnt) {
        if (checkCarListCapacity(amounnt, productName)) {
            unsigned int temp;
            for (Car* car: cars) {
                std::string carName = productName == "gas" ? "Gasoline tanker" : "Truck";
                if (car->getName() == carName) {
                    temp = (car->getCapacity() >= amounnt) ? amounnt : car->getCapacity();
                    car->setCurrProductName(productName);
                    amounnt -= temp;
                    car->addProducts(temp);
                    car->deliver(consumer, type);
                    car->cleanProduct();
                    std::cout << car->getName() << " delivered " << temp << " " << productName << " to "
                              << consumer.getName() << std::endl;
                    removeProduct(productName, temp);
                }
                if (amounnt == 0) {
                    return;
                }
            }
        } else {
            throw Exception("There is not enough cars to deliver" + std::to_string(amounnt) + " " + productName +
                            " at Producer: " + this->name);
        }
    } else {
        throw Exception("There is not enough " + productName + " at Producer: " + this->name);
    }
}

void Producer::removeProduct(const std::string &productName, unsigned int amounnt) {
    getProducts()[productName] = getProductAmount(productName) - amounnt;
}

bool Producer::checkCarListCapacity(unsigned int amount, const std::string &productName) {
    unsigned int cap = 0;
    std::string carName = productName == "gas" ? "Gasoline tanker" : "Truck";
    for (Car* car: cars) {
        if (car->getName() == carName) {
            cap += car->getCapacity();
        }
    }
    return cap >= amount;
}

void Producer::addCar(Car *car) {
    cars.push_back(car);
}

void Producer::removeLastCar() {
    cars.pop_back();
}

std::list<Car *> Producer::getCars() {
    return cars;
}
