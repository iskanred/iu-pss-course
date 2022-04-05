#ifndef ASSIGNMENT_4_ORDER_H
#define ASSIGNMENT_4_ORDER_H

#include "../time/TimeStamp.h"
#include "../time/TimeDuration.h"
#include "../location/Location.h"
#include "../users/Passenger.h"
#include "../cars/cars.h"
#include "../users/Driver.h"
#include "../payment/Payment.h"


class Passenger;
class Driver;


class Order {

    static inline size_t counter = 0;

    const size_t id;

    const TimeStamp startTime;

    const TimeStamp endTime;

    const Location startLocation;

    const Location endLocation;

    const long double distance;

    const long double cost;

    const Passenger &passenger;

    const Driver &driver;

    const Car &car;

    const Payment payment;

public:
    /* For a new order */
    Order(TimeStamp startTime, TimeStamp endTime,
          Location startLocation, Location endLocation, long double distance,
          long double cost, const Passenger &passenger, const Driver &driver, const Car &car, Payment payment);

    /* For an already existed order */
    Order(TimeStamp startTime, TimeStamp endTime,
          Location startLocation, Location endLocation, long double distance,
          long double cost, const Passenger &passenger, const Driver &driver, const Car &car,
          Payment payment, size_t id);


    TimeDuration getRideDuration();


    [[nodiscard]] size_t getId() const;

    [[nodiscard]] const TimeStamp &getStartTime() const;

    [[nodiscard]] const TimeStamp &getEndTime() const;

    [[nodiscard]] const Location &getStartLocation() const;

    [[nodiscard]] const Location &getEndLocation() const;

    [[nodiscard]] long double getDistance() const;

    [[nodiscard]] long double getCost() const;

    [[nodiscard]] const Passenger &getPassenger() const;

    [[nodiscard]] const Driver &getDriver() const;

    const Car &getCar() const;

    [[nodiscard]] Payment getPayment() const;
};


#endif //ASSIGNMENT_4_ORDER_H
