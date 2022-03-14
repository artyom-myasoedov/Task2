//
// Created by volot on 13.03.2022.
//

#include <iostream>
#include "GlobalProducer.h"
#include "Truck.h"
#include "GasolineTanker.h"

std::list<Car*> GlobalProducer::cars = {};

void GlobalProducer::sendProducts(Producer &producer, const std::string &productName, unsigned int amount) {
    for (Car *car: GlobalProducer::cars) {
        std::string carName = productName == "gas" ? "Gasoline tanker" : "Truck";
        if (car->getName() == carName) {
            unsigned int temp = (car->getCapacity() >= amount) ? amount : car->getCapacity();
            car->setCurrProductName(productName);
            amount -= temp;
            car->addProducts(temp);
            car->deliver(producer, "");
            car->cleanProduct();
            std::cout << car->getName() << " delivered " << temp << " " << productName << " to "
                      << producer.getName() << std::endl;
        }
        if (amount == 0) {
            return;
        }
    }
    producer.addProducts(productName, amount, "");
}

void GlobalProducer::init() {
    for (int i = 0; i < 100; i++) {
        GlobalProducer::cars.push_back(new Truck());
        GlobalProducer::cars.push_back(new GasolineTanker());
    }
}

void GlobalProducer::end() {
    while (!GlobalProducer::cars.empty()) {
        GlobalProducer::cars.remove(*GlobalProducer::cars.begin());
    }
}
