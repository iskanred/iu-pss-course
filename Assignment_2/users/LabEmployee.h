#ifndef ASSIGNMENT_2_LABEMPLOYEE_H
#define ASSIGNMENT_2_LABEMPLOYEE_H

#include "UniversityUser.h"
#include "../enums/Lab.h"


class LabEmployee : public UniversityUser {

    const Lab* lab;

    std::string position; // должность

public:
    /* Constructor */
    LabEmployee(std::string name,
                std::string surname,
                std::string tgAlias,
                const Lab& lab,
                std::string position);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;


    /* Setters */

    void changeLab(const Lab& lab);

    void setPosition(const std::string &position);


    /* Getters */

    [[nodiscard]] const Lab& getLab() const;

    [[nodiscard]] const std::string &getPosition() const;

};

#endif //ASSIGNMENT_2_LABEMPLOYEE_H
