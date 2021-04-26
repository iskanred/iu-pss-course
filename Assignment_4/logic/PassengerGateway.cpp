#include "PassengerGateway.h"

#include "System.h"

#include <algorithm>
#include <stdexcept>


const Passenger &PassengerGateway::addNewPassenger(std::string name, std::string phoneNumber, std::string email,
                                                   int deviceId)
{
    return passengers.emplace_back(std::move(name), std::move(phoneNumber), std::move(email), deviceId);
}

void PassengerGateway::addExistedPassenger(std::string name, std::string phoneNumber, std::string email,
                                           std::vector<double> ratings, std::vector<Location> pinnedLocations,
                                           std::vector<int> devicesIds, Payment paymentMethod, bool inRide, size_t id)
{
    passengers.emplace_back(std::move(name), std::move(phoneNumber), std::move(email),
                            std::move(ratings), std::move(pinnedLocations), std::move(devicesIds),
                            paymentMethod, inRide, id);
}

void PassengerGateway::addNewDevice(const Passenger &passenger, int deviceId) {
    System::registerNewDevice(passenger, deviceId);
}


bool PassengerGateway::makeOrder(const Passenger &passenger, const PotentialOrder &potentialOrder, Payment payment) {
    return System::makeOrder(passenger, potentialOrder, payment);
}

void PassengerGateway::addOrderToHistoryOfPassenger(const Order &order) {
    auto passengerIt = std::find(passengers.begin(), passengers.end(), order.getPassenger());
    passengerIt->addOrder(order);
}

void PassengerGateway::setInRideToPassenger(const Passenger &passenger) {
    auto passengerIt = std::find(passengers.begin(), passengers.end(), passenger);
    passengerIt->setInRide(true);
}

const Passenger &PassengerGateway::getPassengerById(size_t id) {
    auto matchId = [&id](const Passenger& passenger) {
        return id == passenger.getId();
    };

    auto passengerIt = std::find_if(passengers.begin(), passengers.end(), matchId);

    if (passengerIt != passengers.end())
        return *(passengerIt);
    else
        throw std::invalid_argument("wrong passenger id");
}

bool PassengerGateway::isPassengerBlocked(const Passenger &passenger) {
    return System::isPassengerBlocked(passenger);
}
