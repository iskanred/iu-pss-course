#ifndef ASSIGNMENT_4_LOCATION_H
#define ASSIGNMENT_4_LOCATION_H

#include <string>


class Location {

    long double x;

    long double y;

public:

    Location(long double x, long double y);


    [[nodiscard]] std::string toString() const;


    [[nodiscard]] long double getX() const;

    [[nodiscard]] long double getY() const;

    static long double distance(Location l1, Location l2);
};


#endif //ASSIGNMENT_4_LOCATION_H
