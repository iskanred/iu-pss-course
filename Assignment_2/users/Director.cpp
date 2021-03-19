#include "Director.h"
#include "../io/Console.h"
using namespace std;


/* Constructors */

Director::Director(string name, string surname, string tgAlias)
    : UniversityUser(move(name), move(surname), AccessLevel::RED, move(tgAlias)),
        presentAtUniversity(true), cabinet(nullptr)
{ }

Director::Director(string name, string surname, string tgAlias, DirectorCabinet &cabinet)
    : UniversityUser(move(name), move(surname), AccessLevel::RED, move(tgAlias)),
        presentAtUniversity(true), cabinet(&cabinet)
{
    // if this is already another director's cabinet
    if (!DirectorSetter::setDirectorToCabinet(this, cabinet)) {
        Console::printDirectorTakeCabinetFailure(*this, cabinet);
    }
}


/* Public member-functions */

string Director::toString() const {
    return "{Director} " + getFullName();
}

void Director::removeCabinet() {
    if (cabinet == nullptr) {
        Console::printDirectorRemoveCabinetFailure(*this);
        return;
    }

    DirectorSetter::setDirectorToCabinet(nullptr, *cabinet);

    Console::printDirectorRemoveCabinetSuccess(*this, *cabinet);

    cabinet = nullptr;
}


/* Setters */

void Director::setPresentAtUniversity(bool presentAtUniversity) {
    Director::presentAtUniversity = presentAtUniversity;
}

void Director::setCabinet(DirectorCabinet& cabinet) {
    if (DirectorSetter::setDirectorToCabinet(this, cabinet))
    {
        if (Director::cabinet != nullptr)
            removeCabinet();

        Director::cabinet = &cabinet;

        Console::printDirectorTakeCabinetSuccess(*this, cabinet);

        return;
    }

    // if this is already another director's cabinet
    Console::printDirectorTakeCabinetFailure(*this, cabinet);
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