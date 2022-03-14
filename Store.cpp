//
// Created by volot on 13.03.2022.
//

#include "Store.h"
#include "Exception.h"

#include <utility>

Store::Store(std::string newName): Producer(std::move(newName), "store") {
}

void Store::sendProductBatch(Consumer &consumer, const std::string &productName, unsigned int amount) {
    if (consumer.getType() == "wholesale") {
        Producer::sendProductBatch(consumer, productName, amount);
    } else {
        throw Exception("Incorrect consumer type");
    }
}
