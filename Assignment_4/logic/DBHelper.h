#ifndef ASSIGNMENT_4_DBHELPER_H
#define ASSIGNMENT_4_DBHELPER_H

#include "../users/Passenger.h"
#include "../users/Driver.h"

#include <string>


class DBHelper {

    static inline const std::string PATH = "../data/";

    static inline const std::string ORDERS_TABLE_PATH = PATH + "orders.table";

    static inline const std::string PASSENGERS_TABLE_PATH = PATH + "passengers.table";

    static inline const std::string DRIVERS_TABLE_PATH = PATH + "drivers.table";


    static void writeOrderToPassenger(const Order& order);

    static void writeOrderToDriver(const Order& order);

    static void writeOrderToUser(int userId, int orderId, const std::string &usersTableFilePath);

    static void writeOrderToDatumLine(int orderId, std::string &line);


    static void copyContent(const std::string &fileFrom, const std::string &fileTo);


public:

    static void writeNewPassenger(const Passenger& passenger);

    static void writeNewDriverAndCar(const Driver& driver);

    static void writeNewOrder(const Order& order);


    static void readPassengers();

    static void readDrivers();

    static void readOrders();


    /* Deleting all possible ways to create an instance of this class */

    DBHelper() = delete;

    ~DBHelper() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    DBHelper(const DBHelper&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    DBHelper& operator=(const DBHelper&) = delete;

};


#endif //ASSIGNMENT_4_DBHELPER_H
