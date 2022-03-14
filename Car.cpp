//
// Created by volot on 14.03.2022.
//

#include "Car.h"
#include "Exception.h"

#include <utility>

Car::Car(std::string name, unsigned int capacity) {
    this->name = std::move(name);
    this->capacity = capacity;
    currentProductAmount = 0;
    currProductName = "";
}

std::string Car::getName() {
    return name;
}

unsigned int Car::getCapacity() const {
    return capacity;
}

unsigned int Car::getCurrAmount() {
    return currentProductAmount;
}

void Car::cleanProduct() {
    currentProductAmount = 0;
}

void Car::addProducts(unsigned int amount) {
    if (currentProductAmount + amount > capacity) {
        throw Exception("There is not enough capacity for " + std::to_string(amount) + " more " + currProductName);
    }
    currentProductAmount += amount;
}

std::string Car::getCurrProductName() {
    return currProductName;
}

void Car::setCurrProductName(std::string productName) {
    currProductName = std::move(productName);
}

void Car::deliver(Consumer &consumer, const std::string &producer) {
    consumer.addProducts(currProductName, currentProductAmount, producer);
}
