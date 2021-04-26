#ifndef ASSIGNMENT_4_DRIVERGATEWAY_H
#define ASSIGNMENT_4_DRIVERGATEWAY_H

#include "../users/Driver.h"

#include "../test/Test.h"

#include <list>


class System;
class DriverGatewayCarAdder;


class DriverGateway {

    friend class Test;

    friend class System;

    friend class DriverGatewayCarAdder;


    static inline std::list<Driver> drivers;

    static inline std::list<const Car*> cars;


    static const Driver &addNewDriver(std::string name, std::string phoneNumber,
                             std::string email, std::string carModel,
                             std::string carColor, std::string carNumber);

    static void addExistedDriver(std::string name,
                             std::string phoneNumber, std::string email,
                             std::vector<double> ratings, size_t id,
                             std::list<const Car*> cars);


    static const Driver *getMatchedDriver(const PotentialOrder &potentialOrder);

    static void addOrderToHistoryOfDriver(const Order &order);

    static const Driver &getDriverById(size_t id);

    static bool registerNewCar(const Driver &driver, const Car &car);

    static bool isDriverBlocked(const Driver &driver);


public:
    /* Deleting all possible ways to create an instance of this class */

    DriverGateway() = delete;

    ~DriverGateway() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    DriverGateway(const DriverGateway&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    DriverGateway& operator=(const DriverGateway&) = delete;
};



class DriverGatewayCarAdder {

    friend class Driver;

    static bool addNewCar(const Driver &driver, const Car &car);

public:
    /* Deleting all possible ways to create an instance of this class */

    DriverGatewayCarAdder() = delete;

    ~DriverGatewayCarAdder() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    DriverGatewayCarAdder(const DriverGatewayCarAdder&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    DriverGatewayCarAdder& operator=(const DriverGatewayCarAdder&) = delete;
};


#endif //ASSIGNMENT_4_DRIVERGATEWAY_H
