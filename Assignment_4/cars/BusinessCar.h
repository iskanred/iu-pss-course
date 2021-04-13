#ifndef ASSIGNMENT_4_BUSINESSCAR_H
#define ASSIGNMENT_4_BUSINESSCAR_H

#include "Car.h"


class BusinessCar : public Car {

    size_t waterBottles;

    size_t snacks;

public:
    BusinessCar(std::string model, std::string color, std::string number);


    void parkRightInFrontOfTheEntrance() const;


    [[nodiscard]] size_t getWaterBottles() const;

    void setWaterBottles(size_t waterBottles);

    [[nodiscard]] size_t getSnacks() const;

    void setSnacks(size_t snacks);
};

#endif //ASSIGNMENT_4_BUSINESSCAR_H
