#ifndef ASSIGNMENT_4_DBHELPER_H
#define ASSIGNMENT_4_DBHELPER_H

#include "../users/Passenger.h"
#include "../users/Driver.h"


class DBHelper {



public:

    static void writeNewPassenger(const Passenger& passenger);

    static void writeNewDriverAndCar(const Driver& passenger);


    /* Deleting all possible ways to create an instance of this class */

    DBHelper() = delete;

    ~DBHelper() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    DBHelper(const DBHelper&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    DBHelper& operator=(const DBHelper&) = delete;

};


#endif //ASSIGNMENT_4_DBHELPER_H
