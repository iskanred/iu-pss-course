#ifndef ASSIGNMENT_4_DRIVERGATEWAY_H
#define ASSIGNMENT_4_DRIVERGATEWAY_H

#include "../users/Driver.h"

#include "../test/Test.h"

#include <list>


class System;


class DriverGateway {

    friend class Test;

    friend class System;


    static inline std::list<Driver> drivers;

    static inline std::list<const Car*> cars;


    static const Driver &addNewDriver(std::string name, std::string phoneNumber,
                             std::string email, std::string carModel,
                             std::string carColor, std::string carNumber);

    static const Driver *getMatchedDriver(const PotentialOrder &potentialOrder);

    static void addOrderToHistoryOfDriver(const Order &order);


public:
    /* Deleting all possible ways to create an instance of this class */

    DriverGateway() = delete;

    ~DriverGateway() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    DriverGateway(const DriverGateway&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    DriverGateway& operator=(const DriverGateway&) = delete;
};


#endif //ASSIGNMENT_4_DRIVERGATEWAY_H
