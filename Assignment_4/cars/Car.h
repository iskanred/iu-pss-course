#ifndef ASSIGNMENT_4_CAR_H
#define ASSIGNMENT_4_CAR_H

#include "../location/Location.h"
#include "CarType.h"

#include <string>


class CarType;


class Car {

protected:

    const CarType *carType;

    const std::string model;

    std::string color;

    std::string number;

    Car(const CarType& carType,
        std::string model,
        std::string color,
        std::string number);

public:

    std::string toString() const;


    void setColor(const std::string &color);

    void setNumber(const std::string &number);


    [[nodiscard]] Location getCurrentLocation() const;

    [[nodiscard]] const CarType &getCarType() const;

    [[nodiscard]] const std::string &getModel() const;

    [[nodiscard]] const std::string &getColor() const;

    [[nodiscard]] const std::string &getNumber() const;



    /* Deleting all possible ways to create an instance of this class */

    Car() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    Car(const Car&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    Car& operator=(const Car&) = delete;
};


#endif //ASSIGNMENT_4_CAR_H
