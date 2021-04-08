#include "User.h"
using namespace std;


/* Constructor */

User::User(string name, string surname, const AccessLevel& accessLevel) :
        name(move(name)), surname(move(surname)), accessLevel(&accessLevel)
{ }


/* Overloaded Operators */

bool User::operator==(const User &rhs) const {
    return  (this == &rhs) ||
            (name == rhs.name &&
            surname == rhs.surname &&
            *accessLevel == *rhs.accessLevel);
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(ostream &out, const User &user)  {
    out << user.toString();
    return out;
}


/* Getters */

string User::getFullName() const {
    return name + " " + surname;
}

const string &User::getName() const {
    return name;
}

const string &User::getSurname() const {
    return surname;
}

const AccessLevel &User::getAccessLevel() const {
    return *accessLevel;
}


/* UserAccessUpdater-class */

void UserAccessUpdater::updateAccess(User &user, const AccessLevel& accessLevel) {
    user.accessLevel = &accessLevel;
}
