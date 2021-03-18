#ifndef ASSIGNMENT_2_UNIVERSITYUSER_H
#define ASSIGNMENT_2_UNIVERSITYUSER_H


#include "User.h"
#include <string>
#include <cctype>
#include "typeindex"


class UniversityUser : public User {

protected:

    std::string universityEmail;

    std::string tgAlias; // telegram alias

    /* Constructor */
    UniversityUser(std::string name,
                   std::string surname,
                   const AccessLevel& accessLevel,
                   std::string tgAlias);

public:
    /* Overloaded operators */

    bool operator==(const User &rhs) const override;


    /* Setters */

    void setTgAlias(const std::string &tgAlias);


    /* Getters */

    [[nodiscard]] const std::string &getUniversityEmail() const;

    [[nodiscard]] const std::string &getTgAlias() const;


private:
    /* Private functions */

    [[nodiscard]] std::string generateEmail() const;

    static std::string toLowerCase(std::string str);
};


#endif //ASSIGNMENT_2_UNIVERSITYUSER_H
