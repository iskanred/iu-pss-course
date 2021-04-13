#ifndef ASSIGNMENT_4_PASSENGERGATEWAY_H
#define ASSIGNMENT_4_PASSENGERGATEWAY_H

#include "../users/Passenger.h"
#include "../order/PotentialOrder.h"

#include "../test/Test.h"

#include <list>


class System;


class PassengerGateway {

    friend class Test;

    friend class System;

    friend class Passenger;


    static inline std::list<Passenger> passengers;


    static const Passenger &addNewPassenger(std::string name,
                                std::string phoneNumber,
                                std::string email);

    static bool makeOrder(const Passenger& passenger, const PotentialOrder& potentialOrder, Payment payment);

    static void addOrderToHistoryOfPassenger(const Order &order);

public:
    /* Deleting all possible ways to create an instance of this class */

    PassengerGateway() = delete;

    ~PassengerGateway() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    PassengerGateway(const PassengerGateway&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    PassengerGateway& operator=(const PassengerGateway&) = delete;
};


#endif //ASSIGNMENT_4_PASSENGERGATEWAY_H
