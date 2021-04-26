#include "ComfortPlusCar.h"


ComfortPlusCar::ComfortPlusCar(std::string model, std::string color, std::string number) :
        Car(CarType::COMFORT_PLUS, std::move(model), std::move(color), std::move(number)),
        waterBottles(5), snacks(5)
{ }

ComfortPlusCar::ComfortPlusCar(std::string model, std::string color, std::string number, size_t id) :
        Car(CarType::COMFORT_PLUS, std::move(model), std::move(color), std::move(number), id),
        waterBottles(5), snacks(5)
{ }


size_t ComfortPlusCar::getWaterBottles() const {
    return waterBottles;
}

void ComfortPlusCar::setWaterBottles(size_t waterBottles) {
    ComfortPlusCar::waterBottles = waterBottles;
}

size_t ComfortPlusCar::getSnacks() const {
    return snacks;
}

void ComfortPlusCar::setSnacks(size_t snacks) {
    ComfortPlusCar::snacks = snacks;
}
