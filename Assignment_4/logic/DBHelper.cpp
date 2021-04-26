#include "DBHelper.h"

#include "System.h"

#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


void DBHelper::writeNewPassenger(const Passenger &passenger) {
    ofstream passengersTableOut(PASSENGERS_TABLE_PATH, std::ios_base::app);

    passengersTableOut << passenger.getId() << " " << passenger.toString() << " "
        << (int) passenger.getPaymentMethod() << " " << passenger.getRating() << " { ";

    for (const auto& location : passenger.getPinnedLocations())
        passengersTableOut << location.toString() + " ";

    passengersTableOut << "} { ";

    for (const auto& deviceId : passenger.getDevicesIds())
        passengersTableOut << deviceId << " ";

    passengersTableOut << "} { }" << endl; // for orders

    passengersTableOut.close();
}

void DBHelper::writeNewCar(const Driver &driver, const Car &car) {
    ofstream carsTableOut(CARS_TABLE_PATH, std::ios_base::app);

    carsTableOut << car.getId() << " " << car.getCarType().toString() << " " << car.getColor()
            << " [ " << car.getModel() << " ] " << car.getNumber() << endl;

    carsTableOut.close();

    writeNewCarToDriver(driver.getId(), car.getId());
}

void DBHelper::writeNewDriver(const Driver &driver) {
    ofstream driversTableOut(DRIVERS_TABLE_PATH, std::ios_base::app);

    driversTableOut << driver.getId() << " " << driver.toString() << " "
        << driver.getRating() << " { ";

    auto& cars = driver.getCars();

    for (auto& car : cars) {
        driversTableOut << car->getId() << " ";
    }
    driversTableOut << "}";

    driversTableOut << " { }" << endl; // for orders

    driversTableOut.close();
}

void DBHelper::writeNewAdmin(const Admin &admin) {
    ofstream adminsTableOut(ADMINS_TABLE_PATH, std::ios_base::app);

    adminsTableOut << admin.getId() << " " << admin.toString() << endl;

    adminsTableOut.close();
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
        << order.getDriver().getId() << " "
        << order.getCar().getId() << endl;


    writeOrderToDriver(order);
    writeOrderToPassenger(order);

    ordersTableOut.close();
}

void DBHelper::writeBlockedPassenger(const Passenger &passenger) {
    ofstream tableOut(BLOCKED_PASSENGERS_TABLE_PATH, std::ios_base::app);
    tableOut << passenger.getId() << endl;
    tableOut.close();
}

void DBHelper::writeBlockedDriver(const Driver &driver) {
    ofstream tableOut(BLOCKED_DRIVERS_TABLE_PATH, std::ios_base::app);
    tableOut << driver.getId() << endl;
    tableOut.close();
}

void DBHelper::writeNewDeviceToPassenger(size_t passengerId, size_t deviceId) {
    const string TEMP_TABLE_FILE_PATH = PATH + "temporary.table";

    ifstream passengersTableIn(PASSENGERS_TABLE_PATH);
    ofstream tempTableOut(TEMP_TABLE_FILE_PATH);

    string line;

    while (getline(passengersTableIn, line)) {
        stringstream sin(line);

        int id; sin >> id;

        if (id == passengerId) {
            int counter = 0;
            size_t deviceIdPos = 0;

            for (size_t pos = 0; pos < line.size(); ++pos) { // search for position to insert new device id
                if (line[pos] == '}')
                    ++counter;
                if (counter == 2) {
                    deviceIdPos = pos;
                    break;
                }
            }

            line.insert(deviceIdPos, to_string(deviceId) + " ");
        }

        tempTableOut << line << endl;
    }

    passengersTableIn.close();
    tempTableOut.close();

    // Copy content of temporary table file to drivers' table
    //  and remove temporary table file
    copyContent(TEMP_TABLE_FILE_PATH, PASSENGERS_TABLE_PATH);
    remove((TEMP_TABLE_FILE_PATH).c_str());
}



