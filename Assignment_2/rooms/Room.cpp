#include "Room.h"
#include <iostream>
#include <algorithm>


/* Constructor */

Room::Room(std::string number, const AccessLevel& accessLevel) :
    number(std::move(number)), accessLevel(&accessLevel)
{ }


/* Private functions */

auto Room::iteratorToUser(const User &user) const {
    auto findingFunction = [&user](const User *elem) { // lambda
        return *elem == user;
    };

    return std::find_if(grantedAccessUsers.begin(),
                        grantedAccessUsers.end(), findingFunction);
}

/* Overloaded operators */

std::ostream &operator<<(std::ostream &out, const Room &room) {
    out << room.toString();
    return out;
}


/* Public member-functions */

void Room::openByUser(const User& user) const {
    if (user.getAccessLevel() < *accessLevel &&
        !hasUserGrantedAccess(user))
    {
        std::cout << user.toString() << " cannot open the "
                    << toString() << std::endl;
        return;
    }

    std::cout << user.toString() << " opened the "
              << toString() << std::endl;
}

bool Room::hasUserGrantedAccess(const User &user) const {
    return iteratorToUser(user) != grantedAccessUsers.end();
}


/* Getters */

const std::string &Room::getNumber() const {
    return number;
}

const std::vector<const User*> &Room::getGrantedAccessUsers() const {
    return grantedAccessUsers;
}

const AccessLevel &Room::getAccessLevel() const {
    return *accessLevel;
}



/* RoomPropertiesUpdater */

void RoomPropertiesUpdater::updateAccess(Room& room, const AccessLevel& accessLevel) {
    room.accessLevel = &accessLevel;
}

void RoomPropertiesUpdater::addGrantedAccessUser(Room& room, const User &user) {
    room.grantedAccessUsers.push_back(&user);
}

bool RoomPropertiesUpdater::removeGrantedAccessUser(Room& room, const User &user) {
    auto it = room.iteratorToUser(user);

    if (it == room.grantedAccessUsers.end())
        return false;

    room.grantedAccessUsers.erase(it);
    return true;
}
