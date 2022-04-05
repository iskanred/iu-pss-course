#include "AdminGateway.h"

#include "System.h"
#include "PassengerGateway.h"

#include <stdexcept>



const Admin &AdminGateway::addNewAdmin(std::string name, std::string phoneNumber, std::string email) {
    return admins.emplace_back(std::move(name), std::move(phoneNumber), std::move(email));
}


void AdminGateway::addPassengerToBlockList(const Passenger &passenger) {
    System::addPassengerToBlockList(passenger);
}

void AdminGateway::addDriverToBlockList(const Driver &driver) {
    System::addDriverToBlockList(driver);
}

void AdminGateway::removePassengerFromBlockList(const Passenger &passenger) {
    System::removePassengerFromBlockList(passenger);
}

void AdminGateway::removeDriverFromBlockList(const Driver &driver) {
    System::removeDriverFromBlockList(driver);
}


bool AdminGateway::validateCar(const Car &car) {
    if (admins.empty())
        throw std::logic_error("no admins to validate the car");

    return admins.front().validateCar(car);
}


std::list<const Order *> AdminGateway::getOrders() {
    std::list<const Order *> orders;

    for (const auto& order : System::orders) {
        orders.emplace_back(&order);
    }

    return orders;
}

std::list<const Passenger *> AdminGateway::getPassengers() {
    return System::getPassengers();
}

std::list<const Driver *> AdminGateway::getDrivers() {
    return System::getDrivers();
}

std::list<const Passenger *> AdminGateway::getBlockedPassengers() {
    return System::blockedPassengers;
}

std::list<const Driver *> AdminGateway::getBlockedDrivers() {
    return System::blockedDrivers;
}




void AdminGatewayInterface::addPassengerToBlockList(const Passenger &passenger) {
    AdminGateway::addPassengerToBlockList(passenger);
}

void AdminGatewayInterface::addDriverToBlockList(const Driver &driver) {
    AdminGateway::addDriverToBlockList(driver);
}

void AdminGatewayInterface::removePassengerFromBlockList(const Passenger &passenger) {
    AdminGateway::removePassengerFromBlockList(passenger);
}

void AdminGatewayInterface::removeDriverFromBlockList(const Driver &driver) {
    AdminGateway::removeDriverFromBlockList(driver);
}


std::list<const Order *> AdminGatewayInterface::getOrders() {
    return AdminGateway::getOrders();
}

std::list<const Passenger *> AdminGatewayInterface::getPassengers() {
    return AdminGateway::getPassengers();
}

std::list<const Driver *> AdminGatewayInterface::getDrivers() {
    return AdminGateway::getDrivers();
}

std::list<const Passenger *> AdminGatewayInterface::getBlockedPassengers() {
    return AdminGateway::getBlockedPassengers();
}

std::list<const Driver *> AdminGatewayInterface::getBlockedDrivers() {
    return AdminGateway::getBlockedDrivers();
}
