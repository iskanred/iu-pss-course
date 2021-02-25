#include "Professor.h"
using namespace std;


/* Constructor */

Professor::Professor(string name, string surname, string tgAlias, string favoriteJoke, vector<string> courses) :
    User(move(name), move(surname), move(tgAlias), AccessLevel::YELLOW),
    favoriteJoke(move(favoriteJoke)), courses(move(courses))
{ }


/* Public member-functions */

void Professor::saySomething() const {
    cout << "Professor " << getFullName() << ": " << favoriteJoke << endl;
}


/* Setters */

void Professor::setFavoriteJoke(const string &favoriteJoke) {
    Professor::favoriteJoke = favoriteJoke;
}

void Professor::setCourses(const vector<std::string> &courses) {
    Professor::courses = courses;
}


/* Getters */

const string &Professor::getFavoriteJoke() const {
    return favoriteJoke;
}

const vector<std::string> &Professor::getCourses() const {
    return courses;
}
