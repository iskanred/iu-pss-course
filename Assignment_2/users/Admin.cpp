#include "Admin.h"
using namespace std;


/* Constructor */

Admin::Admin(string name, string surname, string tgAlias, string wiFiPassword) :
    User(move(name), move(surname), move(tgAlias), AccessLevel::RED),
    wiFiPassword(move(wiFiPassword))
{ }


/* Public member-functions */

void Admin::saySomething() const {
    cout << toString() << ": if it works correctly, don't touch it, please!" << endl;
}

string Admin::toString() const {
    return "Admin " + getFullName();
}

void Admin::setAccessLevelForUser(User &user, const AccessLevel& accessLevel) const {
    UserAccessUpdater::updateAccess(user, accessLevel);

    cout << toString() << " has updated " << user.toString()
            << "'s access level to " << accessLevel.toString() << endl;
}

void Admin::setAccessLevelForRoom(Room &room, const AccessLevel& accessLevel) const {
    RoomPropertiesUpdater::updateAccess(room, accessLevel);

    cout << toString() << " has updated access level of " << room.toString()
        << " to " << accessLevel.toString() << endl;
}

void Admin::grantUserAccessToRoom(const User &user, Room &room) const {
    if (user.getAccessLevel() >= room.getAccessLevel() ||
            room.hasUserGrantedAccess(user))
    {
        cout << toString() << " has tried to grant access for "
            << user.toString() << " to " << room.toString()
            << ", but " << user.toString()
            << " has already had access to this room" << endl;

        return;
    }

    RoomPropertiesUpdater::addGrantedAccessUser(room, user);

    cout << toString() << " has granted for " << user.toString()
         << " access to " << room.toString() << endl;
}

void Admin::removeGrantedAccessForUserToRoom(const User &user, Room &room) const {
    // if user hadn't been among granted access users
    if (!RoomPropertiesUpdater::removeGrantedAccessUser(room, user))
    {
        cout << toString() << " has tried to remove granted access for "
             << user.toString() << " to " << room.toString()
             << ", but " << user.toString()
             << " hasn't had a granted access to this room" << endl;

        return;
    }

    cout << toString() << " has removed granted access for " << user.toString()
         << " to " << room.toString() << endl;
}


/* Setters */

void Admin::setWiFiPassword(const string &wiFiPassword) {
    Admin::wiFiPassword = wiFiPassword;
}


/* Getters */

const string &Admin::getWiFiPassword() const {
    return wiFiPassword;
}
