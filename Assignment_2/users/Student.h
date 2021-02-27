#ifndef ASSIGNMENT_2_STUDENT_H
#define ASSIGNMENT_2_STUDENT_H

#include "User.h"
#include "Professor.h"
#include <set>


class Student : public User {

    std::string group;

    bool studyOffline;

    std::set<const Course*> courses;

public:
    /* Constructor */
    Student(std::string name,
            std::string surname,
            std::string tgAlias,
            std::string group,
            bool studyOffline,
            std::set<const Course*> courses);


    /* Public member-functions */

    void saySomething() const override;

    [[nodiscard]] std::string toString() const override;

    void talkWithProfessor(const Professor& professor) const;


    /* Setters */

    void setGroup(const std::string &group);

    void setStudyOffline(bool studyOffline);

    void setCourses(const std::set<const Course *> &courses);


    /* Getters */

    [[nodiscard]] const std::string &getGroup() const;

    [[nodiscard]] bool isStudyOffline() const;

    [[nodiscard]] const std::set<const Course *> &getCourses() const;

private:
   /* Private functions */

   /**
    * Students have 'n.surname@innopolis.university'
    *   instead of standard 'n.surname@innopolis.ru'
    * So, this function return correct email-s for students
    *
    * @return email for students
    */
    [[nodiscard]] std::string generateEmailForStudent() const;
};

#endif //ASSIGNMENT_2_STUDENT_H
