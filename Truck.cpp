//
// Created by volot on 14.03.2022.
//

#include "Truck.h"
#include "Exception.h"

void Truck::setCurrProductName(std::string productName) {
    if (productName == "gas") {
        throw Exception("Truck can't delivar gas!");
    }
    Car::setCurrProductName(productName);
}

Truck::Truck(): Car("Truck", 50) {

}
