#ifndef ASSIGNMENT_4_SYSTEM_H
#define ASSIGNMENT_4_SYSTEM_H

#include "../order/Order.h"

#include "../test/Test.h"

#include <vector>
#include <string>
#include <list>


class System {

    friend class Test;

    friend class AdminGateway;


    static inline std::list<Order> orders;

    static inline std::list<const Driver*> blockedDrivers;

    static inline std::list<const Passenger*> blockedPassengers;


    static std::list<const Passenger*> getPassengers();

    static std::list<const Driver*> getDrivers();


public:

    static void registerPassenger(std::string name,
                                  std::string phoneNumber,
                                  std::string email,
                                  int deviceId);

    static void registerDriver(std::string name,
                               std::string phoneNumber,
                               std::string email,
                               std::string carModel,
                               std::string carColor,
                               std::string carNumber);

    static void registerAdmin(std::string name,
                              std::string phoneNumber,
                              std::string email);

    static void registerNewDevice(const Passenger &passenger, int deviceId);


    static void restoreInfo();

    static void logInPassenger(std::string name,
                               std::string phoneNumber,
                               std::string email,
                               std::vector<double> ratings,
                               std::vector<Location> pinnedLocations,
                               std::vector<int> devicesIds,
                               Payment paymentMethod, bool inRide, size_t id);

    static void logInDriver(std::string name, std::string phoneNumber, std::string email,
                            std::vector<double> ratings, size_t id, std::list<const Car*> cars);

    static void logInAdmin(size_t id, std::string name, std::string phoneNumber, std::string email);

    static void logInBlockedPassenger(size_t id);

    static void logInBlockedDriver(size_t id);

    /**
     * Run only after 'logInDriver(args)' and 'logInPassenger(args)'
     */
    static void logInOrder(TimeStamp startTime, TimeStamp endTime,
                           Location startLocation, Location endLocation, long double distance,
                           long double cost, size_t passengerId, size_t driverId, size_t carId,
                           Payment payment, size_t id);


    /**
     * @return order instance - if the order is made successfully
     *         nullptr - if there are no available drivers now
     */
    static bool makeOrder(const Passenger &passenger, const PotentialOrder &potentialOrder, Payment payment);

    /**
     * Check car and write to database
     */
    static bool registerNewCar(const Driver &driver, const Car &car);


    static void addPassengerToBlockList(const Passenger &passenger);

    static void addDriverToBlockList(const Driver &driver);

    static bool isDriverBlocked(const Driver &driver);

    static bool isPassengerBlocked(const Passenger &passenger);

    static void removePassengerFromBlockList(const Passenger& passenger);

    static void removeDriverFromBlockList(const Driver& driver);


    /* Deleting all possible ways to create an instance of this class */

    System() = delete;

    ~System() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    System(const System&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    System& operator=(const System&) = delete;
};


#endif //ASSIGNMENT_4_SYSTEM_H
