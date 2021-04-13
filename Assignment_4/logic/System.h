#ifndef ASSIGNMENT_4_SYSTEM_H
#define ASSIGNMENT_4_SYSTEM_H

#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "DBHelper.h"
#include "../order/Order.h"

#include "../test/Test.h"

#include <vector>
#include <string>
#include <list>


class System {

    friend class Test;


    static inline std::list<Order> orders;


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

    /**
     * @return order instance - if the order is made successfully
     *         nullptr - if there are no available drivers now
     */
    static bool makeOrder(const Passenger &passenger, const PotentialOrder &potentialOrder, Payment payment);


    /* Deleting all possible ways to create an instance of this class */

    System() = delete;

    ~System() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    System(const System&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    System& operator=(const System&) = delete;
};


#endif //ASSIGNMENT_4_SYSTEM_H
