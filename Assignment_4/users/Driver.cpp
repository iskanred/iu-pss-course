#include "Driver.h"

#include "../logic/DriverGateway.h"

#include <algorithm>



Driver::Driver(std::string name, std::string phoneNumber, std::string email, const Car &car) :
    User(std::move(name), std::move(phoneNumber), std::move(email), counter++), workingStatus(false)
{
    if (DriverGatewayCarAdder::addNewCar(*this, car))
        currentCar = cars.emplace_back(&car);
}

Driver::Driver(std::string name, std::string phoneNumber, std::string email,
               std::vector<double> ratings, std::list<const Car*> cars, size_t id) :
    User(std::move(name), std::move(phoneNumber), std::move(email),
         std::move(ratings), id),
    cars(std::move(cars)), currentCar(Driver::cars.back()), workingStatus(true)
{
    counter = std::max(counter, id + 1);
}


void Driver::login() {
    signedIn = true;
}


void Driver::addNewCar(std::string model, std::string color, std::string number) {
    auto& carType = CarType::determineCarType(model,color, number);
    auto& car = carType.getCarOfThisType(std::move(model), std::move(color), std::move(number));

    if (DriverGatewayCarAdder::addNewCar(*this, car))
        cars.emplace_back(&car);
}

void Driver::changeCar(const Car &car) {
    currentCar = &car;
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


const std::list<const Car *> &Driver::getCars() const {
    return cars;
}

bool Driver::isWorking() const {
    return workingStatus;
}

void Driver::setWorkingStatus(bool workingStatus) {
    Driver::workingStatus = workingStatus;
}

const Car &Driver::getCurrentCar() const {
    return *currentCar;
}

