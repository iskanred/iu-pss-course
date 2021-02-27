#include "Student.h"
using namespace std;


/* Constructor */

Student::Student(string name, string surname, string tgAlias, string group, bool studyOffline, set<const Course*> courses) :
    User(move(name), move(surname), move(tgAlias), AccessLevel::GREEN),
    group(move(group)), studyOffline(studyOffline), courses(move(courses))
{
    universityEmail = generateEmailForStudent();
}


/* Public member-functions */

void Student::saySomething() const {
    cout << toString() << ": Increase a scholarship, please!" << endl;
}

string Student::toString() const {
    return "{Student} " + getFullName();
}

void Student::talkWithProfessor(const Professor& professor) const {
    cout << professor.toString() << ": See you on retake, " << name << endl;
    cout << toString() << ": Please, professor, give me C" << endl;
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
