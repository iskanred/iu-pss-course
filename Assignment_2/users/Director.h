#ifndef ASSIGNMENT_2_DIRECTOR_H
#define ASSIGNMENT_2_DIRECTOR_H

#include "User.h"


class Director : public User {
    /**
     * Director can often leave the university for business-trips
     * The system may need to know whether a director is at the university
     */
    bool presentAtUniversity;

public:
    /* Constructor */
    Director(std::string name,
             std::string surname,
             std::string tgAlias,
             bool presentAtUniversity);


    /* Public member-functions */

    void saySomething() const override;

    [[nodiscard]] std::string toString() const override;


    /* Setters */

    void setPresentAtUniversity(bool presentAtUniversity);


    /* Getters */

    [[nodiscard]] bool isPresentAtUniversity() const;

};


#endif //ASSIGNMENT_2_DIRECTOR_H
