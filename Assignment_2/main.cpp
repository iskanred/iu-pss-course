#include "enums/enums.h"
#include "rooms/rooms.h"
#include "users/users.h"

#include <iostream>
using namespace std;

/// For test

int main() {

//    set<const Course*> s;
//
//    s.insert(&Course::INTRODUCTION_TO_PROGRAMMING_I);
//    s.insert(&Course::DATA_STRUCTURES_AND_ALGORITHMS);
//
//    Professor professor("Adil", "Khan", "khan", "!", s);
//
//    Student student("Iskander", "Nafikov", "iskanred", "BS20-02", true, s);
//
//    LabEmployee labEmployee("Oleg", "Bulichev", "bulich", Lab::CYBER_SECURITY, "Product manager");
//
//
//    Admin admin("Maxim", "Indusov", "max_indus", "12345678");


    DirectorCabinet directorCabinet("A123");
    DirectorCabinet directorCabinet2("Added");

    Director director1("Abu", "Dabi", "1");

    Director director2("Kel", "Nafikov", "2", directorCabinet);

    //director1.setCabinet(directorCabinet);

    director2.setCabinet(directorCabinet2);

    cout << director2 << endl;
    cout << directorCabinet.getDirector() << endl;

    cout << director2 << endl;

    cout << directorCabinet2 << endl;


//    admin.setAccessLevelForUser(professor, AccessLevel::RED);
//
//    ClassRoom classRoom("123", 12);
//
//
//    directorCabinet.openByUser(admin);
//
//    directorCabinet.openByUser(professor);
//
//    admin.setAccessLevelForUser(professor, AccessLevel::YELLOW);
//
//    directorCabinet.openByUser(professor);
//
//    admin.grantUserAccessToRoom(student, directorCabinet);
//
//    admin.grantUserAccessToRoom(student, classRoom);
//
//    directorCabinet.openByUser(student);
//
//    classRoom.openByUser(student);
//
//    admin.removeGrantedAccessForUserToRoom(student, directorCabinet);
//
//    admin.removeGrantedAccessForUserToRoom(student, classRoom);
//
//    directorCabinet.openByUser(student);

    return 0;
}
