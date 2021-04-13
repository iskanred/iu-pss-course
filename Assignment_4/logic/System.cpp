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

    // Database write

    return true;
}
