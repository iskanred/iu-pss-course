#include "Location.h"

#include <cmath>
#include <sstream>


Location::Location(long double x, long double y) {
    Location::x = x;
    Location::y = y;
}


// Can be changed to output address computed by coordinates
std::string Location::toString() const {
    std::ostringstream sout;

    sout << x << " " << y;

    return sout.str();
}


long double Location::getX() const {
    return x;
}

long double Location::getY() const {
    return y;
}

long double Location::distance(Location l1, Location l2) {
    return sqrtl((l1.getX() - l2.getX()) * (l1.getX() - l2.getX()) +
                    (l1.getY() - l2.getY()) * (l1.getY() - l2.getY()));
}
