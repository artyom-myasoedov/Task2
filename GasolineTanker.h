//
// Created by volot on 14.03.2022.
//

#ifndef TASK2_GASOLINETANKER_H
#define TASK2_GASOLINETANKER_H


#include "Car.h"

class GasolineTanker : public Car {
public:
    GasolineTanker();

    void setCurrProductName(std::string productName) override;
};


#endif //TASK2_GASOLINETANKER_H
