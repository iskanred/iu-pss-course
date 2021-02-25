#include "Student.h"
using namespace std;


/* Constructor */

Student::Student(string name, string surname, string tgAlias, string group, bool studyOffline) :
    User(move(name), move(surname), move(tgAlias), AccessLevel::GREEN),
    group(move(group)), studyOffline(studyOffline)
{
    universityEmail = generateEmailForStudent();
}


/* Public member-functions */

void Student::saySomething() const {
    cout << "Student " << getFullName() << ": Increase a scholarship, please!" << endl;
}

void Student::talkWithProfessor(const Professor& professor) const {
    cout << "Professor " << professor.getFullName()  << ": See you on retake, " << name << endl;
    cout << "Student " << getFullName() << ": Please, professor, give me C" << endl;
}


/* Setters */

void Student::setGroup(const string &group) {
    Student::group = group;
}

void Student::setStudyOffline(bool studyOffline) {
    Student::studyOffline = studyOffline;
}


/* Getters */

const string &Student::getGroup() const {
    return group;
}

bool Student::isStudyOffline() const {
    return studyOffline;
}


/* Private functions */

string Student::generateEmailForStudent() const {
    string email = universityEmail;

    email.erase(email.end() - 2, email.end()); // erase 'ru' from the end of email
    email += "university"; // add university to the end of email

    return email;
}
