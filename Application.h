//
// Created by volot on 14.03.2022.
//

#ifndef TASK2_APPLICATION_H
#define TASK2_APPLICATION_H


#include "Producer.h"
#include "Consumer.h"
#include <map>

class Application {
public:
    std::map<std::string, Consumer*> consumers;
    std::map<std::string, Producer*> producers;

    void start();
    void init();

    Application();
    ~Application();

    void showMainMenu();
};


#endif //TASK2_APPLICATION_H
