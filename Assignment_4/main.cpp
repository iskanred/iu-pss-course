#include <iostream>
using namespace std;

#include "test/Test.h"


/**
 * Wendex Taxi backend
 * ===============================
 * Student: Iskander Nafikov
 * Group: BS20-02
 * TA: Mike Ivanov
 * ===============================
 *
 * Database files already had some information about passengers, drivers and previous rides.
 * So, the this information will be restored in this 'main' function.
 * Also, 'main' will test some functional and add new information.
 * Thus, the information will be changed.
 *
 * Do not run this code multiple times because it can lead to users with the same information!
 * The system does not provide checking information on uniqueness
 *
 * If you want to run this code multiple times, it is better to change users' information (names, etc.)
 *  to avoid confusions
 *
 */


int main()
{
    srand(time(nullptr));

    Test::restoreInfoFromDB(); // restoring already existed info from database

    // Forming 4 locations
    Location from1(1, 2);
    Location to1(1, 2);
    Location from2(12, 12);
    Location to2(34, 46);

    // Register passenger and driver
    Test::registerPassenger("Alexander", "+73255459809", "alex@z.ru");
    Test::registerDriver("Boris", "+79193457393", "boryaa@b.en",
                           "Lada Granta", "White", "O9I8U7");

    // Getting these passenger and driver
    auto& passenger1 = Test::getLastPassenger();
    auto& driver1 = Test::getLastDriver();

    Test::setDefaultPaymentMethodToPassenger(passenger1, Payment::CARD);
    Test::setWorkingStatusToDriver(driver1, true);


    // Register passenger and driver
    Test::registerPassenger("Ivan", "+79600543347", "vanya@vanya.vn");
    Test::registerDriver("Ulup", "+79138457822", "ululu.u@mail.ul",
                         "Kia Rio", "Black", "N6V3K1");

    // Getting these passenger and driver
    auto& passenger2 = Test::getLastPassenger();
    auto& driver2 = Test::getLastDriver();

    Test::setDefaultPaymentMethodToPassenger(passenger2, Payment::CARD);
    Test::setWorkingStatusToDriver(driver2, true);


    // Getting conditions of the rides to passengers
    auto rideInfo1 = Test::getPotentialRideInfo(passenger1, from1, to1);
    auto rideInfo2 = Test::getPotentialRideInfo(passenger2, from2, to2);

    // Trying to make order for each car type: Economy, Comfort, ...
    if (Test::makeOrder(passenger1, rideInfo1[0]))
        ;
    else if (Test::makeOrder(passenger1, rideInfo1[1]))
        ;
    else if(Test::makeOrder(passenger1, rideInfo1[2]))
        ;
    else if(Test::makeOrder(passenger1, rideInfo1[3]))
        ;
    else
        ; // no drivers available


    // Getting this order if it was done
    auto& order1 = Test::getLastOrder();
    cout << endl;


    // Trying to make order for each car type: Economy, Comfort, ...
    if (Test::makeOrder(passenger2, rideInfo2[0]))
        ;
    else if (Test::makeOrder(passenger2, rideInfo2[1]))
        ;
    else if(Test::makeOrder(passenger2, rideInfo2[2]))
        ;
    else if(Test::makeOrder(passenger2, rideInfo2[3]))
        ;
    else
        ; // no drivers available


    // Getting this order if it was done
    auto& order2 = Test::getLastOrder();
    cout << endl;

    // Print bill of order 1
    passenger1.askForBill(order1);
    cout << endl;

    // Print bill of order 2
    passenger2.askForBill(order2);
    cout << endl;

    return 0;
}
