#include "Admin.h"
#include "../io/Console.h"

using namespace std;


/* Constructor */

Admin::Admin(string name, string surname, string tgAlias, string wiFiPassword) :
    UniversityUser(move(name), move(surname), AccessLevel::RED, move(tgAlias)),
    wiFiPassword(move(wiFiPassword))
{ }


/* Public member-functions */

string Admin::toString() const {
    return "{Admin} " + getFullName();
}

void Admin::setAccessLevelForUser(User &user, const AccessLevel& accessLevel) const {
    UserAccessUpdater::updateAccess(user, accessLevel);

    Console::printAdminSetAccessLevelForUser(*this, user, accessLevel);
}

void Admin::setAccessLevelForRoom(Room &room, const AccessLevel& accessLevel) const {
    RoomPropertiesUpdater::updateAccess(room, accessLevel);

    Console::printAdminSetAccessLevelForRoom(*this, room, accessLevel);
}

void Admin::grantUserAccessToRoom(const User &user, Room &room) const {
    if (user.getAccessLevel() >= room.getAccessLevel() ||
            room.hasUserGrantedAccess(user))
    {
        Console::printAdminGrantUserAccessToRoomSuccess(*this, user, room);
        return;
    }

    RoomPropertiesUpdater::addGrantedAccessUser(room, user);

    Console::printAdminGrantUserAccessToRoomFailure(*this, user, room);
}

void Admin::removeGrantedAccessForUserToRoom(const User &user, Room &room) const {
    // if user hadn't been among granted access users
    if (!RoomPropertiesUpdater::removeGrantedAccessUser(room, user))
    {
        Console::printAdminRemoveGrantedAccessForUserToRoomFailure(*this, user, room);

        return;
    }

    Console::printAdminRemoveGrantedAccessForUserToRoomSuccess(*this, user, room);
}


/* Setters */

void Admin::setWiFiPassword(const string &wiFiPassword) {
    Admin::wiFiPassword = wiFiPassword;
}


/* Getters */

const string &Admin::getWiFiPassword() const {
    return wiFiPassword;
}
