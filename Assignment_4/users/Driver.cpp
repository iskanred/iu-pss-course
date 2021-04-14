#include "Driver.h"

#include <algorithm>



Driver::Driver(std::string name, std::string phoneNumber, std::string email, const Car &car) :
    User(std::move(name), std::move(phoneNumber), std::move(email), counter++),
    car(car), workingStatus(false)
{ }

Driver::Driver(std::string name, std::string phoneNumber, std::string email,
               std::vector<double> ratings, const Car &car, size_t id) :
    User(std::move(name), std::move(phoneNumber), std::move(email),
         std::move(ratings), id),
    car(car), workingStatus(true)
{
    counter = std::max(counter, id + 1);
}


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


