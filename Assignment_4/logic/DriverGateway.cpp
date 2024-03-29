#include "DriverGateway.h"

#include "System.h"

#include <algorithm>
#include <stdexcept>


const Driver &DriverGateway::addNewDriver(std::string name, std::string phoneNumber,
                                          std::string email, std::string carModel,
                                          std::string carColor, std::string carNumber)
{
    auto& carType = CarType::determineCarType(carModel, carColor, carNumber);
    auto& car = carType.getCarOfThisType(std::move(carModel), std::move(carColor), std::move(carNumber));

    return drivers.emplace_back(std::move(name), std::move(phoneNumber), std::move(email), car);
}

void DriverGateway::addExistedDriver(std::string name, std::string phoneNumber, std::string email,
                                              std::vector<double> ratings, size_t id,
                                              std::list<const Car*> cars)
{
    drivers.emplace_back(std::move(name), std::move(phoneNumber),
                         std::move(email), std::move(ratings), std::move(cars), id);
}


const Driver *DriverGateway::getMatchedDriver(const PotentialOrder &potentialOrder) {
    // here can be honest matching algorithm

    for (const auto& driver : drivers) {
        if (!System::isDriverBlocked(driver) && driver.isWorking() && !driver.isInRide() &&
            driver.getCurrentCar().getCarType() == potentialOrder.getCarType())
            return &driver;
    }

    return nullptr;
}

void DriverGateway::addOrderToHistoryOfDriver(const Order &order) {
    auto driverIt = std::find(drivers.begin(), drivers.end(), order.getDriver());
    driverIt->addOrder(order);
}

const Driver &DriverGateway::getDriverById(size_t id) {
    auto matchId = [&id](const Driver& driver) {
        return id == driver.getId();
    };

    auto driverIt = std::find_if(drivers.begin(), drivers.end(), matchId);

    if (driverIt != drivers.end())
        return *(driverIt);
    else
        throw std::invalid_argument("wrong driver id");
}

bool DriverGateway::registerNewCar(const Driver &driver, const Car &car) {
    return System::registerNewCar(driver, car);
}

bool DriverGatewayCarAdder::addNewCar(const Driver &driver, const Car &car) {
    return DriverGateway::registerNewCar(driver, car);
}


bool DriverGateway::isDriverBlocked(const Driver &driver) {
    return System::isDriverBlocked(driver);
}
