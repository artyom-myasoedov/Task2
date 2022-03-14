//
// Created by volot on 11.03.2022.
//

#ifndef TASK2_CONSUMER_H
#define TASK2_CONSUMER_H

#include <map>
#include <utility>


class Consumer {
protected:
    std::map<std::string, unsigned int> products;
    std::string name;
    std::string type;
public:
    Consumer(std::string newName, std::string type);

    ~Consumer();

    std::string getName();

    std::string getType();

    std::map<std::string, unsigned int> &getProducts();

    bool containsProduct(const std::string &productName);

    unsigned int getProductAmount(const std::string &productName);

    virtual void addProducts(const std::string &productName, unsigned int amount, const std::string & producerType);
};


#endif //TASK2_CONSUMER_H
