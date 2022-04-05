#ifndef ASSIGNMENT_4_DRIVER_H
#define ASSIGNMENT_4_DRIVER_H

#include "User.h"
#include "../order/Order.h"

#include "../cars/cars.h"

#include <list>



class Driver : public User {

    static inline size_t counter = 0;


    std::list<const Car*> cars;

    const Car *currentCar;

    bool workingStatus;

public:
    /**
     * For a new driver
     */
    Driver(std::string name,
           std::string phoneNumber,
           std::string email,
           const Car& car);

    /**
     * For an already existed driver
     */
    Driver(std::string name,
           std::string phoneNumber,
           std::string email,
           std::vector<double> ratings,
           const std::list<const Car*> cars,
           size_t id);


    void login();


    void addNewCar(std::string model, std::string color, std::string number);

    void changeCar(const Car &car);


    [[nodiscard]] bool isInRide() const;


    std::string toString() const override;


    [[nodiscard]] const std::list<const Car*> &getCars() const;

    [[nodiscard]] bool isWorking() const;

    void setWorkingStatus(bool workingStatus);

    const Car &getCurrentCar() const;
};


#endif //ASSIGNMENT_4_DRIVER_H
