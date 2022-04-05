#include "Car.h"

#include <algorithm>


Car::Car(const CarType &carType, std::string model, std::string color, std::string number) :
    carType(&carType), model(std::move(model)), color(std::move(color)), number(std::move(number)), id(counter++)
{ }

Car::Car(const CarType &carType, std::string model, std::string color, std::string number, size_t id) :
    carType(&carType), model(std::move(model)), color(std::move(color)), number(std::move(number)), id(id)
{
    counter = std::max(counter, id + 1);
}


std::string Car::toString() const {
    return carType->toString() + " " + color + " [ " + model + " ] " + number;
}


void Car::setColor(const std::string &color) {
    Car::color = color;
}

void Car::setNumber(const std::string &number) {
    Car::number = number;
}


Location Car::getCurrentLocation() const {
    // Here can be computations of current location of this car
    // Now it is just randomly generated
    return Location(rand() % 10000 + 1, rand() % 10000 + 1);
}

const CarType &Car::getCarType() const {
    return *carType;
}

const std::string &Car::getModel() const {
    return model;
}

const std::string &Car::getColor() const {
    return color;
}

const std::string &Car::getNumber() const {
    return number;
}

size_t Car::getId() const {
    return id;
}
