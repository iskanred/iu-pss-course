#include "DriverGateway.h"

#include <algorithm>


const Driver &DriverGateway::addNewDriver(std::string name, std::string phoneNumber,
                                          std::string email, std::string carModel,
                                          std::string carColor, std::string carNumber)
{
    auto& carType = CarType::determineCarType(carModel, carColor, carNumber);
    auto& car = carType.getCarOfThisType(std::move(carModel), std::move(carColor), std::move(carNumber));

    return drivers.emplace_back(std::move(name), std::move(phoneNumber), std::move(email), car);
}

const Driver *DriverGateway::getMatchedDriver(const PotentialOrder &potentialOrder) {
    // here can be honest matching algorithm

    for (const auto& driver : drivers) {
        if (driver.isWorking() && !driver.isInRide() &&
            driver.getCar().getCarType() == potentialOrder.getCarType())
            return &driver;
    }

    return nullptr;
}

void DriverGateway::addOrderToHistoryOfDriver(const Order &order) {
    auto driverIt = std::find(drivers.begin(), drivers.end(), order.getDriver());
    driverIt->addOrder(order);
}
