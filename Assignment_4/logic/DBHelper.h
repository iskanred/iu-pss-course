#ifndef ASSIGNMENT_4_DBHELPER_H
#define ASSIGNMENT_4_DBHELPER_H

#include "../users/Passenger.h"
#include "../users/Driver.h"
#include "../users/Admin.h"

#include <string>


class DBHelper {

    static inline const std::string PATH = "../data/";

    static inline const std::string ORDERS_TABLE_PATH = PATH + "orders.table";

    static inline const std::string PASSENGERS_TABLE_PATH = PATH + "passengers.table";

    static inline const std::string DRIVERS_TABLE_PATH = PATH + "drivers.table";

    static inline const std::string ADMINS_TABLE_PATH = PATH + "admins.table";

    static inline const std::string CARS_TABLE_PATH = PATH + "cars.table";

    static inline const std::string BLOCKED_PASSENGERS_TABLE_PATH = PATH + "blocked_passengers.table";

    static inline const std::string BLOCKED_DRIVERS_TABLE_PATH = PATH + "blocked_drivers.table";



    static std::list<const Car*> readCars();

    static void writeOrderToPassenger(const Order& order);

    static void writeOrderToDriver(const Order& order);

    static void writeOrderToUser(int userId, int orderId, const std::string &usersTableFilePath);

    static void writeOrderToDatumLine(int orderId, std::string &line);

    static void writeNewCarToDriver(size_t driverId, size_t carId);


    static void copyContent(const std::string &fileFrom, const std::string &fileTo);


public:

    static bool checkIfPassengerExist(const std::string& phoneNumber);

    static bool checkIfDriverExist(const std::string& phoneNumber);

    static bool checkIfAdminExist(const std::string& phoneNumber);

    static bool checkIfCarExist(const std::string& carNumber);


    static void writeNewPassenger(const Passenger& passenger);

    static void writeNewDriver(const Driver& driver);

    static void writeNewAdmin(const Admin& admin);

    static void writeNewCar(const Driver &driver, const Car &car);

    static void writeNewOrder(const Order& order);

    static void writeBlockedPassenger(const Passenger& passenger);

    static void writeBlockedDriver(const Driver &driver);

    static void writeNewDeviceToPassenger(size_t passengerId, size_t deviceId);


    static void removeBlockedPassenger(const Passenger& passenger);

    static void removeBlockedDriver(const Driver &driver);


    static void readPassengers();

    static void readDrivers();

    static void readAdmins();

    static void readBlockedPassengers();

    static void readBlockedDrivers();

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
