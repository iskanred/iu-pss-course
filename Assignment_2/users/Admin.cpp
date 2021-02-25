#include "Admin.h"
using namespace std;


/* Constructor */

Admin::Admin(string name, string surname, string tgAlias, string wiFiPassword) :
    User(move(name), move(surname), move(tgAlias), AccessLevel::RED),
    wiFiPassword(move(wiFiPassword))
{ }


/* Public member-functions */

void Admin::saySomething() const {
    cout << "If it works correctly, don't touch it, please!" << endl;
}

void Admin::upAccess(User &user) {
    UserAccessUpdater::updateAccess(user);
    cout << "Admin " << getFullName()
            << " updated " << user.getFullName() << "'s access level to "
            << user.getAccessLevel().toString() << endl;
}


/* Getters */

const string &Admin::getWiFiPassword() const {
    return wiFiPassword;
}