void DBHelper::removeBlockedPassenger(const Passenger &passenger) {
    const string TEMP_TABLE_FILE_PATH = PATH + "temporary.table";

    ifstream tableIn(BLOCKED_PASSENGERS_TABLE_PATH);
    ofstream tempTableOut(TEMP_TABLE_FILE_PATH);

    string line;

    while (getline(tableIn, line)) {
        stringstream sin(line);

        int id; sin >> id;

        // Skip it
        if (id == passenger.getId())
            continue;

        tempTableOut << line << endl;
    }

    tableIn.close();
    tempTableOut.close();

    // Copy content of temporary table file to drivers' table
    //  and remove temporary table file
    copyContent(TEMP_TABLE_FILE_PATH, BLOCKED_PASSENGERS_TABLE_PATH);
    remove((TEMP_TABLE_FILE_PATH).c_str());
}

void DBHelper::removeBlockedDriver(const Driver &driver) {
    const string TEMP_TABLE_FILE_PATH = PATH + "temporary.table";

    ifstream tableIn(BLOCKED_DRIVERS_TABLE_PATH);
    ofstream tempTableOut(TEMP_TABLE_FILE_PATH);

    string line;

    while (getline(tableIn, line)) {
        stringstream sin(line);

        int id; sin >> id;

        // Skip it
        if (id == driver.getId())
            continue;

        tempTableOut << line << endl;
    }

    tableIn.close();
    tempTableOut.close();

    // Copy content of temporary table file to drivers' table
    //  and remove temporary table file
    copyContent(TEMP_TABLE_FILE_PATH, BLOCKED_DRIVERS_TABLE_PATH);
    remove((TEMP_TABLE_FILE_PATH).c_str());
}



std::list<const Car *> DBHelper::readCars() {
    list<const Car*> cars;
    ifstream carsTableIn(CARS_TABLE_PATH);
    string line;

    while (getline(carsTableIn, line)) {
        stringstream sin(line);

        size_t id; sin >> id;
        string typeName; sin >> typeName;
        string color; sin >> color;
        string temp; sin >> temp; // read '['

        string carModel;
        string carModelPart;

        while (sin >> carModelPart && carModelPart != "]") {
            carModel += carModelPart + " ";
        }

        if (carModel.back() == ' ')
            carModel.erase(carModel.size() - 1);

        string number; sin >> number;

        auto& carType = CarType::getCarTypeFromName(typeName);
        cars.emplace_back(&carType.getCarOfThisType(carModel, color, number));
    }

    carsTableIn.close();

    return cars;
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

        // Read pinned locations
        string temp; sin >> temp; // read '{'
        long double x, y;
        vector<Location> pinnedLocations;

        while (sin >> x >> y) {
            pinnedLocations.emplace_back(x, y);
        }

        // Read devices ids
        sin >> temp; // read '{'
        int deviceId;
        vector<int> devicesIds;

        // Read devices id
        while (sin >> deviceId) {
            devicesIds.emplace_back(deviceId);
        }

        System::logInPassenger(name, phoneNumber, email, vector<double>(1, rating),
                               pinnedLocations, devicesIds, Payment(paymentId), false, id);
    }

    passengersTableIn.close();
}

void DBHelper::readDrivers() {
    auto cars = readCars();

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
        size_t carId;
        list<const Car*> driverCars;

        auto matchId = [&carId](const Car* car) {
            return carId == car->getId();
        };

        while (sin >> carId) {
            driverCars.emplace_back(*find_if(cars.begin(), cars.end(), matchId));
        }

        System::logInDriver(name, phoneNumber, email, vector<double>(1, rating),
                            id, driverCars);
    }

    driversTableIn.close();
}

void DBHelper::readAdmins() {
    ifstream adminsTableIn(ADMINS_TABLE_PATH);
    string line;

    while(getline(adminsTableIn, line)) {
        stringstream sin(line);

        size_t id; sin >> id;
        string name; sin >> name;
        string phoneNumber; sin >> phoneNumber;
        string email; sin >> email;

        System::logInAdmin(id, name, phoneNumber, email);
    }
}

void DBHelper::readBlockedPassengers() {
    ifstream tableIn(BLOCKED_PASSENGERS_TABLE_PATH);
    size_t id;

    while (tableIn >> id) {
        System::logInBlockedPassenger(id);
    }

    tableIn.close();
}

