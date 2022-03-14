//
// Created by volot on 13.03.2022.
//

#ifndef TASK2_WHOLESALECONSUMER_H
#define TASK2_WHOLESALECONSUMER_H


#include <string>
#include "Consumer.h"

class WholesaleConsumer: public Consumer {
public:
    WholesaleConsumer(std::string newName);

    void addProducts(const std::string &productName, unsigned int amount, const std::string& producerType) override;
};


#endif //TASK2_WHOLESALECONSUMER_H
