#include "EconomyCar.h"


EconomyCar::EconomyCar(std::string model, std::string color, std::string number) :
    Car(CarType::ECONOMY, std::move(model), std::move(color), std::move(number))
{ }

EconomyCar::EconomyCar(std::string model, std::string color, std::string number, size_t id) :
        Car(CarType::ECONOMY, std::move(model), std::move(color), std::move(number), id)
{ }
