//
// Created by volot on 13.03.2022.
//

#include "RetailConsumer.h"
#include "Exception.h"

#include <utility>

RetailConsumer::RetailConsumer(std::string newName) : Consumer(std::move(newName), "retail") {

}

void RetailConsumer::addProducts(const std::string &productName, unsigned int amount, const std::string& producerType) {
    if (producerType != "shop") {
        throw Exception("Incorrect producer type");
    }
    Consumer::addProducts(productName, amount, "");
}


