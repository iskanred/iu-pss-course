#ifndef ASSIGNMENT_4_COMFORTCAR_H
#define ASSIGNMENT_4_COMFORTCAR_H

#include "Car.h"


class ComfortCar : public Car {

    size_t waterBottles;

public:
    ComfortCar(std::string model, std::string color, std::string number);

    ComfortCar(std::string model, std::string color, std::string number, size_t id);


    [[nodiscard]] size_t getWaterBottles() const;

    void setWaterBottles(size_t waterBottles);
};


#endif //ASSIGNMENT_4_COMFORTCAR_H
