#include "Console.h"

#include <iostream>
#include <algorithm>
using namespace std;


void Console::printParkRightInFrontOfTheEntrance(const BusinessCar& car) {
    cout << "The car " << car.getModel() << " "
    << car.getNumber() << " " << car.getColor()
    << " parked right in front of the entrance" << endl;
}

void Console::printBill(const Order &order) {
    std::string payment;

    switch (order.getPayment()) {
        case Payment::CARD:
            payment = "card";
            break;
        case Payment::CASH :
            payment = "cash";
            break;
    }

    cout << "Bill of the trip #" << order.getId() << endl
    << "Passenger: " << order.getPassenger().toString() << endl
    << "Time: " << order.getStartTime().toString() << " - " << order.getEndTime().toString() << endl
    << "Locations: " << order.getStartLocation().toString() << " - " << order.getEndLocation().toString() << endl
    << "Cost: " << order.getCost() << " Rub" << endl
    << "Distance: " << order.getDistance() << " km" << endl
    << "Driver: " << order.getDriver().toString() << endl
    << "Car: " << order.getCar().toString() << endl
    << "Payment method: by " << payment << endl;
}

void Console::printNewOrder() {
    cout << "Order is made successfully!" << endl;
}

void Console::printNoFreeDrivers() {
    cout << "Sorry, no free drivers available right now" << endl;
}

void Console::printUserExist() {
    cout << "Sorry, such a user already registered in Wendex.Taxi. If it is you, you can sign in" << endl;
}

void Console::printCarExist() {
    cout << "Sorry, such a car already registered in Wendex.Taxi" << endl;
}

void Console::printPassengerBlocked() {
    cout << "Sorry, you are blocked, so you cannot order a ride now!" << endl;
}

void Console::printPassengerInRide() {
    cout << "Sorry, you cannot order a new ride during another one!" << endl;
}

void Console::printCarNotValidated() {
    cout << "Sorry, the car has been not validated by our admins" << endl;
}

void Console::printOrders(std::list<const Order *> orders) {
    cout << "=====[All Orders]=====" << endl;

    auto print = [](const Order *order) {
        cout << "Start Time: " << order->getStartTime().toString() << endl
             << "End Time: " << order->getEndTime().toString() << endl
             << "Start Location: " << order->getStartLocation().toString() << endl
             << "End Location: " << order->getEndLocation().toString() << endl
             << "Cost: " << order->getCost() << endl
             << "Distance: " << order->getDistance() << endl
             << "Passenger: " << order->getPassenger().toString() << endl
             << "Driver: " << order->getDriver().toString() << endl
             << "Car: " << order->getCar().toString() << endl << endl;
    };

    for_each(orders.begin(), orders.end(), print);
    cout << "==========================" << endl;
}

void Console::printPassengers(std::list<const Passenger *> passengers) {
    cout << "=====[All Passengers]=====" << endl;

    auto print = [](const Passenger *passenger) {
        cout << passenger->toString() << endl << endl;
    };

    for_each(passengers.begin(), passengers.end(), print);
    cout << "==========================" << endl;
}

void Console::printDrivers(std::list<const Driver *> drivers) {
    cout << "=====[All Drivers]=====" << endl;

    auto print = [](const Driver *driver) {
        cout << driver->toString() << endl << endl;
    };

    for_each(drivers.begin(), drivers.end(), print);
    cout << "==========================" << endl;
}

void Console::printBlockedPassengers(std::list<const Passenger *> blockedPassengers) {
    cout << "=====[All Blocked Passengers]=====" << endl;

    auto print = [](const Passenger *passenger) {
        cout << passenger->toString() << endl << endl;
    };

    for_each(blockedPassengers.begin(), blockedPassengers.end(), print);
    cout << "==========================" << endl;
}

void Console::printBlockedDrivers(std::list<const Driver *> blockedDrivers) {
    cout << "=====[All Blocked Drivers]=====" << endl;

    auto print = [](const Driver *driver) {
        cout << driver->toString() << endl << endl;
    };

    for_each(blockedDrivers.begin(), blockedDrivers.end(), print);
    cout << "==========================" << endl;
}


void Console::log(const std::string &log) {
    cout << endl << "{Log: " << log << "}" << endl << endl;
}
