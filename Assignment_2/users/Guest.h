#ifndef ASSIGNMENT_2_GUEST_H
#define ASSIGNMENT_2_GUEST_H

#include "Director.h"


class Guest : User {



public:
    /* Constructor */
    Guest();


    /* Public member-functions */

    void saySomething() const override;

    [[nodiscard]] std::string toString() const override;


    /* Setters */




    /* Getters */


};


#endif //ASSIGNMENT_2_GUEST_H
