#ifndef ASSIGNMENT_4_POTENTIALORDER_H
#define ASSIGNMENT_4_POTENTIALORDER_H

#include "../time/TimeDuration.h"
#include "../location/Location.h"
#include "../cars/CarType.h"


class PotentialOrder {

    const TimeDuration expectedTime;

    const long double price;

    const CarType *carType;

    const long double distance;

    const Location locationFrom;

    const Location locationTo;


    static long double computePrice(Location from, Location to, const CarType &carType);

    static TimeDuration computeExpectedTime(Location from, Location to, const CarType &carType);

    static long double computeDistance(Location from, Location to, const CarType &carType);


public:
    PotentialOrder(Location from, Location to, const CarType &carType);


    [[nodiscard]] const TimeDuration &getExpectedTime() const;

    [[nodiscard]] long double getPrice() const;

    [[nodiscard]] const CarType &getCarType() const;

    [[nodiscard]] long double getDistance() const;

    [[nodiscard]] const Location &getLocationFrom() const;

    [[nodiscard]] const Location &getLocationTo() const;
};


#endif //ASSIGNMENT_4_POTENTIALORDER_H
