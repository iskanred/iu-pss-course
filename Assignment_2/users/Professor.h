#ifndef ASSIGNMENT_2_PROFESSOR_H
#define ASSIGNMENT_2_PROFESSOR_H

#include "User.h"
#include "../enums/Course.h"
#include <set>


class Professor : public User {

    std::string favoriteJoke;

    std::set<const Course*> courses;

public:
    /* Constructor */
    Professor(std::string name,
            std::string surname,
            std::string tgAlias,
            std::string favoriteJoke,
            std::set<const Course*> courses);


    /* Public member-functions */

    void saySomething() const override;

    [[nodiscard]] std::string toString() const override;


    /* Setters */

    void setFavoriteJoke(const std::string &favoriteJoke);

    void setCourses(const std::set<const Course*> &courses);


    /* Getters */

    [[nodiscard]] const std::string &getFavoriteJoke() const;

    [[nodiscard]] const std::set<const Course*> &getCourses() const;

};

#endif //ASSIGNMENT_2_PROFESSOR_H
