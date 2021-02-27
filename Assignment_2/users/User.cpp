#include "User.h"
#include <cctype>
using namespace std;


/* Constructor */

User::User(string name, string surname, string tgAlias, const AccessLevel& accessLevel) :
        name(move(name)), surname(move(surname)), tgAlias(move(tgAlias)),
        accessLevel(&accessLevel), universityEmail(generateEmail())
{ }


/* Overloaded Operators */

bool User::operator==(const User &rhs) const {
    return (this == &rhs) ||
            (name == rhs.name &&
            surname == rhs.surname &&
            tgAlias == rhs.tgAlias &&
            accessLevel == rhs.accessLevel);
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}


/* Setters */

void User::setTgAlias(const string &tgAlias) {
    User::tgAlias = tgAlias;
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

const string &User::getTgAlias() const {
    return tgAlias;
}

const string &User::getUniversityEmail() const {
    return universityEmail;
}

const AccessLevel &User::getAccessLevel() const {
    return *accessLevel;
}


/* Private functions */

string User::toLowerCase(string str) {
    string strToLower = move(str);

    for (char& c : strToLower)
        c = (char) tolower(c);

    return strToLower;
}

string User::generateEmail() const {
    string surnameLowerCase = toLowerCase(surname);

    string email = string(1, tolower(name[0])) + "."
                   + surnameLowerCase + "@innopolis.ru";

    return email;
}


/* UserAccessUpdater-class */

void UserAccessUpdater::updateAccess(User &user, const AccessLevel& accessLevel) {
    user.accessLevel = &accessLevel;
}
