#include "enums/enums.h"
#include "users/users.h"
#include "rooms/rooms.h"

#include <iostream>
using namespace std;

/// For test

int main() {

    set<const Course*> s;

    s.insert(&Course::INTRODUCTION_TO_PROGRAMMING_I);
    s.insert(&Course::DATA_STRUCTURES_AND_ALGORITHMS);

    Professor professor("Adil", "Khan", "khan", "!", s);

    Student student("Iskander", "Nafikov", "iskanred", "BS20-02", true, s);

    LabEmployee labEmployee("Oleg", "Bulichev", "bulich", Lab::CYBER_SECURITY, "Product manager");


    Admin admin("Maxim", "Indusov", "max_indus", "12345678");


    DirectorCabinet directorCabinet("A123");

    Director director1("1", "1", "1");

    Director director2("2", "2", "2", directorCabinet);


    director1.setCabinet(directorCabinet);

    cout << director2.getCabinet()->getDirector()->toString() << endl;

    cout << directorCabinet.getDirector()->toString() << endl;


    admin.setAccessLevelForUser(professor, AccessLevel::RED);

    ClassRoom classRoom("123", 12);


    directorCabinet.openByUser(admin);

    directorCabinet.openByUser(professor);

    admin.setAccessLevelForUser(professor, AccessLevel::YELLOW);

    directorCabinet.openByUser(professor);

    admin.grantUserAccessToRoom(student, directorCabinet);

    admin.grantUserAccessToRoom(student, classRoom);

    directorCabinet.openByUser(student);

    classRoom.openByUser(student);

    admin.removeGrantedAccessForUserToRoom(student, directorCabinet);

    admin.removeGrantedAccessForUserToRoom(student, classRoom);

    directorCabinet.openByUser(student);

    return 0;
}
