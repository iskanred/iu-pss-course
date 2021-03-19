#ifndef ASSIGNMENT_2_USER_H
#define ASSIGNMENT_2_USER_H

#include <string>
#include "../enums/AccessLevel.h"


class Admin;

class UserAccessUpdater;


/** Abstract class User */
class User {

    friend class UserAccessUpdater;

protected:

    std::string name;

    std::string surname;

    const AccessLevel* accessLevel;


    /* Constructor */
    User(std::string name,
         std::string surname,
         const AccessLevel& accessLevel);

public:
    /* Overloaded Operators */

    virtual bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;

    friend std::ostream &operator<<(std::ostream &out, const User& user);


    /* Abstract member-functions */

    [[nodiscard]] virtual std::string toString() const = 0;


    /* Getters */

    [[nodiscard]] std::string getFullName() const;

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] const std::string &getSurname() const;

    [[nodiscard]] const AccessLevel &getAccessLevel() const;
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

    static void updateAccess(User& user, const AccessLevel& accessLevel);

public:
    /* Deleting all possible ways to create an instance of this class */

    UserAccessUpdater() = delete;

    ~UserAccessUpdater() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    UserAccessUpdater(const UserAccessUpdater&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    UserAccessUpdater& operator=(const UserAccessUpdater&) = delete;
};

#endif //ASSIGNMENT_2_USER_H
