#ifndef ASSIGNMENT_4_CARTYPE_H
#define ASSIGNMENT_4_CARTYPE_H

#include "Car.h"

#include <cstdio>
#include <string>
#include <vector>


class Car;


class CarType {

    enum class Type {
        Economy = 0, Comfort = 1,
        ComfortPlus = 2, Business = 3
    };


    const Type type;


    /** Constructor for only in-class instances  */
    explicit CarType(Type type);

public:
    // Declaring copy constructor, no move constructor will be generated implicitly
    CarType(const CarType&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    CarType& operator=(const CarType&) = delete;



    /* Constants */


    /** These constants are the only instances of this class that can exist in the program */
    static const CarType ECONOMY;
    static const CarType COMFORT;
    static const CarType COMFORT_PLUS;
    static const CarType BUSINESS;


    /* Array of pointers to the constant instances */

    static const std::vector<const CarType*> CAR_TYPES;



    bool operator==(const CarType &rhs) const;

    bool operator!=(const CarType &rhs) const;


    /* Static functions */

    static size_t getCarTypesNumber();

    static const CarType &getCarTypeById(int id);

    static const CarType &determineCarType(const std::string &carModel, const std::string &carColor,
                                           const std::string &carNumber);


    /* Member-functions */

    [[nodiscard]] const Car &getCarOfThisType(std::string carModel, std::string carColor,
                                std::string carNumber) const ;


    std::string toString() const;
};


#endif //ASSIGNMENT_4_CARTYPE_H
