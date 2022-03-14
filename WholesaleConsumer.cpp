//
// Created by volot on 13.03.2022.
//

#include "WholesaleConsumer.h"

#include <utility>
#include "Exception.h"

void WholesaleConsumer::addProducts(const std::string &productName, unsigned int amount, const std::string& producerType) {
    if (producerType != "store") {
        throw Exception("Incorrect producer type");
    }
    Consumer::addProducts(productName, amount, "");
}

WholesaleConsumer::WholesaleConsumer(std::string newName) : Consumer(std::move(newName), "wholesale") {

}
