#include "Test.h"

#include "../logic/System.h"
#include "../logic/PassengerGateway.h"
#include "../logic/DriverGateway.h"
#include "../logic/AdminGateway.h"


#include <stdexcept>
using namespace std;


Passenger &Test::registerPassenger(string name, string phoneNumber, string email, int deviceId) {
    size_t passengersNumber = PassengerGateway::passengers.size();

    System::registerPassenger(move(name), move(phoneNumber), move(email), deviceId);

    if (passengersNumber == PassengerGateway::passengers.size())
        throw std::logic_error("passenger was not added");

    return PassengerGateway::passengers.back();
}

Driver &Test::registerDriver(string name, string phoneNumber, string email, string carModel,
                          string carColor, string carNumber)
{
    size_t driversNumber = DriverGateway::drivers.size();

    System::registerDriver(std::move(name), std::move(phoneNumber),
                           std::move(email), std::move(carModel),
                           std::move(carColor), std::move(carNumber));

    if (driversNumber == DriverGateway::drivers.size())
        throw std::logic_error("driver was not added");

    return DriverGateway::drivers.back();
}

Admin &Test::registerAdmin(std::string name, std::string phoneNumber, std::string email) {
    size_t adminsNumber = AdminGateway::admins.size();

    System::registerAdmin(std::move(name), std::move(phoneNumber), std::move(email));

    if (adminsNumber == AdminGateway::admins.size())
        throw std::logic_error("admin was not added");

    return AdminGateway::admins.back();
}


void Test::restoreInfoFromDB() {
    System::restoreInfo();
}


const Order &Test::getLastOrder() {
    if (System::orders.empty())
        throw std::logic_error("orders list is empty");

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

bool Test::makeOrder(Passenger &passenger, const PotentialOrder &potentialOrder) {
    size_t startOrdersCount = System::orders.size();

    passenger.makeOrder(potentialOrder);

    if (System::orders.size() > startOrdersCount)
        return true;
    else
        return false;
}

const Car &Test::addCarToDriver(Driver &driver, std::string carModel, std::string carColor, std::string carNumber) {
    size_t carsNumber = driver.getCars().size();

    driver.addNewCar(std::move(carModel), std::move(carColor), std::move(carNumber));

    if (carsNumber == driver.getCars().size())
        throw std::logic_error("car was not added");

    return *driver.getCars().back();
}

void Test::setCurrentCarToDriver(Driver &driver, const Car &car) {
    return driver.changeCar(car);
}


void Test::blockDriverByAdmin(const Admin &admin, const Driver &driver) {
    admin.blockRideForDriver(driver);
}

void Test::blockPassengerByAdmin(const Admin &admin, const Passenger &passenger) {
    admin.blockRideForPassenger(passenger);
}

void Test::unblockDriverByAdmin(const Admin &admin, const Driver &driver) {
    admin.unblockRideForDriver(driver);
}

void Test::unblockPassengerByAdmin(const Admin &admin, const Passenger &passenger) {
    admin.unblockRideForPassenger(passenger);
}


void Test::seeOrdersByAdmin(const Admin &admin) {
    admin.seeOrders();
}

void Test::seePassengersByAdmin(const Admin &admin) {
    admin.seePassengers();
}

void Test::seeDriversByAdmin(const Admin &admin) {
    admin.seeDrivers();
}

void Test::seeBlockedPassengersByAdmin(const Admin &admin) {
    admin.seeBlockedPassengers();
}

void Test::seeBlockedDriversByAdmin(const Admin &admin) {
    admin.seeBlockedDrivers();
}
