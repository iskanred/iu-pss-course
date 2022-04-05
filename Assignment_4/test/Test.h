#ifndef ASSIGNMENT_4_TEST_H
#define ASSIGNMENT_4_TEST_H

#include "../location/Location.h"
#include "../order/PotentialOrder.h"
#include "../users/Passenger.h"
#include "../users/Admin.h"

#include <string>
#include <vector>


class Admin;


class Test {

public:

    static Passenger &registerPassenger(std::string name,
                                        std::string phoneNumber,
                                        std::string email,
                                        int deviceId);

    static Driver &registerDriver(std::string name,
                               std::string phoneNumber,
                               std::string email,
                               std::string carModel,
                               std::string carColor,
                               std::string carNumber);

    static Admin &registerAdmin(std::string name,
                              std::string phoneNumber,
                              std::string email);


    static void restoreInfoFromDB();


    static const Order &getLastOrder();


    static void setWorkingStatusToDriver(Driver &driver, bool workingStatus);


    static std::vector<PotentialOrder> getPotentialRideInfo(const Passenger &passenger,
                                                            const Location &from,
                                                            const Location &to);

    static bool makeOrder(Passenger &passenger, const PotentialOrder &potentialOrder);


    static void setDefaultPaymentMethodToPassenger(Passenger &passenger, Payment paymentMethod);

    static const Car &addCarToDriver(Driver &driver, std::string carModel, std::string carColor, std::string carNumber);

    static void setCurrentCarToDriver(Driver &driver, const Car& car);


    static void blockDriverByAdmin(const Admin &admin, const Driver &driver);

    static void blockPassengerByAdmin(const Admin &admin, const Passenger &passenger);

    static void unblockDriverByAdmin(const Admin &admin, const Driver &driver);

    static void unblockPassengerByAdmin(const Admin &admin, const Passenger &passenger);


    static void seeOrdersByAdmin(const Admin &admin);

    static void seePassengersByAdmin(const Admin &admin);

    static void seeDriversByAdmin(const Admin &admin);

    static void seeBlockedPassengersByAdmin(const Admin &admin);

    static void seeBlockedDriversByAdmin(const Admin &admin);


    /* Deleting all possible ways to create an instance of this class */

    Test() = delete;

    ~Test() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    Test(const Test&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    Test& operator=(const Test&) = delete;
};


#endif //ASSIGNMENT_4_TEST_H
