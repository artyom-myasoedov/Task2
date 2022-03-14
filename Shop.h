//
// Created by volot on 13.03.2022.
//

#ifndef TASK2_SHOP_H
#define TASK2_SHOP_H
#include "Producer.h"

class Shop: public Producer{
public:
    Shop(std::string newName);
    void sendProductBatch(Consumer& consumer, const std::string& productName, unsigned int amount) override;
};


#endif //TASK2_SHOP_H
