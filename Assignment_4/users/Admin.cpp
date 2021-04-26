#include "Admin.h"
#include "../logic/AdminGateway.h"

#include "../io/Console.h"



Admin::Admin(std::string name, std::string phoneNumber, std::string email) :
    User(std::move(name), std::move(phoneNumber), std::move(email), counter++)
{ }

Admin::Admin(std::string name, std::string phoneNumber, std::string email, size_t id) :
User(std::move(name), std::move(phoneNumber), std::move(email), std::vector<double>(), id)
{ }


void Admin::login() {
    signedIn = true;
}


void Admin::blockRideForPassenger(const Passenger &passenger) const {
    AdminGatewayInterface::addPassengerToBlockList(passenger);
    Console::log("Admin " + toString() + " has blocked passenger " + passenger.toString());
}

void Admin::blockRideForDriver(const Driver &driver) const {
    AdminGatewayInterface::addDriverToBlockList(driver);
    Console::log("Admin " + toString() + " has blocked driver  " + driver.toString());
}


void Admin::unblockRideForPassenger(const Passenger &passenger) const {
    AdminGatewayInterface::removePassengerFromBlockList(passenger);
    Console::log("Admin " + toString() + " has unblocked passenger " + passenger.toString());
}

void Admin::unblockRideForDriver(const Driver &driver) const {
    AdminGatewayInterface::removeDriverFromBlockList(driver);
    Console::log("Admin " + toString() + " has unblocked driver  " + driver.toString());
}


void Admin::seeOrders() const {
    Console::log( "Admin " + toString() + " asked for see all orders");
    Console::printOrders(AdminGatewayInterface::getOrders());
}

void Admin::seePassengers() const {
    Console::log( "Admin " + toString() + " asked for see all passengers");
    Console::printPassengers(AdminGatewayInterface::getPassengers());
}

void Admin::seeDrivers() const {
    Console::log( "Admin " + toString() + " asked for see all drivers");
    Console::printDrivers(AdminGatewayInterface::getDrivers());
}

void Admin::seeBlockedPassengers() const {
    Console::log( "Admin " + toString() + " asked for see all blocked passengers");
    Console::printBlockedPassengers(AdminGatewayInterface::getBlockedPassengers());
}

void Admin::seeBlockedDrivers() const {
    Console::log( "Admin " + toString() + " asked for see all blocked drivers");
    Console::printBlockedDrivers(AdminGatewayInterface::getBlockedDrivers());
}


bool Admin::validateCar(const Car &car) const {
    // In future, can deny the car by some properties
    Console::log("Admin " + toString() + " has validated the car " + car.toString());
    return true;
}


std::string Admin::toString() const {
    return name + " " + phoneNumber + " " + email;
}