void DBHelper::readBlockedDrivers() {
    ifstream tableIn(BLOCKED_DRIVERS_TABLE_PATH);
    size_t id;

    while (tableIn >> id) {
        System::logInBlockedDriver(id);
    }

    tableIn.close();
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
        size_t carId; sin >> carId;

        System::logInOrder(TimeStamp(startTime), TimeStamp(endTime),
                           Location(x1, y1), Location(x2, y2), distance, cost,
                           passengerId, driverId, carId, Payment(paymentId), id);
    }

    ordersTableIn.close();
}


bool DBHelper::checkIfPassengerExist(const string &phoneNumber) {
    ifstream passengersTableIn(PASSENGERS_TABLE_PATH);
    string line;

    while (getline(passengersTableIn, line)) {
        stringstream sin(line);
        string passengerPhoneNumber;

        sin >> passengerPhoneNumber >> passengerPhoneNumber >> passengerPhoneNumber;

        if (passengerPhoneNumber == phoneNumber) {
            passengersTableIn.close();
            return true;
        }
    }

    passengersTableIn.close();
    return false;
}

bool DBHelper::checkIfDriverExist(const string &phoneNumber) {
    ifstream driversTableIn(DRIVERS_TABLE_PATH);
    string line;

    while (getline(driversTableIn, line)) {
        stringstream sin(line);
        string driverPhoneNumber;

        sin >> driverPhoneNumber >> driverPhoneNumber >> driverPhoneNumber;

        if (driverPhoneNumber == phoneNumber) {
            driversTableIn.close();
            return true;
        }
    }

    driversTableIn.close();
    return false;
}

bool DBHelper::checkIfAdminExist(const string &phoneNumber) {
    ifstream adminsTableIn(ADMINS_TABLE_PATH);
    string line;

    while (getline(adminsTableIn, line)) {
        stringstream sin(line);
        string adminPhoneNumber;

        // id >> name >> phoneNumber
        sin >> adminPhoneNumber >> adminPhoneNumber >> adminPhoneNumber;

        if (adminPhoneNumber == phoneNumber) {
            adminsTableIn.close();
            return true;
        }
    }

    adminsTableIn.close();
    return false;
}

bool DBHelper::checkIfCarExist(const string &carNumber) {
    ifstream carsTableIn(CARS_TABLE_PATH);
    string line;

    while (getline(carsTableIn, line)) {
        stringstream sin(line);

        size_t pos = line.find_last_of(' ');
        string currentCarNumber = line.substr(pos + 1);

        if (currentCarNumber == carNumber) {
            carsTableIn.close();
            return true;
        }
    }

    carsTableIn.close();
    return false;
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

        int id; sin >> id;

        if (id == userId) {
            writeOrderToDatumLine(orderId, line);
        }

        tempTableFileOut << line << endl;
    }

    usersTableIn.close();
    tempTableFileOut.close();

    // Copy content of temporary table file to users' table
    //  and remove temporary table file
    copyContent(TEMP_TABLE_FILE_PATH, usersTableFilePath);
    remove((TEMP_TABLE_FILE_PATH).c_str());
}


void DBHelper::writeOrderToDatumLine(int orderId, string &line) {
    size_t pos = line.size() - 1;
    line.insert(pos, to_string(orderId) + " ");
}

void DBHelper::writeNewCarToDriver(size_t driverId, size_t carId) {
    const string TEMP_TABLE_FILE_PATH = PATH + "temporary.table";

    ifstream driversTableIn(DRIVERS_TABLE_PATH);
    ofstream tempTableFileOut(TEMP_TABLE_FILE_PATH);

    string line;

    while (getline(driversTableIn, line)) {
        stringstream sin(line);

        int id; sin >> id;

        if (id == driverId) {
            size_t pos = line.find('}');
            line.insert(pos - 1, " " + to_string(carId));
        }

        tempTableFileOut << line << endl;
    }

    driversTableIn.close();
    tempTableFileOut.close();

    // Copy content of temporary table file to drivers' table
    //  and remove temporary table file
    copyContent(TEMP_TABLE_FILE_PATH, DRIVERS_TABLE_PATH);
    remove((TEMP_TABLE_FILE_PATH).c_str());
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
