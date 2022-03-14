//
// Created by volot on 14.03.2022.
//

#include "GasolineTanker.h"
#include "Exception.h"

GasolineTanker::GasolineTanker() : Car("Gasoline tanker", 30) {

}

void GasolineTanker::setCurrProductName(std::string productName) {
    if (productName != "gas") {
        throw Exception("Gasoline tanker can deliver only gas!");
    }
    Car::setCurrProductName(productName);
}
