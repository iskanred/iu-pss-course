#include "Passenger.h"

#include "../logic/PassengerGateway.h"
#include "../io/Console.h"

#include <algorithm>



Passenger::Passenger(std::string name,std::string phoneNumber, std::string email, int deviceId) :
    User(std::move(name), std::move(phoneNumber), std::move(email), counter++),
    pinnedLocations(), paymentMethod(), devicesIds(1, deviceId), inRide(false)
{ }

Passenger::Passenger(std::string name, std::string phoneNumber, std::string email,
                     std::vector<double> ratings, std::vector<Location> pinnedLocations,
                     std::vector<int> devicesIds, Payment paymentMethod, bool inRide, size_t id) :
    User(std::move(name), std::move(phoneNumber), std::move(email), std::move(ratings), id),
    pinnedLocations(std::move(pinnedLocations)), paymentMethod(paymentMethod),
    devicesIds(std::move(devicesIds)), inRide(inRide)
{
    counter = std::max(counter, id + 1);
}


void Passenger::login(int deviceId) {
    if (std::find(devicesIds.begin(), devicesIds.end(), deviceId) == devicesIds.end()) {
        signedIn = true;
        devicesIds.emplace_back(deviceId);
        PassengerGateway::addNewDevice(*this, deviceId);
    }
}

void Passenger::addLocation(const Location &location) {
    pinnedLocations.push_back(location);
}

std::vector<PotentialOrder> Passenger::getPotentialRideInfo(Location from, Location to) const {
    std::vector<PotentialOrder> potentialRideInfo;

    potentialRideInfo.reserve(CarType::getCarTypesNumber());

    for (const auto& carType : CarType::CAR_TYPES)
        potentialRideInfo.emplace_back(from, to, *carType);

    return potentialRideInfo;
}

void Passenger::makeOrder(const PotentialOrder &potentialOrder) {
    makeOrder(potentialOrder, paymentMethod);
}

void Passenger::makeOrder(const PotentialOrder &potentialOrder, Payment payment) {
    if (inRide) {
        Console::printPassengerInRide();
        Console::log(toString() + " has tried to order a new ride during another ride");
        return;
    }

    if (PassengerGateway::isPassengerBlocked(*this)) {
        try {
            throw BlockedPassengerException(*this);
        } catch (const BlockedPassengerException &bpe) {
            Console::printPassengerBlocked();
            Console::log(bpe.what());
            return;
        }
    }

    inRide = PassengerGateway::makeOrder(*this, potentialOrder, payment);

    if (inRide)
        Console::printNewOrder();
    else
        Console::printNoFreeDrivers();
}

void Passenger::askForBill(const Order &order) const {
    // here can be print bill to interface
    Console::log("passenger " + toString() + " asked for a bill");
    Console::printBill(order);
}


std::string Passenger::toString() const {
    return name + " " + phoneNumber + " " + email;
}


const std::vector<const Order *> &Passenger::getOrderHistory() const {
    return orderHistory;
}

const std::vector<Location> &Passenger::getPinnedLocations() const {
    return pinnedLocations;
}

void Passenger::setPaymentMethod(Payment payment) {
    paymentMethod = payment;
}

Payment Passenger::getPaymentMethod() const {
    return paymentMethod;
}

const std::vector<int> &Passenger::getDevicesIds() const {
    return devicesIds;
}

bool Passenger::isInRide() const {
    return inRide;
}

void Passenger::setInRide(bool inRide) {
    Passenger::inRide = inRide;
}


BlockedPassengerException::BlockedPassengerException(const Passenger &passenger) :
    passengerInfo(passenger.toString())
{ }

const char *BlockedPassengerException::what() const noexcept {
    return (new std::string("blocked user " + passengerInfo + " tried to order a ride"))->c_str();
}
