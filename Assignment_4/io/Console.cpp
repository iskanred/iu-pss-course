#include "Console.h"

#include <iostream>
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
    << "Car: " << order.getDriver().getCar().toString() << endl
    << "Payment method: by " << payment << endl;
}

void Console::printNewOrder() {
    cout << "Order is made successfully!" << endl;
}

void Console::printNoFreeDrivers() {
    cout << "Sorry, no free drivers available right now" << endl;
}
