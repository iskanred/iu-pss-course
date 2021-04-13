#ifndef ASSIGNMENT_4_DRIVER_H
#define ASSIGNMENT_4_DRIVER_H

#include "User.h"
#include "../order/Order.h"

#include "../cars/cars.h"

#include <vector>



class Driver : public User {

    const Car& car;

    bool workingStatus;

public:
    /**
     * For a new passenger
     */
    Driver(std::string name,
           std::string phoneNumber,
           std::string email,
           const Car& car);

    /**
     * For an already existed passenger
     */
    Driver(std::string name,
           std::string phoneNumber,
           std::string email,
           std::vector<double> ratings,
           std::vector<const Order *> orderHistory,
           const Car& car);


    [[nodiscard]] bool isInRide() const;


    std::string toString() const override;


    [[nodiscard]] const Car &getCar() const;

    [[nodiscard]] bool isWorking() const;

    void setWorkingStatus(bool workingStatus);
};


#endif //ASSIGNMENT_4_DRIVER_H
