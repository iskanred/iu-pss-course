#include "PotentialOrder.h"

#include <ctime>
#include <cstdlib>



PotentialOrder::PotentialOrder(Location from, Location to, const CarType &carType) :
        price(computePrice(from, to, carType)), expectedTime(computeExpectedTime(from, to, carType)),
        carType(&carType), distance(computeDistance(from, to, carType)),
        locationFrom(from), locationTo(to)
{ }


// Here can be an algorithm that computes the
//  price of the potential ride from 'from' to 'to' locations
// Now it is generated randomly
long double PotentialOrder::computePrice(Location from, Location to, const CarType &carType) {
    srand(time(nullptr));
    return rand() % 10000;
}

// Here can be an algorithm that computes the
//  the expected time of the potential ride from 'from' to 'to' locations
// Now it is generated randomly
TimeDuration PotentialOrder::computeExpectedTime(Location from, Location to, const CarType &carType) {
    srand(time(nullptr));
    return TimeDuration(rand());
}

// Here can be an algorithm that computes the
//  the expected distance of the potential ride from 'from' to 'to' locations
// Now it is generated randomly
long double PotentialOrder::computeDistance(Location from, Location to, const CarType &carType) {
    srand(time(nullptr));
    return rand() % 1000;
}


const TimeDuration &PotentialOrder::getExpectedTime() const {
    return expectedTime;
}

long double PotentialOrder::getPrice() const {
    return price;
}

const CarType &PotentialOrder::getCarType() const {
    return *carType;
}

long double PotentialOrder::getDistance() const {
    return distance;
}

const Location &PotentialOrder::getLocationFrom() const {
    return locationFrom;
}

const Location &PotentialOrder::getLocationTo() const {
    return locationTo;
}
