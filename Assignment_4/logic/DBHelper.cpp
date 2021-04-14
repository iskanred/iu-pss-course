#include "DBHelper.h"

#include "System.h"

#include <fstream>
#include <sstream>

using namespace std;



void DBHelper::writeNewPassenger(const Passenger &passenger) {
    ofstream passengersTableOut(PASSENGERS_TABLE_PATH, std::ios_base::app);

    passengersTableOut << passenger.getId() << " " << passenger.toString() << " "
        << (int) passenger.getPaymentMethod() << " " << passenger.getRating() << " { ";

    string pinnedLocations;

    for (const auto& location : passenger.getPinnedLocations())
        pinnedLocations += location.toString() + " ";

    if (pinnedLocations.back() == ' ')
        pinnedLocations.erase(pinnedLocations.size() - 1);

    passengersTableOut << pinnedLocations << " }";

    passengersTableOut << " { }" << endl; // for orders

    passengersTableOut.close();
}

void DBHelper::writeNewDriverAndCar(const Driver &driver) {
    ofstream driversTableOut(DRIVERS_TABLE_PATH, std::ios_base::app);

    driversTableOut << driver.getId() << " " << driver.toString() << " "
        << driver.getRating() << " { " << driver.getCar().toString() + " }";


    driversTableOut << " { }" << endl; // for orders

    driversTableOut.close();
}

void DBHelper::writeNewOrder(const Order &order) {
    ofstream ordersTableOut(ORDERS_TABLE_PATH, std::ios_base::app);

    ordersTableOut << order.getId() << " "
        << order.getStartTime().getTimeOfStamp() << " "
        << order.getEndTime().getTimeOfStamp() << " "
        << order.getStartLocation().toString() << " "
        << order.getEndLocation().toString() << " "
        << order.getCost() << " "
        << order.getDistance() << " "
        << to_string((int) order.getPayment()) << " "
        << order.getPassenger().getId() << " "
        << order.getDriver().getId() << endl;


    writeOrderToDriver(order);
    writeOrderToPassenger(order);

    ordersTableOut.close();
}


void DBHelper::readPassengers() {
    ifstream passengersTableIn(PASSENGERS_TABLE_PATH);
    string line;

    while (getline(passengersTableIn, line)) {
        stringstream sin(line);

        size_t id; sin >> id;
        string name; sin >> name;
        string phoneNumber; sin >> phoneNumber;
        string email; sin >> email;
        int paymentId; sin >> paymentId;
        double rating; sin >> rating;

        string temp; sin >> temp; // read '{'
        long double x, y;
        vector<Location> pinnedLocations;

        while (sin >> x >> y) {
            pinnedLocations.emplace_back(x, y);
        }

        System::logInPassenger(name, phoneNumber, email, vector<double>(1, rating),
                                pinnedLocations, Payment(paymentId), id);
    }

    passengersTableIn.close();
}

void DBHelper::readDrivers() {
    ifstream driversTableIn(DRIVERS_TABLE_PATH);
    string line;

    while (getline(driversTableIn, line)) {
        stringstream sin(line);

        size_t id; sin >> id;
        string name; sin >> name;
        string phoneNumber; sin >> phoneNumber;
        string email; sin >> email;
        double rating; sin >> rating;

        string temp; sin >> temp; // read '{'
        string carType; sin >> carType;
        string carColor; sin >> carColor;
        sin >> temp; // read '['

        string carModel;
        string carModelPart;

        while (sin >> carModelPart && carModelPart != "]") {
            carModel += carModelPart + " ";
        }

        if (carModel.back() == ' ')
            carModel.erase(carModel.size() - 1);

        string carNumber; sin >> carNumber;

        System::logInDriver(name, phoneNumber, email, vector<double>(1, rating),
                            id, CarType::getCarTypeFromName(carType), carModel, carColor, carNumber);
    }

    driversTableIn.close();
}

void DBHelper::readOrders() {
    ifstream ordersTableIn(ORDERS_TABLE_PATH);
    string line;

    while (getline(ordersTableIn, line)) {
        stringstream sin(line);
        string temp;

        size_t id; sin >> id;
        time_t startTime, endTime; sin >> startTime >> endTime;
        long double x1, y1, x2, y2; sin >> x1 >> y1 >> x2 >> y2;
        long double cost; sin >> cost;
        long double distance; sin >> distance;
        int paymentId; sin >> paymentId;
        size_t passengerId; sin >> passengerId;
        size_t driverId; sin >> driverId;

        System::logInOrder(TimeStamp(startTime), TimeStamp(endTime),
                           Location(x1, y1), Location(x2, y2), distance, cost,
                           passengerId, driverId, Payment(paymentId), id);
    }

    ordersTableIn.close();
}


void DBHelper::writeOrderToPassenger(const Order &order) {
    writeOrderToUser(order.getPassenger().getId(), order.getId(), PASSENGERS_TABLE_PATH);
}

void DBHelper::writeOrderToDriver(const Order &order) {
    writeOrderToUser(order.getDriver().getId(), order.getId(), DRIVERS_TABLE_PATH);
}

void DBHelper::writeOrderToUser(int userId, int orderId, const string &usersTableFilePath) {
    const string TEMP_TABLE_FILE_PATH = PATH + "temporary.table";

    ifstream usersTableIn(usersTableFilePath);
    ofstream tempTableFileOut(TEMP_TABLE_FILE_PATH);

    string line;

    while (getline(usersTableIn, line)) {
        stringstream sin(line);

        int id;
        sin >> id;

        if (id == userId) {
            writeOrderToDatumLine(orderId, line);
        }

        tempTableFileOut << line << endl;
    }

    usersTableIn.close();
    tempTableFileOut.close();

    // Copy content of temporary table file to passengers table
    //  and remove temporary table file
    copyContent(TEMP_TABLE_FILE_PATH, usersTableFilePath);
    remove((TEMP_TABLE_FILE_PATH).c_str());
}


void DBHelper::writeOrderToDatumLine(int orderId, string &line) {
    size_t pos = line.size() - 1;
    line.insert(pos, to_string(orderId) + " ");
}


void DBHelper::copyContent(const string &fileFrom, const string &fileTo) {
    ifstream fileFromIn(fileFrom);
    ofstream fileToOut(fileTo);

    string line;

    while (getline(fileFromIn, line))
        fileToOut << line << endl;

    fileFromIn.close();
    fileToOut.close();
}
