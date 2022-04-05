#ifndef ASSIGNMENT_4_COMFORTPLUSCAR_H
#define ASSIGNMENT_4_COMFORTPLUSCAR_H


#include "Car.h"


class ComfortPlusCar : public Car {

    size_t waterBottles;

    size_t snacks;

public:
    ComfortPlusCar(std::string model, std::string color, std::string number);

    ComfortPlusCar(std::string model, std::string color, std::string number, size_t id);


    [[nodiscard]] size_t getWaterBottles() const;

    void setWaterBottles(size_t waterBottles);

    [[nodiscard]] size_t getSnacks() const;

    void setSnacks(size_t snacks);
};


#endif //ASSIGNMENT_4_COMFORTPLUSCAR_H
