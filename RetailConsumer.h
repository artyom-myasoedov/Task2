//
// Created by volot on 13.03.2022.
//

#ifndef TASK2_RETAILCONSUMER_H
#define TASK2_RETAILCONSUMER_H
#include "Consumer.h"

class RetailConsumer: public Consumer{
public:
    RetailConsumer(std::string newName);

    void addProducts(const std::string &productName, unsigned int amount, const std::string & producerType) override;
};


#endif //TASK2_RETAILCONSUMER_H
