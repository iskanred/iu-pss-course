#ifndef ASSIGNMENT_4_CONSOLE_H
#define ASSIGNMENT_4_CONSOLE_H

#include "../cars/BusinessCar.h"
#include "../order/Order.h"


namespace Console {

    void printParkRightInFrontOfTheEntrance(const BusinessCar& car);

    void printBill(const Order &order);

    void printNewOrder();

    void printNoFreeDrivers();
}


#endif //ASSIGNMENT_4_CONSOLE_H
