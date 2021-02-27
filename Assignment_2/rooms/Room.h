#ifndef ASSIGNMENT_2_ROOM_H
#define ASSIGNMENT_2_ROOM_H

#include <string>
#include <vector>
#include "../users/User.h"
#include "../enums/AccessLevel.h"


class Admin;

class RoomPropertiesUpdater;


/** Abstract class Room */
class Room {

    friend class RoomPropertiesUpdater;

protected:

    std::string number;

    std::vector<const User*> grantedAccessUsers;

    AccessLevel accessLevel;


    /* Constructor */
    explicit Room(std::string number, AccessLevel accessLevel);

public:
    /* Public member-functions */

    [[nodiscard]] virtual std::string toString() const = 0; // abstract

    void openByUser(const User& user) const;

    [[nodiscard]] bool hasUserGrantedAccess(const User& user) const;


    /* Getters */

    [[nodiscard]] const std::string &getNumber() const;

    [[nodiscard]] const std::vector<const User*> &getGrantedAccessUsers() const;

    [[nodiscard]] const AccessLevel &getAccessLevel() const;

private:
    /* Private functions */

    [[nodiscard]] auto iteratorToUser(const User& user) const;
};



/**
 * RoomPropertiesUpdater class
 *
 * This class is an interface between Room-class
 *  and Admin-class
 *
 * Admin should have access to change some
 *  private properties of a room.
 *
 * So, Admin-class can be friend-class of Room
 *
 * However, Admin shouldn't be able to change its
 *  other properties (that can be added then), so
 *  this interface helps them interact saving encapsulation
 */
class RoomPropertiesUpdater {

    friend class Admin;

    static void updateAccess(Room& room, AccessLevel accessLevel);

    static void addGrantedAccessUser(Room& room, const User& user);

    /**
     * @return true - if user had been among granted access users, and was removed
     *          false - if user hadn't been among granted access users
     */
    static bool removeGrantedAccessUser(Room& room, const User& user);

public:
    RoomPropertiesUpdater() = delete;
};


#endif //ASSIGNMENT_2_ROOM_H
