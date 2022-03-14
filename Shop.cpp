//
// Created by volot on 13.03.2022.
//

#include "Shop.h"
#include "Exception.h"
#include <utility>

Shop::Shop(std::string newName) : Producer(std::move(newName), "shop") {

}

void Shop::sendProductBatch(Consumer &consumer, const std::string &productName, unsigned int amount) {
    if (consumer.getType() == "retail") {
        Producer::sendProductBatch(consumer, productName, amount);
    } else {
        throw Exception("Incorrect consumer type");
    }
}
