#include "ComfortCar.h"


ComfortCar::ComfortCar(std::string model, std::string color, std::string number) :
    Car(CarType::COMFORT, std::move(model), std::move(color), std::move(number)),
    waterBottles(5)
{ }


size_t ComfortCar::getWaterBottles() const {
    return waterBottles;
}

void ComfortCar::setWaterBottles(size_t waterBottles) {
    ComfortCar::waterBottles = waterBottles;
}
