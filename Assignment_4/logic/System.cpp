#include "System.h"



void System::registerPassenger(std::string name, std::string phoneNumber, std::string email) {
    auto& passenger = PassengerGateway::addNewPassenger(std::move(name), std::move(phoneNumber),
                                                       std::move(email));

    DBHelper::writeNewPassenger(passenger);
}

void System::registerDriver(std::string name, std::string phoneNumber,
                            std::string email, std::string carModel,
                            std::string carColor, std::string carNumber)
{
    auto& driver = DriverGateway::addNewDriver(std::move(name), std::move(phoneNumber),
                                                std::move(email), std::move(carModel),
                                                std::move(carColor), std::move(carNumber));

    DBHelper::writeNewDriverAndCar(driver);
}


void System::restoreInfo() {
    DBHelper::readPassengers();
    DBHelper::readDrivers();
    DBHelper::readOrders();
}

void System::logInPassenger(std::string name, std::string phoneNumber, std::string email, std::vector<double> ratings,
                            std::vector<Location> pinnedLocations, Payment paymentMethod, size_t id)
{
    PassengerGateway::addExistedPassenger(std::move(name), std::move(phoneNumber), std::move(email),
                                          std::move(ratings), std::move(pinnedLocations), paymentMethod, id);
}

void System::logInDriver(std::string name, std::string phoneNumber, std::string email,
                         std::vector<double> ratings, size_t id,
                         const CarType &carType, std::string carModel, std::string carColor, std::string carNumber)
{
    DriverGateway::addExistedDriver(std::move(name), std::move(phoneNumber), std::move(email),
                                    std::move(ratings), id, carType, std::move(carModel), std::move(carColor), std::move(carNumber));
}

void System::logInOrder(TimeStamp startTime, TimeStamp endTime, Location startLocation, Location endLocation,
                        long double distance, long double cost, size_t passengerId, size_t driverId,
                        Payment payment, size_t id)
{
    auto& passenger = PassengerGateway::getPassengerById(passengerId);
    auto& driver = DriverGateway::getDriverById(driverId);

    auto& order = orders.emplace_back(std::move(startTime), std::move(endTime),
                        startLocation, endLocation, distance,
                        cost, passenger, driver, payment, id);

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
                            potentialOrder.getPrice(), passenger, *driver, payment);

    PassengerGateway::addOrderToHistoryOfPassenger(order);
    DriverGateway::addOrderToHistoryOfDriver(order);

    DBHelper::writeNewOrder(order);

    return true;
}
