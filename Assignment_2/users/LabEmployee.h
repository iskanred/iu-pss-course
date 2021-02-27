#ifndef ASSIGNMENT_2_LABEMPLOYEE_H
#define ASSIGNMENT_2_LABEMPLOYEE_H

#include "User.h"
#include "Professor.h"
#include "../enums/Lab.h"


class LabEmployee : public User {

    Lab lab;

    std::string position; // должность

public:
    /* Constructor */
    LabEmployee(std::string name,
                std::string surname,
                std::string tgAlias,
                Lab lab,
                std::string position);


    /* Public member-functions */

    void saySomething() const override;

    [[nodiscard]] std::string toString() const override;

    void talkWithProfessor(const Professor& professor) const;


    /* Setters */

    void changeLab(Lab lab);

    void setPosition(const std::string &position);


    /* Getters */

    [[nodiscard]] Lab getLab() const;

    [[nodiscard]] const std::string &getPosition() const;

};

#endif //ASSIGNMENT_2_LABEMPLOYEE_H