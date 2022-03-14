//
// Created by volot on 13.03.2022.
//

#ifndef TASK2_EXCEPTION_H
#define TASK2_EXCEPTION_H


#include <string>

class Exception {
private:
    std::string message;
public:
    Exception(std::string message);
    std::string getMessage();
};


#endif //TASK2_EXCEPTION_H
