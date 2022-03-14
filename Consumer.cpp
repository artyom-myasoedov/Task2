//
// Created by volot on 11.03.2022.
//

#include "Consumer.h"

#include <utility>
#include <iostream>

Consumer::Consumer(std::string newName, std::string type) {
    this->name = std::move(newName);
    this->type = std::move(type);
    this->products = {};
}

Consumer::~Consumer() {}

std::string Consumer::getName() {
    return name;
}

std::map<std::string, unsigned int> &Consumer::getProducts() {
    return products;
}

void Consumer::addProducts(const std::string &productName, unsigned int amount, const std::string & producerType) {
    if (products.find(productName) != products.end()) {
        products[productName] += amount;
    } else {
        products[productName] = amount;
    }
    std::cout << amount << " " << productName << " were delivered to the " << type << " " << this->name << std::endl;
}

bool Consumer::containsProduct(const std::string &productName) {
    if (products.find(productName) == products.end()) {
        return false;
    }
    return products[productName] != 0;
}

unsigned int Consumer::getProductAmount(const std::string &productName) {
    if (containsProduct(productName)) {
        return products[productName];
    }
    return 0;
}

std::string Consumer::getType() {
    return this->type;
}
