#include "CarType.h"

#include "EconomyCar.h"
#include "ComfortCar.h"
#include "ComfortPlusCar.h"
#include "BusinessCar.h"

#include <ctime>
#include <stdexcept>


const CarType CarType::ECONOMY = CarType(Type::Economy);

const CarType CarType::COMFORT = CarType(Type::Comfort);

const CarType CarType::COMFORT_PLUS = CarType(Type::ComfortPlus);

const CarType CarType::BUSINESS = CarType(Type::Business);


const std::vector<const CarType*> CarType::CAR_TYPES = {&ECONOMY,
                                                        &COMFORT,
                                                        &COMFORT_PLUS,
                                                        &BUSINESS};


CarType::CarType(CarType::Type type) : type(type)
{ }


size_t CarType::getCarTypesNumber() {
    return CAR_TYPES.size();
}


const CarType &CarType::getCarTypeById(int id) {
    if (id < 0 || id >= getCarTypesNumber())
        throw std::invalid_argument("wrong car id");

    Type type = Type(id);

    switch (type) {
        case Type::Economy :
            return ECONOMY;
        case Type::Comfort :
            return COMFORT;
        case Type::ComfortPlus :
            return COMFORT_PLUS;
        case Type::Business :
            return BUSINESS;
    }
}

const CarType &CarType::determineCarType(const std::string &carModel,
                                         const std::string &carColor,
                                         const std::string &carNumber)
{
    // Here can be the determining car type
    // Now it is generated randomly
    int typeId = rand() % CarType::getCarTypesNumber();

    return CarType::getCarTypeById(typeId);
}


const CarType &CarType::getCarTypeFromName(const std::string &carTypeName) {
    if (carTypeName == ECONOMY.toString())
        return ECONOMY;
    else if (carTypeName == COMFORT.toString())
        return COMFORT;
    else if (carTypeName == COMFORT_PLUS.toString())
        return COMFORT_PLUS;
    else if (carTypeName == BUSINESS.toString())
        return BUSINESS;
    else
        throw std::invalid_argument("wrong name of car type");
}


const Car &CarType::getCarOfThisType(std::string carModel, std::string carColor,
                                     std::string carNumber) const
{
    Car* car;

    switch (type) {
        case Type::Economy :
            car = new EconomyCar(std::move(carModel), std::move(carColor), std::move(carNumber));
            break;
        case Type::Comfort :
            car = new ComfortCar(std::move(carModel), std::move(carColor), std::move(carNumber));
            break;
        case Type::ComfortPlus :
            car = new ComfortPlusCar(std::move(carModel), std::move(carColor), std::move(carNumber));
            break;
        case Type::Business :
            car = new BusinessCar(std::move(carModel), std::move(carColor), std::move(carNumber));
            break;
    }

    return *car;
}


std::string CarType::toString() const {
    switch (type) {
        case Type::Economy :
            return "Economy";
        case Type::Comfort :
            return "Comfort";
        case Type::ComfortPlus :
            return "ComfortPlus";
        case Type::Business :
            return "Business";
    }
}

bool CarType::operator==(const CarType &rhs) const {
    return type == rhs.type;
}

bool CarType::operator!=(const CarType &rhs) const {
    return !(rhs == *this);
}
