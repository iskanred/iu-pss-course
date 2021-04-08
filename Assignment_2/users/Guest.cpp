#include "Guest.h"

#include <typeindex>
using namespace std;

/* Constructor */

Guest::Guest(string name, string surname, string visitPurpose) :
             User(move(name), move(surname), AccessLevel::BLUE),
             visitPurpose(move(visitPurpose))
{ }


/* Overloaded operators */

bool Guest::operator==(const User &rhs) const {
    if (this == &rhs)
        return true;

    // if instances are of different types
    if (type_index(typeid(*this)) != type_index(typeid(rhs)))
        return false;

    auto& user = (Guest&)(rhs);

    return  name == rhs.getName() &&
            surname == rhs.getSurname() &&
            *accessLevel == rhs.getAccessLevel() &&
            visitPurpose == user.visitPurpose;
}


/* Public member-functions */

std::string Guest::toString() const {
    return "{Guest} " + getFullName();
}

/* Setters */

void Guest::setVisitPurpose(const std::string &visitPurpose) {
    Guest::visitPurpose = visitPurpose;
}


/* Getters */

const std::string &Guest::getVisitPurpose() const {
    return visitPurpose;
}

