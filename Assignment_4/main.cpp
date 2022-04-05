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
 * The program contains all necessary operations described in the task
 *
 * Entry point: main function below
 *
 * You always can try to run program twice or more (there is a checking if this entity is already
 *  registered in the system
 *
 * All important information you can find in Readme.md and in the documentation and comments of the code
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

    try {
        // Register admin
        auto& admin1 = Test::registerAdmin("Grigory", "+79897653412", "adminskiy@admin.en");


        // Register passenger and driver
        auto& passenger1 = Test::registerPassenger("Alexander", "+73255459809", "alex@z.ru", 0X01);
        auto& driver1 = Test::registerDriver("Boris", "+79193457393", "boryaa@b.en",
                               "Lada Granta", "White", "O9I8U7");

        // Setting some properties to them
        Test::addCarToDriver(driver1, "Subaru Impreza", "Gray", "Q5J8U0");

        Test::setCurrentCarToDriver(driver1, *driver1.getCars().back());

        Test::setDefaultPaymentMethodToPassenger(passenger1, Payment::CARD);
        Test::setWorkingStatusToDriver(driver1, true);


        // Register passenger and driver
        auto &passenger2 = Test::registerPassenger("Ivan", "+79600543347", "vanya@vanya.vn", 0X11322);
        auto &driver2 = Test::registerDriver("Ulup", "+79138457822", "ululu.u@mail.ul",
                             "Kia Rio", "Black", "N6V3K1");


        // Setting some properties to them
        Test::setCurrentCarToDriver(driver2, *driver2.getCars().back());
        Test::addCarToDriver(driver2, "Lada Kalina", "Red", "I8H6B3");
        auto &porscheCar = Test::addCarToDriver(driver2, "Porsche 911", "Gold", "N8S5P0");

        Test::setCurrentCarToDriver(driver1, porscheCar);
        Test::setDefaultPaymentMethodToPassenger(passenger2, Payment::CARD);
        Test::setWorkingStatusToDriver(driver2, true);


        // Getting conditions of the rides to passengers
        auto rideInfo1 = Test::getPotentialRideInfo(passenger1, from1, to1);
        auto rideInfo2 = Test::getPotentialRideInfo(passenger2, from2, to2);


        // Trying to make order for each car type: Economy, Comfort, ...
        Test::makeOrder(passenger1, rideInfo1[0]);
        Test::makeOrder(passenger1, rideInfo1[1]);
        Test::makeOrder(passenger1, rideInfo1[2]);
        Test::makeOrder(passenger1, rideInfo1[3]);


        // Getting this order if it was done
        auto& order1 = Test::getLastOrder();
        cout << endl;


        // Trying to make order for each car type: Economy, Comfort, ...
        Test::makeOrder(passenger2, rideInfo2[0]);
        Test::makeOrder(passenger2, rideInfo2[1]);
        Test::makeOrder(passenger2, rideInfo2[2]);
        Test::makeOrder(passenger2, rideInfo2[3]);


        // Getting this order if it was done
        auto& order2 = Test::getLastOrder();
        cout << endl;

        // Print bill of order 1
        passenger1.askForBill(order1);
        cout << endl;

        // Print bill of order 2
        passenger2.askForBill(order2);
        cout << endl;




          /* ========================================================================================== */
         /* ===================================(New Functional)======================================= */
        /* ========================================================================================== */


        // Register passenger and driver
        auto& passenger3 = Test::registerPassenger("Adrian", "+79387628189", "adad@mail.com", 0X9322);
        auto& driver3 = Test::registerDriver("Ilshat", "+79493457397", "il56at@inno.univeristy",
                                             "Cadillac", "Black", "N7Z4F1");

        Test::setDefaultPaymentMethodToPassenger(passenger1, Payment::CASH);
        Test::setWorkingStatusToDriver(driver1, true);

        // Block passenger and driver
        Test::blockPassengerByAdmin(admin1, passenger3);
        Test::blockDriverByAdmin(admin1, driver3);

        // Getting conditions of the rides to passengers
        auto rideInfo3 = Test::getPotentialRideInfo(passenger3, from1, to1);

        // Trying to make order for each car type: Economy, Comfort, ...
        Test::makeOrder(passenger3, rideInfo3[0]);
        Test::makeOrder(passenger3, rideInfo3[1]);
        Test::makeOrder(passenger3, rideInfo3[2]);
        Test::makeOrder(passenger3, rideInfo3[3]);

        // Getting this order if it was done
        auto& order3 = Test::getLastOrder();
        cout << endl;

        // Print bill of order 1
        passenger3.askForBill(order3);
        cout << endl;

        // Unblock passenger
        Test::unblockPassengerByAdmin(admin1, passenger3);

        // Trying to make order for each car type: Economy, Comfort, ...
        Test::makeOrder(passenger3, rideInfo3[0]);
        Test::makeOrder(passenger3, rideInfo3[1]);
        Test::makeOrder(passenger3, rideInfo3[2]);
        Test::makeOrder(passenger3, rideInfo3[3]);

        // Getting this order if it was done
        auto& order4 = Test::getLastOrder();
        cout << endl;

        // Print bill of order 1
        passenger3.askForBill(order4);
        cout << endl;


        // Login passenger through different devices
        passenger1.login(0X01);
        passenger2.login(0X8AFF2);
        passenger3.login(0XBF31F);

        Test::seeOrdersByAdmin(admin1);
        Test::seePassengersByAdmin(admin1);
        Test::seeDriversByAdmin(admin1);
        Test::seeBlockedPassengersByAdmin(admin1);
        Test::seeBlockedDriversByAdmin(admin1);

    } catch (const std::logic_error& le) {
        cout << le.what() << endl;
    }

    return 0;
}
