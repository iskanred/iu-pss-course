#include "System.h"

#include "../io/Console.h"
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "AdminGateway.h"
#include "DBHelper.h"

#include <algorithm>



std::list<const Passenger *> System::getPassengers() {
    std::list<const Passenger *> passengers;

    for (const auto& passenger : PassengerGateway::passengers) {
        passengers.emplace_back(&passenger);
    }

    return passengers;
}

std::list<const Driver *> System::getDrivers() {
    std::list<const Driver *> drivers;

    for (const auto& driver : DriverGateway::drivers) {
        drivers.emplace_back(&driver);
    }

    return drivers;
}


void System::registerPassenger(std::string name, std::string phoneNumber, std::string email, int deviceId) {
    if (DBHelper::checkIfPassengerExist(phoneNumber)) {
        Console::printUserExist();
        return;
    }

    auto& passenger = PassengerGateway::addNewPassenger(std::move(name), std::move(phoneNumber),
                                                       std::move(email), deviceId);

    DBHelper::writeNewPassenger(passenger);
}


bool System::registerNewCar(const Driver &driver, const Car &car) {
    if (DBHelper::checkIfCarExist(car.getNumber())) {
        Console::printCarExist();
        return false;
    }
    if (!AdminGateway::validateCar(car)) {
        Console::printCarNotValidated();
        return false;
    }

    DBHelper::writeNewCar(driver, car);
    return true;
}


void System::registerDriver(std::string name, std::string phoneNumber,
                            std::string email, std::string carModel,
                            std::string carColor, std::string carNumber)
{
    if (DBHelper::checkIfDriverExist(phoneNumber)) {
        Console::printUserExist();
        return;
    }

    auto& driver = DriverGateway::addNewDriver(std::move(name), std::move(phoneNumber),
                                                std::move(email), std::move(carModel),
                                                std::move(carColor), std::move(carNumber));

    DBHelper::writeNewDriver(driver);
}

void System::registerAdmin(std::string name, std::string phoneNumber, std::string email) {
    if (DBHelper::checkIfAdminExist(phoneNumber)) {
        Console::printUserExist();
        return;
    }

    auto& admin = AdminGateway::addNewAdmin(std::move(name), std::move(phoneNumber), std::move(email));

    DBHelper::writeNewAdmin(admin);
}

void System::registerNewDevice(const Passenger &passenger, int deviceId) {
    DBHelper::writeNewDeviceToPassenger(passenger.getId(), deviceId);
}


void System::restoreInfo() {
    DBHelper::readPassengers();
    DBHelper::readDrivers();
    DBHelper::readBlockedPassengers();
    DBHelper::readBlockedDrivers();
    DBHelper::readOrders();
}

void System::logInPassenger(std::string name, std::string phoneNumber, std::string email, std::vector<double> ratings,
                            std::vector<Location> pinnedLocations, std::vector<int> devicesIds,
                            Payment paymentMethod, bool inRide, size_t id)
{
    PassengerGateway::addExistedPassenger(std::move(name), std::move(phoneNumber), std::move(email),
                                          std::move(ratings), std::move(pinnedLocations),
                                          std::move(devicesIds), paymentMethod, inRide, id);
}

void System::logInDriver(std::string name, std::string phoneNumber, std::string email,
                         std::vector<double> ratings, size_t id, std::list<const Car*> cars)
{
    DriverGateway::addExistedDriver(std::move(name), std::move(phoneNumber), std::move(email),
                                    std::move(ratings), id, std::move(cars));
}

void System::logInBlockedPassenger(size_t id) {
    auto matchId = [&id](const Passenger& passenger) {
        return id == passenger.getId();
    };

    auto passengerIt = std::find_if(PassengerGateway::passengers.begin(),
                                PassengerGateway::passengers.end(), matchId);

    blockedPassengers.emplace_back(&(*passengerIt));
}

void System::logInBlockedDriver(size_t id) {
    auto matchId = [&id](const Driver& driver) {
        return id == driver.getId();
    };

    auto driverIt = std::find_if(DriverGateway::drivers.begin(),
                                  DriverGateway::drivers.end(), matchId);

    blockedDrivers.emplace_back(&(*driverIt));
}

void System::logInAdmin(size_t id, std::string name, std::string phoneNumber, std::string email) {
    AdminGateway::admins.emplace_back(std::move(name), std::move(phoneNumber), std::move(email), id);
}

void System::logInOrder(TimeStamp startTime, TimeStamp endTime, Location startLocation, Location endLocation,
                        long double distance, long double cost, size_t passengerId, size_t driverId, size_t carId,
                        Payment payment, size_t id)
{
    auto& passenger = PassengerGateway::getPassengerById(passengerId);
    auto& driver = DriverGateway::getDriverById(driverId);

    if (TimeStamp() < endTime)
        PassengerGateway::setInRideToPassenger(passenger);

    auto matchId = [&carId](const Car* car) {
        return car->getId() == carId;
    };
    // This driver should have this car
    auto car = std::find_if(driver.getCars().begin(), driver.getCars().end(), matchId);

    auto& order = orders.emplace_back(std::move(startTime), std::move(endTime),
                        startLocation, endLocation, distance,
                        cost, passenger, driver, *(*car), payment, id);

    PassengerGateway::addOrderToHistoryOfPassenger(order);
    DriverGateway::addOrderToHistoryOfDriver(order);
}


bool System::makeOrder(const Passenger &passenger, const PotentialOrder &potentialOrder, Payment payment) {
    auto driver = DriverGateway::getMatchedDriver(potentialOrder);

    if (driver == nullptr)
        return false;

    TimeStamp startTime; // currentTime
    TimeStamp endTime = startTime + potentialOrder.getExpectedTime();

    auto& order = orders.emplace_back(startTime, endTime, potentialOrder.getLocationFrom(),
                            potentialOrder.getLocationTo(), potentialOrder.getDistance(),
                            potentialOrder.getPrice(), passenger, *driver, driver->getCurrentCar(), payment);

    PassengerGateway::addOrderToHistoryOfPassenger(order);
    DriverGateway::addOrderToHistoryOfDriver(order);

    DBHelper::writeNewOrder(order);

    return true;
}


void System::addPassengerToBlockList(const Passenger &passenger) {
    blockedPassengers.emplace_back(&passenger);
    DBHelper::writeBlockedPassenger(passenger);
}

void System::addDriverToBlockList(const Driver &driver) {
    blockedDrivers.emplace_back(&driver);
    DBHelper::writeBlockedDriver(driver);
}

bool System::isDriverBlocked(const Driver &driver) {
    return std::find(blockedDrivers.begin(), blockedDrivers.end(), &driver) != blockedDrivers.end();
}

bool System::isPassengerBlocked(const Passenger &passenger) {
    return std::find(blockedPassengers.begin(), blockedPassengers.end(), &passenger) != blockedPassengers.end();
}


void System::removePassengerFromBlockList(const Passenger &passenger) {
    size_t blockedPassengersNumber = blockedPassengers.size();
    blockedPassengers.remove(&passenger);

    if (blockedPassengersNumber != blockedPassengers.size())
        DBHelper::removeBlockedPassenger(passenger);
}

void System::removeDriverFromBlockList(const Driver &driver) {
    size_t blockedDriversNumber = blockedDrivers.size();

    blockedDrivers.remove(&driver);

    if (blockedDriversNumber != blockedDrivers.size())
        DBHelper::removeBlockedDriver(driver);
}
