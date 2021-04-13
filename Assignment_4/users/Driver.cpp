#include "Driver.h"



Driver::Driver(std::string name, std::string phoneNumber, std::string email, const Car &car) :
    User(std::move(name), std::move(phoneNumber), std::move(email)),
    car(car), workingStatus(false)
{ }

Driver::Driver(std::string name, std::string phoneNumber, std::string email,
               std::vector<double> ratings, std::vector<const Order *> orderHistory, const Car &car) :
    User(std::move(name), std::move(phoneNumber), std::move(email),
         std::move(ratings), std::move(orderHistory)),
    car(car), workingStatus(false)
{ }


bool Driver::isInRide() const {
    // if driver has no orders yet or he is not working now
    if (orderHistory.empty() || !isWorking())
        return false;

    TimeStamp currentTime;

    if (currentTime >= orderHistory.back()->getStartTime() &&
        currentTime <= orderHistory.back()->getEndTime())
    {
        return true;
    }

    return false;
}


std::string Driver::toString() const {
    return name + " " + phoneNumber + " " + email;
}


const Car &Driver::getCar() const {
    return car;
}

bool Driver::isWorking() const {
    return workingStatus;
}

void Driver::setWorkingStatus(bool workingStatus) {
    Driver::workingStatus = workingStatus;
}


