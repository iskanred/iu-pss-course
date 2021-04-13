#include "PassengerGateway.h"

#include "System.h"

#include <algorithm>


const Passenger &PassengerGateway::addNewPassenger(std::string name,
                                       std::string phoneNumber,
                                       std::string email)
{
    return passengers.emplace_back(std::move(name), std::move(phoneNumber), std::move(email));
}

bool PassengerGateway::makeOrder(const Passenger &passenger, const PotentialOrder &potentialOrder, Payment payment) {
    return System::makeOrder(passenger, potentialOrder, payment);
}

void PassengerGateway::addOrderToHistoryOfPassenger(const Order &order) {
    auto passengerIt = std::find(passengers.begin(), passengers.end(), order.getPassenger());
    passengerIt->addOrder(order);
}

