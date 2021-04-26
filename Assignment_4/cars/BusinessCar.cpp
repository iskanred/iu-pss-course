#include "BusinessCar.h"

#include "../io/Console.h"


BusinessCar::BusinessCar(std::string model, std::string color, std::string number) :
        Car(CarType::BUSINESS, std::move(model), std::move(color), std::move(number)),
        waterBottles(5), snacks(5)
{ }

BusinessCar::BusinessCar(std::string model, std::string color, std::string number, size_t id) :
        Car(CarType::BUSINESS, std::move(model), std::move(color), std::move(number), id),
        waterBottles(5), snacks(5)
{ }


void BusinessCar::parkRightInFrontOfTheEntrance() const {
    Console::printParkRightInFrontOfTheEntrance(*this);
}


size_t BusinessCar::getWaterBottles() const {
    return waterBottles;
}

void BusinessCar::setWaterBottles(size_t waterBottles) {
    BusinessCar::waterBottles = waterBottles;
}

size_t BusinessCar::getSnacks() const {
    return snacks;
}

void BusinessCar::setSnacks(size_t snacks) {
    BusinessCar::snacks = snacks;
}
