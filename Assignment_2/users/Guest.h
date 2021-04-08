#ifndef ASSIGNMENT_2_GUEST_H
#define ASSIGNMENT_2_GUEST_H

#include "Director.h"


class Guest : public User {

    std::string visitPurpose;

public:
    /* Constructor */
    Guest(std::string name,
          std::string surname,
          std::string visitPurpose);


    /* Overloaded operators */

    bool operator==(const User &rhs) const override;


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;


    /* Setters */

    void setVisitPurpose(const std::string &visitPurpose);


    /* Getters */

    [[nodiscard]] const std::string &getVisitPurpose() const;
};


#endif //ASSIGNMENT_2_GUEST_H
