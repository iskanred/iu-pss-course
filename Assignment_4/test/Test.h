#ifndef ASSIGNMENT_4_TEST_H
#define ASSIGNMENT_4_TEST_H

#include "../location/Location.h"
#include "../order/PotentialOrder.h"
#include "../users/Passenger.h"

#include <string>
#include <vector>


class Test {

public:

    static void registerPassenger(std::string name,
                                  std::string phoneNumber,
                                  std::string email);

    static void registerDriver(std::string name,
                               std::string phoneNumber,
                               std::string email,
                               std::string carModel,
                               std::string carColor,
                               std::string carNumber);


    static void restoreInfoFromDB();


    static Passenger &getLastPassenger();

    static Driver &getLastDriver();

    static const Order &getLastOrder();


    static void setWorkingStatusToDriver(Driver &driver, bool workingStatus);


    static std::vector<PotentialOrder> getPotentialRideInfo(const Passenger &passenger,
                                                            const Location &from,
                                                            const Location &to);

    static bool makeOrder(Passenger &passenger, const PotentialOrder &potentialOrder);


    static void setDefaultPaymentMethodToPassenger(Passenger &passenger, Payment paymentMethod);


    /* Deleting all possible ways to create an instance of this class */

    Test() = delete;

    ~Test() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    Test(const Test&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    Test& operator=(const Test&) = delete;
};


#endif //ASSIGNMENT_4_TEST_H
