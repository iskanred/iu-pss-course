#include "LabEmployee.h"
using namespace std;


/* Constructor */

LabEmployee::LabEmployee(string name, string surname, string tgAlias, Lab lab, string position) :
    User(move(name), move(surname), move(tgAlias), AccessLevel::YELLOW),
    lab(lab), position(move(position))
{ }


/* Public member-functions */

void LabEmployee::saySomething() const {
    cout << "Lab employee: " << getFullName() << ": Our lab is the best one at university" << endl;
}

void LabEmployee::talkWithProfessor(const Professor& professor) const {
    professor.saySomething();
    cout << "Lab employee " << getFullName() << ": Ha-ha-ha" << endl;
}


/* Setters */

void LabEmployee::changeLab(Lab lab) {
    LabEmployee::lab = lab;
}

void LabEmployee::setPosition(const string &position) {
    LabEmployee::position = position;
}


/* Getters */

Lab LabEmployee::getLab() const {
    return lab;
}

const string &LabEmployee::getPosition() const {
    return position;
}
