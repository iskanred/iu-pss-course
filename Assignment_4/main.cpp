#include <iostream>
using namespace std;

#include "logic/System.h"


int main()
{
    Location from1(1, 2);
    Location to1(1, 2);
    Location from2(12, 12);
    Location to2(34, 46);


    Test::registerPassenger("Muhammad", "+79876543429", "budam.denum@mail.com");
    Test::registerDriver("Andrey", "+79198657893", "andrey@mail.com",
                           "Hyundai Solaris", "Gray", "I9O7H6");

    auto& passenger1 = Test::getLastPassenger();
    auto& driver1 = Test::getLastDriver();

    Test::setDefaultPaymentMethodToPassenger(passenger1, Payment::CARD);
    Test::setWorkingStatusToDriver(driver1, true);



    Test::registerPassenger("Abdul", "+79876543347", "humady.olu@mail.com");
    Test::registerDriver("Ulip", "+79198457893", "ulip@mail.com",
                         "Toyota Cresta", "Yellow", "I0S2D9");

    auto& passenger2 = Test::getLastPassenger();
    auto& driver2 = Test::getLastDriver();

    Test::setDefaultPaymentMethodToPassenger(passenger2, Payment::CARD);
    Test::setWorkingStatusToDriver(driver2, true);



    Test::registerPassenger("Nikam", "+79236443347", "nikam@mail.com");
    auto& passenger3 = Test::getLastPassenger();

    Test::setDefaultPaymentMethodToPassenger(passenger3, Payment::CASH);



    auto rideInfo1 = Test::getPotentialRideInfo(passenger1, from1, to1);
    auto rideInfo2 = Test::getPotentialRideInfo(passenger2, from2, to2);
    auto rideInfo3 = Test::getPotentialRideInfo(passenger2, from2, to2);

    Test::makeOrder(passenger1, rideInfo1[0]);
    Test::makeOrder(passenger1, rideInfo1[1]);
    Test::makeOrder(passenger1, rideInfo1[2]);
    Test::makeOrder(passenger1, rideInfo1[3]);

    auto& order1 = Test::getLastOrder();
    cout << endl;

    Test::makeOrder(passenger2, rideInfo2[0]);
    Test::makeOrder(passenger2, rideInfo2[1]);
    Test::makeOrder(passenger2, rideInfo2[2]);
    Test::makeOrder(passenger2, rideInfo2[3]);

    auto& order2 = Test::getLastOrder();
    cout << endl;

    Test::makeOrder(passenger3, rideInfo3[0]);
    Test::makeOrder(passenger3, rideInfo3[1]);
    Test::makeOrder(passenger3, rideInfo3[2]);
    Test::makeOrder(passenger3, rideInfo3[3]);

    cout << endl;


    passenger1.askForBill(order1);
    cout << endl;

    passenger2.askForBill(order2);
    cout << endl;



    return 0;
}
