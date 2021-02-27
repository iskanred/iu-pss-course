#include "Director.h"
using namespace std;


/* Constructor */

Director::Director(string name, string surname, string tgAlias, bool presentAtUniversity)
    : User(move(name), move(surname), move(tgAlias), AccessLevel::RED),
        presentAtUniversity(presentAtUniversity)
{ }


/* Public member-functions */

void Director::saySomething() const {
    cout << toString() << ": We need to decrease a scholarship for students!" << endl;
}

string Director::toString() const {
    return "Director " + getFullName();
}


/* Setters */

void Director::setPresentAtUniversity(bool presentAtUniversity) {
    Director::presentAtUniversity = presentAtUniversity;
}


/* Getters */

bool Director::isPresentAtUniversity() const {
    return presentAtUniversity;
}
