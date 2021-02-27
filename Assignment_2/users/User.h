#ifndef ASSIGNMENT_2_USER_H
#define ASSIGNMENT_2_USER_H

#include <string>
#include <iostream>
#include "../enums/AccessLevel.h"


class Admin;

class UserAccessUpdater;


/** Abstract class User */
class User {

    friend class UserAccessUpdater;

protected:

    std::string name;

    std::string surname;

    std::string tgAlias; // telegram alias

    AccessLevel accessLevel;

    std::string universityEmail;


    /* Constructor */
    User(std::string name,
         std::string surname,
         std::string tgAlias,
         AccessLevel accessLevel);

public:
    /* Overloaded Operators */

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;


    /* Abstract member-functions */

    virtual void saySomething() const = 0;

    [[nodiscard]] virtual std::string toString() const = 0;


    /* Setters */

    void setTgAlias(const std::string &tgAlias);


    /* Getters */

    [[nodiscard]] std::string getFullName() const;

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] const std::string &getSurname() const;

    [[nodiscard]] const std::string &getTgAlias() const;

    [[nodiscard]] const std::string &getUniversityEmail() const;

    [[nodiscard]] AccessLevel getAccessLevel() const;

private:
    /* Private functions */

    [[nodiscard]] std::string generateEmail() const;

    static std::string toLowerCase(std::string str);
};



/**
 * UserAccessUpdater class
 *  is necessary to update access for some user by admin
 *
 * This class is an interface between User-class
 *  and its child: Admin-class
 *
 * Admin should have access to change user's level of access,
 *  but other children shouldn't, so this updater-function
 *  must be private and Admin can be friend-class for User-class
 *
 * However, Admin shouldn't have access to other private
 *  entities of User-class, so this interface helps them
 *  interact saving encapsulation
 */
class UserAccessUpdater {

    friend class Admin;

    static void updateAccess(User& user, AccessLevel accessLevel);

public:
    UserAccessUpdater() = delete;
};

#endif //ASSIGNMENT_2_USER_H
