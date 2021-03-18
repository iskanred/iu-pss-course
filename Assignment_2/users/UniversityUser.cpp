#include "UniversityUser.h"
using namespace std;


/* Constructor */

UniversityUser::UniversityUser(string name, string surname, const AccessLevel &accessLevel, string tgAlias) :
        User(move(name), move(surname), accessLevel), tgAlias(move(tgAlias)),
        universityEmail(generateEmail())
{ }


/* Overloaded operators */

bool UniversityUser::operator==(const User &rhs) const  {
    if (this == &rhs)
        return true;

    // if instances are of different types
    if (std::type_index(typeid(*this)) != std::type_index(typeid(rhs)))
        return false;

    auto& user = (UniversityUser&)(rhs);

    return  name == rhs.getName() &&
            surname == rhs.getSurname() &&
            *accessLevel == rhs.getAccessLevel() &&
            tgAlias == user.tgAlias;
}


/* Setters */

void UniversityUser::setTgAlias(const string &tgAlias) {
    UniversityUser::tgAlias = tgAlias;
}


/* Getters */

const string &UniversityUser::getUniversityEmail() const {
    return universityEmail;
}

const string &UniversityUser::getTgAlias() const {
    return tgAlias;
}


/* Private functions */

string UniversityUser::toLowerCase(string str) {
    string strToLower = move(str);

    for (char& c : strToLower)
        c = (char) tolower(c);

    return strToLower;
}

string UniversityUser::generateEmail() const {
    string surnameLowerCase = toLowerCase(surname);

    string email = string(1, tolower(name[0])) + "."
                   + surnameLowerCase + "@innopolis.ru";

    return email;
}