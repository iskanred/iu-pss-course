#ifndef ASSIGNMENT_4_CONSOLE_H
#define ASSIGNMENT_4_CONSOLE_H

#include "../cars/BusinessCar.h"
#include "../order/Order.h"


namespace Console {

    void printParkRightInFrontOfTheEntrance(const BusinessCar& car);

    void printBill(const Order &order);

    void printNewOrder();

    void printNoFreeDrivers();

    void printUserExist();

    void printCarExist();

    void printPassengerBlocked();

    void printPassengerInRide();

    void printCarNotValidated();


    void printOrders(std::list<const Order *> orders);

    void printPassengers(std::list<const Passenger *> passengers);

    void printDrivers(std::list<const Driver *> drivers);

    void printBlockedPassengers(std::list<const Passenger *> blockedPassengers);

    void printBlockedDrivers(std::list<const Driver *> blockedDrivers);


    void log(const std::string &log);
}


#endif //ASSIGNMENT_4_CONSOLE_H
