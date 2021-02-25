#ifndef ASSIGNMENT_2_USER_H
#define ASSIGNMENT_2_USER_H

#include <string>
#include <iostream> // is necessary for f.e. method saySomething()
#include "../enums/AccessLevel.h"


class Admin;

class UserAccessUpdater;


/**
 * Abstract class User
 */
class User {

    friend class UserAccessUpdater;

protected:

    std::string name;

    std::string surname;

    std::string tgAlias; // telegram alias

    std::string universityEmail;

    AccessLevel accessLevel;


    /* Constructor */
    User(std::string name,
         std::string surname,
         std::string tgAlias,
         AccessLevel accessLevel);

public:
    /* Abstract member-functions */

    virtual void saySomething() const = 0;


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
 * This class is an interface between User-class and its child: Admin-class
 *
 * Admin should have access to change user's level of access, but other children shouldn't,
 *  so this updater-function must be private and Admin can be friend-class for User-class
 * At the same time Admin shouldn't have access to other private entities of User-class, so
 *  interface representing by UserAccessUpdater-class can solve this problem
 */
class UserAccessUpdater {

    friend class Admin;

    static void updateAccess(User& user);
};

#endif //ASSIGNMENT_2_USER_H
