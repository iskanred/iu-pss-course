#include "LabEmployee.h"
using namespace std;


/* Constructor */

LabEmployee::LabEmployee(string name, string surname, string tgAlias, const Lab& lab, string position) :
    UniversityUser(move(name), move(surname), AccessLevel::YELLOW, move(tgAlias)),
    lab(&lab), position(move(position))
{ }


/* Public member-functions */

string LabEmployee::toString() const {
    return "{Lab employee} " + getFullName();
}

/* Setters */

void LabEmployee::changeLab(const Lab& lab) {
    LabEmployee::lab = &lab;
}

void LabEmployee::setPosition(const string &position) {
    LabEmployee::position = position;
}


/* Getters */

const Lab &LabEmployee::getLab() const {
    return *lab;
}

const string &LabEmployee::getPosition() const {
    return position;
}