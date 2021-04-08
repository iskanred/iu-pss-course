#include "Student.h"
using namespace std;


/* Constructor */

Student::Student(string name, string surname, string tgAlias, string group, bool studyOffline, set<const Course*> courses) :
    UniversityUser(move(name), move(surname), AccessLevel::GREEN, move(tgAlias)),
    group(move(group)), studyOffline(studyOffline), courses(move(courses))
{
    universityEmail = generateEmailForStudent();
}


/* Public member-functions */

string Student::toString() const {
    return "{Student} " + getFullName();
}


/* Setters */

void Student::setGroup(const string &group) {
    Student::group = group;
}

void Student::setStudyOffline(bool studyOffline) {
    Student::studyOffline = studyOffline;
}

void Student::setCourses(const set<const Course *> &courses) {
    Student::courses = courses;
}


/* Getters */

const string &Student::getGroup() const {
    return group;
}

bool Student::isStudyOffline() const {
    return studyOffline;
}

const set<const Course *> &Student::getCourses() const {
    return courses;
}


/* Private functions */

string Student::generateEmailForStudent() const {
    string email = universityEmail;

    email.erase(email.end() - 2, email.end()); // erase 'ru' from the end of email
    email += "university"; // add university to the end of email

    return email;
}
