#ifndef ASSIGNMENT_2_ADMIN_H
#define ASSIGNMENT_2_ADMIN_H

#include "User.h"


class Admin : public User {

    std::string wiFiPassword; // Admin keeps password for university Wi-Fi

public:
    /* Constructor */
    Admin(std::string name, std::string surname, std::string tgAlias, std::string wiFiPassword);


    /* Public member-functions */

    void saySomething() const override;


    /**
     * Update access for user on 1 position
     * F.e. green becomes yellow, yellow becomes red
     */
    void upAccess(User& user);

    //void giveAccessForRoom(const User& user, const Room& room);

    //void depriveAccessForRoom();


    /* Getters */

    [[nodiscard]] const std::string &getWiFiPassword() const;

};

#endif //ASSIGNMENT_2_ADMIN_H
