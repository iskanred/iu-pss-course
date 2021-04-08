#ifndef ASSIGNMENT_2_ADMIN_H
#define ASSIGNMENT_2_ADMIN_H

#include "UniversityUser.h"
#include "../rooms/Room.h"


class Admin : public UniversityUser {

    std::string wiFiPassword; // Admin keeps password for university Wi-Fi

public:
    /* Constructor */
    Admin(std::string name, std::string surname, std::string tgAlias, std::string wiFiPassword);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;

    void setAccessLevelForUser(User& user, const AccessLevel& accessLevel) const;

    void setAccessLevelForRoom(Room& room, const AccessLevel& accessLevel) const;

    void grantUserAccessToRoom(const User& user, Room& room) const;

    void removeGrantedAccessForUserToRoom(const User& user, Room& room) const;


    /* Setters */

    void setWiFiPassword(const std::string &wiFiPassword);


    /* Getters */

    [[nodiscard]] const std::string &getWiFiPassword() const;

};


#endif //ASSIGNMENT_2_ADMIN_H
