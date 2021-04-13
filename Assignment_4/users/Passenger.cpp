#include "Passenger.h"

#include "../logic/PassengerGateway.h"
#include "../io/Console.h"


Passenger::Passenger(std::string name,std::string phoneNumber, std::string email) :
    User(std::move(name), std::move(phoneNumber), std::move(email)),
    pinnedLocations(), paymentMethod()
{ }

Passenger::Passenger(std::string name, std::string phoneNumber, std::string email,
                     std::vector<double> ratings, std::vector<const Order *> orderHistory,
                     std::vector<Location> pinnedLocations, Payment paymentMethod) :
    User(std::move(name), std::move(phoneNumber), std::move(email),
         std::move(ratings), std::move(orderHistory)),
    pinnedLocations(std::move(pinnedLocations)), paymentMethod(paymentMethod)
{ }


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

void Passenger::makeOrder(const PotentialOrder &potentialOrder, Payment payment) const {
    bool orderMade = PassengerGateway::makeOrder(*this, potentialOrder, payment);

    if (orderMade)
        Console::printNewOrder();
    else
        Console::printNoFreeDrivers();
}

void Passenger::askForBill(const Order &order) const {
    // here can be print bill to interface
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
