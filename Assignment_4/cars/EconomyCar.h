#ifndef ASSIGNMENT_4_ECONOMYCAR_H
#define ASSIGNMENT_4_ECONOMYCAR_H

#include "Car.h"


class EconomyCar : public Car {

public:
    EconomyCar(std::string model, std::string color, std::string number);

    EconomyCar(std::string model, std::string color, std::string number, size_t id);
};


#endif //ASSIGNMENT_4_ECONOMYCAR_H
