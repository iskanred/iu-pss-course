#include "Test.h"

#include "../logic/System.h"
using namespace std;


void Test::registerPassenger(string name, string phoneNumber, string email) {
    System::registerPassenger(move(name), move(phoneNumber), move(email));
}

void Test::registerDriver(string name, string phoneNumber, string email, string carModel,
                          string carColor, string carNumber) {
    System::registerDriver(std::move(name), std::move(phoneNumber),
                           std::move(email), std::move(carModel),
                           std::move(carColor), std::move(carNumber));
}


Passenger &Test::getLastPassenger() {
    return PassengerGateway::passengers.back();
}

Driver &Test::getLastDriver() {
    return DriverGateway::drivers.back();
}

const Order &Test::getLastOrder() {
    return System::orders.back();
}


void Test::setDefaultPaymentMethodToPassenger(Passenger &passenger, Payment paymentMethod) {
    passenger.setPaymentMethod(paymentMethod);
}


void Test::setWorkingStatusToDriver(Driver &driver, bool workingStatus) {
    driver.setWorkingStatus(workingStatus);
}


std::vector<PotentialOrder> Test::getPotentialRideInfo(const Passenger &passenger,
                                                       const Location &from,
                                                       const Location &to) {
    return passenger.getPotentialRideInfo(from, to);
}

void Test::makeOrder(Passenger &passenger, const PotentialOrder &potentialOrder) {
    passenger.makeOrder(potentialOrder);
}
