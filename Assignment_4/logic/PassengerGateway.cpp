#include "PassengerGateway.h"

#include "System.h"

#include <algorithm>


const Passenger &PassengerGateway::addNewPassenger(std::string name,
                                       std::string phoneNumber,
                                       std::string email)
{
    return passengers.emplace_back(std::move(name), std::move(phoneNumber), std::move(email));
}

void PassengerGateway::addExistedPassenger(std::string name, std::string phoneNumber,
                                                       std::string email, std::vector<double> ratings,
                                                       std::vector<Location> pinnedLocations,
                                                       Payment paymentMethod, size_t id)
{
    passengers.emplace_back(std::move(name), std::move(phoneNumber), std::move(email),
                            std::move(ratings), std::move(pinnedLocations), paymentMethod, id);
}


bool PassengerGateway::makeOrder(const Passenger &passenger, const PotentialOrder &potentialOrder, Payment payment) {
    return System::makeOrder(passenger, potentialOrder, payment);
}

void PassengerGateway::addOrderToHistoryOfPassenger(const Order &order) {
    auto passengerIt = std::find(passengers.begin(), passengers.end(), order.getPassenger());
    passengerIt->addOrder(order);
}

const Passenger &PassengerGateway::getPassengerById(size_t id) {
    auto matchId = [&id](const Passenger& passenger) {
        return id == passenger.getId();
    };

    auto passengerIt = std::find_if(passengers.begin(), passengers.end(), matchId);

    if (passengerIt != passengers.end())
        return *(passengerIt);
    else
        throw ; // should throw an exception
}
