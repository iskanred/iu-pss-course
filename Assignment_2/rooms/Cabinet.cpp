#include "Cabinet.h"


/* Constructor */

Cabinet::Cabinet(std::string number, size_t computersNumber) :
        Room(std::move(number), AccessLevel::YELLOW),
        computersNumber(computersNumber)
{ }


/* Public member-functions */

std::string Cabinet::toString() const {
    return "({Cabinet} #" + number + ")";
}

void Cabinet::addComputers(size_t computersNumber) {
    Cabinet::computersNumber += computersNumber;
}

void Cabinet::removeComputers(size_t computersNumber) {
    if (computersNumber == 0)
        Cabinet::computersNumber -= computersNumber;
}


/* Getters */

size_t Cabinet::getComputersNumber() const {
    return computersNumber;
}
