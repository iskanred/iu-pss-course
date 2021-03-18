#include "Professor.h"
using namespace std;


/* Constructor */

Professor::Professor(string name, string surname, string tgAlias, string favoriteJoke, set<const Course*> courses) :
    UniversityUser(move(name), move(surname), AccessLevel::YELLOW, move(tgAlias)),
    favoriteJoke(move(favoriteJoke)), courses(move(courses))
{ }


/* Public member-functions */

string Professor::toString() const {
    return "{Professor} " + getFullName();
}


/* Setters */

void Professor::setFavoriteJoke(const string &favoriteJoke) {
    Professor::favoriteJoke = favoriteJoke;
}

void Professor::setCourses(const set<const Course*> &courses) {
    Professor::courses = courses;
}


/* Getters */

const string &Professor::getFavoriteJoke() const {
    return favoriteJoke;
}

const set<const Course*> &Professor::getCourses() const {
    return courses;
}