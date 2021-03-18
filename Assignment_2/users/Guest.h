#ifndef ASSIGNMENT_2_GUEST_H
#define ASSIGNMENT_2_GUEST_H

#include "Director.h"


class Guest : public User {



public:
    /* Constructor */
    //Guest(std::string name, std::string surname, const AccessLevel& accessLevel);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;


    /* Setters */




    /* Getters */


};


#endif //ASSIGNMENT_2_GUEST_H
