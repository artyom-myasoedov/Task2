//
// Created by volot on 13.03.2022.
//

#ifndef TASK2_STORE_H
#define TASK2_STORE_H


#include <string>
#include "Producer.h"

class Store: public Producer{
public:
    Store(std::string newName);
    void sendProductBatch(Consumer& consumer, const std::string& productName, unsigned int amount) override;
};


#endif //TASK2_STORE_H
