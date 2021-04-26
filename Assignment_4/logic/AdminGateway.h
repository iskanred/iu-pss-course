#ifndef ASSIGNMENT_4_ADMINGATEWAY_H
#define ASSIGNMENT_4_ADMINGATEWAY_H

#include <list>

#include "../users/Driver.h"
#include "../users/Passenger.h"
#include "../users/Admin.h"


class AdminGatewayInterface;
class System;
class Test;


class AdminGateway {

    friend class AdminGatewayInterface;

    friend class System;

    friend class Test;


    static inline std::list<Admin> admins;


    static const Admin &addNewAdmin(std::string name, std::string phoneNumber, std::string email);


    static void addPassengerToBlockList(const Passenger& passenger);

    static void addDriverToBlockList(const Driver& driver);

    static void removePassengerFromBlockList(const Passenger& passenger);

    static void removeDriverFromBlockList(const Driver& driver);

    static bool validateCar(const Car &car);


    static std::list<const Order*> getOrders();

    static std::list<const Passenger*> getPassengers();

    static std::list<const Driver*> getDrivers();

    static std::list<const Passenger*> getBlockedPassengers();

    static std::list<const Driver*> getBlockedDrivers();


public:
    /* Deleting all possible ways to create an instance of this class */

    AdminGateway() = delete;

    ~AdminGateway() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    AdminGateway(const AdminGateway&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    AdminGateway& operator=(const AdminGateway&) = delete;
};


/**
 * Interface between Admin class and AdminGateway
 */
class AdminGatewayInterface {

    friend class Admin;


    static void addPassengerToBlockList(const Passenger& passenger);

    static void addDriverToBlockList(const Driver& driver);

    static void removePassengerFromBlockList(const Passenger& passenger);

    static void removeDriverFromBlockList(const Driver& driver);


    static std::list<const Order*> getOrders();

    static std::list<const Passenger*> getPassengers();

    static std::list<const Driver*> getDrivers();

    static std::list<const Passenger*> getBlockedPassengers();

    static std::list<const Driver*> getBlockedDrivers();


public:
    /* Deleting all possible ways to create an instance of this class */

    AdminGatewayInterface() = delete;

    ~AdminGatewayInterface() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    AdminGatewayInterface(const AdminGatewayInterface&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    AdminGatewayInterface& operator=(const AdminGatewayInterface&) = delete;
};


#endif //ASSIGNMENT_4_ADMINGATEWAY_H
