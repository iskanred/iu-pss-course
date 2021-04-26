#include "Order.h"

#include <algorithm>


Order::Order(TimeStamp startTime, TimeStamp endTime,
             Location startLocation, Location endLocation, long double distance,
             const long double cost, const Passenger &passenger, const Driver &driver,
             const Car &car, Payment payment) :
        id(counter++), startTime(std::move(startTime)), endTime(std::move(endTime)),
        startLocation(startLocation), endLocation(endLocation), distance(distance),
        cost(cost), passenger(passenger), driver(driver), car(car), payment(payment)
{ }

Order::Order(TimeStamp startTime, TimeStamp endTime,
             Location startLocation, Location endLocation, long double distance,
             long double cost, const Passenger &passenger, const Driver &driver,
             const Car &car, Payment payment, size_t id) :
        startTime(std::move(startTime)), endTime(std::move(endTime)),
        startLocation(startLocation), endLocation(endLocation), distance(distance),
        cost(cost), passenger(passenger), driver(driver), car(car), payment(payment), id(id)
{
    counter = std::max(counter, id + 1); // update real counter of orders
}


TimeDuration Order::getRideDuration() {
    return endTime - startTime;
}


size_t Order::getId() const {
    return id;
}

const TimeStamp &Order::getStartTime() const {
    return startTime;
}

const TimeStamp &Order::getEndTime() const {
    return endTime;
}

const Location &Order::getStartLocation() const {
    return startLocation;
}

const Location &Order::getEndLocation() const {
    return endLocation;
}

long double Order::getDistance() const {
    return distance;
}

long double Order::getCost() const {
    return cost;
}

const Passenger &Order::getPassenger() const {
    return passenger;
}

const Driver &Order::getDriver() const {
    return driver;
}

const Car &Order::getCar() const {
    return car;
}

Payment Order::getPayment() const {
    return payment;
}
