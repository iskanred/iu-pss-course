#ifndef ASSIGNMENT_4_ADMIN_H
#define ASSIGNMENT_4_ADMIN_H

#include "User.h"
#include "../test/Test.h"


class Admin : public User {


    friend class Test;


    static inline size_t counter = 0;


    void blockRideForPassenger(const Passenger &passenger) const ;

    void blockRideForDriver(const Driver &driver) const ;

    void unblockRideForPassenger(const Passenger &passenger) const ;

    void unblockRideForDriver(const Driver &driver) const;


    void seeOrders() const ;

    void seePassengers() const ;

    void seeDrivers() const ;

    void seeBlockedPassengers() const ;

    void seeBlockedDrivers() const ;

public:
    /**
     * For a new driver
     */
    Admin(std::string name,
          std::string phoneNumber,
          std::string email);

    /**
     * For an already existed driver
     */
    Admin(std::string name,
          std::string phoneNumber,
          std::string email,
          size_t id);


    void login();


    /**
     * @param car is a car to validate
     * @return {@code true} if car is validated
     *          or {@code false} if not
     */
    [[nodiscard]] bool validateCar(const Car &car) const ;


    [[nodiscard]] std::string toString() const override;
};


#endif //ASSIGNMENT_4_ADMIN_H
