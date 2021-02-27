#include "Director.h"
using namespace std;


/* Constructors */

Director::Director(string name, string surname, string tgAlias)
    : User(move(name), move(surname), move(tgAlias), AccessLevel::RED),
        presentAtUniversity(true), cabinet(nullptr)
{ }

Director::Director(string name, string surname, string tgAlias, DirectorCabinet &cabinet)
    : User(move(name), move(surname), move(tgAlias), AccessLevel::RED),
        presentAtUniversity(true), cabinet(&cabinet)
{
    // if this is already another director's cabinet
    if (!DirectorSetter::setDirectorToCabinet(this, cabinet))
    {
        cout << "Director " << getFullName()
                << " has tried to take " << cabinet.toString()
                << ", but this cabinet is already taken by "
                << cabinet.getDirector()->toString() << endl;
    }
}


/* Public member-functions */

void Director::saySomething() const {
    cout << toString() << ": We need to decrease a scholarship for students!" << endl;
}

string Director::toString() const {
    return "{Director} " + getFullName();
}

void Director::removeCabinet() {
    DirectorSetter::setDirectorToCabinet(nullptr, *cabinet);

    cout << cabinet->toString() << " is not "
            << toString() << "'s cabinet more" << endl;

    cabinet = nullptr;
}


/* Setters */

void Director::setPresentAtUniversity(bool presentAtUniversity) {
    Director::presentAtUniversity = presentAtUniversity;
}

void Director::setCabinet(DirectorCabinet& cabinet) {
    if (DirectorSetter::setDirectorToCabinet(this, cabinet))
    {
        removeCabinet();

        Director::cabinet = &cabinet;

        cout << toString()
             << " has taken " << cabinet.toString() << endl;

        return;
    }

    // if this is already another director's cabinet
    cout << toString()
            << " has tried to take " << cabinet.toString()
            << ", but this cabinet is already taken by "
            << cabinet.getDirector()->toString() << endl;
}


/* Getters */

bool Director::isPresentAtUniversity() const {
    return presentAtUniversity;
}

/**
 * (Nullable)!
 *
 * @return - pointer to a director's cabinet;
 *         - 'nullptr' if it is no director's cabinet
 *                  associated to this director yet
 */
const DirectorCabinet *Director::getCabinet() const {
    return cabinet; // can return nullptr
}