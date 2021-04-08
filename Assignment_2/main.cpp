#include <iostream>
#include <set>
#define println cout << endl
using namespace std;


/**
 * ==============================================
 * Innopolis University
 * PSS-II course
 * Assignment (2 & 3)
 *
 * Student: Iskander Nafikov BS20-02
 * TA: Mike Ivanov
 * ==============================================
 * This program implements a system of access levels
 *  for users to rooms at a university
 * ==============================================
 * By default:
 * [NO_LEVEL] < [BLUE] < [GREEN] < [YELLOW] < [RED]
 *
 * Guests have [BLUE] access level
 * Students have [GREEN] access level
 * Professors have [YELLOW] access level
 * Lab employees have [YELLOW] access level
 * Admins have [RED] access level
 * Directors have [RED] access level
 *
 * Class-rooms have [GREEN] access level
 * Conference-rooms on the 1st floor have [BLUE] access level, or [GREEN] otherwise
 * Lecture-rooms on the 1st floor have [BLUE] access level, or [YELLOW] otherwise
 * Cabinets have [YELLOW] access level
 * Director-cabinets have [RED] access level
 * ==============================================
 * Admins can:
 * 1) change access level of room
 * 2) change access level of user
 * 3) grant special access for user to room
 * 4) remove granted special access for user to room
 * ==============================================
 * There are 3 "enums" (actually not enum) types:
 * 1) AccessLevel
 * 2) Lab
 * 3) Course
 * ==============================================
 * There are 5 package-files:
 * 1) emergencies.h (includes all files from "emergency"-directory)
 * 2) enums.h (includes all files from "enums"-directory)
 * 3) rooms.h (includes all files from "rooms"-directory)
 * 4) users.h (includes all files from "users"-directory)
 * 5) io.h (includes all files from "io"-directory)
 * ==============================================
 */


#include "emergency/emergencies.h"
#include "enums/enums.h"
#include "rooms/rooms.h"
#include "users/users.h"


int main()
{
    Emergency::listenForEmergency(); // new

    const string wiFiPassword = "12345678";

    /* Courses of second-semester bachelor students */
    set<const Course*> coursesSecondSemester;
    coursesSecondSemester.insert(&Course::INTRODUCTION_TO_PROGRAMMING_II);
    coursesSecondSemester.insert(&Course::DATA_STRUCTURES_AND_ALGORITHMS);
    coursesSecondSemester.insert(&Course::THEORETICAL_COMPUTER_SCIENCE);
    coursesSecondSemester.insert(&Course::DATA_STRUCTURES_AND_ALGORITHMS);
    coursesSecondSemester.insert(&Course::ENGLISH_FOR_ACADEMIC_PURPOSES_II);
    coursesSecondSemester.insert(&Course::MATH_ANALYSIS_II);


    /* Users declaration */

    Student students[16] = {
            Student("Iskander", "Nafikov", "iskanred", "BS20-02",
                    true, coursesSecondSemester),
            Student("Vsevolod", "Klyushev", "Kiaver", "BS20-02",
                    true, coursesSecondSemester),
            Student("Eduard", "Zaripov", "ipadgoose", "BS20-02",
                    true, coursesSecondSemester),
            Student("Sergey", "Golubev", "pigeon_gcc", "BS20-02",
                    true, coursesSecondSemester),
            Student("Artyom", "Chernitsa", "aalexren", "BS20-02",
                    true, coursesSecondSemester),
            Student("Dzhemilya", "Gizutdinova", "Aflesyn", "BS20-02",
                    true, coursesSecondSemester),
            Student("Artem", "Murashko", "art22m", "BS20-02",
                    true, coursesSecondSemester),
            Student("Makar", "Shevchenko", "SyrexMinus", "BS20-03",
                    true, coursesSecondSemester),
            Student("Egor", "Shalagin", "@Shalagin_Egor", "BS20-01",
                    true, coursesSecondSemester),
            Student("Alexander", "Pushkin", "poet228", "BS20-01",
                    true, coursesSecondSemester),
            Student("Anton", "Vlasov", "antoxa", "BS20-04",
                    true, coursesSecondSemester),
            Student("Vladimir", "Putin", "president", "BS20-06",
                    false, coursesSecondSemester),
            Student("Bruce", "Lee", "leeee", "BS20-05",
                    false, coursesSecondSemester),
            Student("Igor", "Iluhin", "white_hhorse", "BS20-05",
                    false, coursesSecondSemester),
            Student("Vin", "Diesel", "fastAnddFurious", "BS20-06",
                    false, coursesSecondSemester),
            Student("Oruck", "Kuza", "kuzaoruck", "BS20-04",
                    true, coursesSecondSemester)
    };

    LabEmployee employees[8] {
            LabEmployee("Ivan", "Ivanov", "ivan1", Lab::DATA_SCIENCE, "director"),
            LabEmployee("Alexander", "Alexandrov", "alex1", Lab::CYBER_SECURITY, "manager"),
            LabEmployee("Vladimir", "Vladimirov", "alex1", Lab::CYBER_SECURITY, "product manager"),
            LabEmployee("Alexey", "Alexeyev", "alex1", Lab::NETWORKS, "developer"),
            LabEmployee("Yuriy", "Yuryev", "alex1", Lab::OPERATING_SYSTEMS, "developer"),
            LabEmployee("Eugene", "Evgenyev", "alex1", Lab::ROBOTICS, "customer service worker"),
            LabEmployee("Maestro", "Maestrov", "alex1", Lab::SOFTWARE_ENGINEERING, "business analyst"),
            LabEmployee("Paris", "Parisov", "alex1", Lab::SOFTWARE_ENGINEERING, "manager")
    };

    vector<const Course*> professorCourses = {&Course::DATA_STRUCTURES_AND_ALGORITHMS,
                                              &Course::INTRODUCTION_TO_PROGRAMMING_II,
                                              &Course::THEORETICAL_COMPUTER_SCIENCE,
                                              &Course::MATH_ANALYSIS_II};

    Professor professors[4] {
        Professor("Adil", "Khan", "khan", "I love humour",
                  set<const Course*>(professorCourses.begin(), professorCourses.begin() + 1)),
        Professor("Eugene", "Zouev", "zouev", "C++!",
                  set<const Course*>(professorCourses.begin() + 1, professorCourses.begin() + 2)),
        Professor("Manuel", "Mazzara", "MMazzara", "To say that computer science is about computers"
                                                   " is similar to say that astronomy is about telescopes",
                  set<const Course*>(professorCourses.begin() + 2, professorCourses.begin() + 3)),
        Professor("Ivan", "Khonykhov", "IvanKonyukhov", "And so far, and so forth...",
                  set<const Course*>(professorCourses.end() - 1, professorCourses.end()))
    };

    Admin admins[2] {
            Admin("Nikolay", "Cake", "cake", wiFiPassword),
            Admin("Sergey", "Platonov", "platon", wiFiPassword)
    };

    Director directors[2] {
            Director("Kirill", "Semenikhin", "sema"),
            Director("Amadey", "Mozart", "ilovemusic")
    };


    /* Rooms declaration */

    ClassRoom classRoom1("301", 3, 12U);
    ClassRoom classRoom2("303", 3, 20U);

    ConferenceRoom conferenceRoom1("C-3", 1, 5);
    ConferenceRoom conferenceRoom2("C-1", 5, 4);


    LectureRoom lectureRoom1("106",1);
    LectureRoom lectureRoom2("108",1);

    Cabinet cabinet1("P-19", 2, 1U);
    Cabinet cabinet2("L-8", 4, 8U);

    println;

    DirectorCabinet directorCabinet1("D-1", 4, directors[0]);
    DirectorCabinet directorCabinet2("D-2", 4, directors[1]);


    /* Actions */

    println;

    // Check default access

    classRoom1.openByUser(students[0]);
    classRoom2.openByUser(professors[0]);
    classRoom1.openByUser(employees[0]);
    classRoom2.openByUser(directors[0]);
    classRoom1.openByUser(admins[0]);

    println;

    conferenceRoom1.openByUser(students[1]);
    conferenceRoom1.openByUser(professors[1]);
    conferenceRoom1.openByUser(employees[1]);
    conferenceRoom1.openByUser(directors[1]);
    conferenceRoom1.openByUser(admins[1]);

    println;

    lectureRoom1.openByUser(students[2]);
    lectureRoom2.openByUser(professors[2]);
    lectureRoom1.openByUser(employees[2]);
    lectureRoom2.openByUser(directors[0]);
    lectureRoom1.openByUser(admins[0]);

    println;

    cabinet1.openByUser(students[3]);
    cabinet2.openByUser(professors[3]);
    cabinet1.openByUser(employees[3]);
    cabinet2.openByUser(directors[1]);
    cabinet1.openByUser(admins[1]);

    println;

    directorCabinet1.openByUser(students[4]);
    directorCabinet2.openByUser(professors[0]);
    directorCabinet1.openByUser(employees[4]);
    directorCabinet2.openByUser(directors[0]);
    directorCabinet1.openByUser(admins[0]);

    println;


    // set lower access to room

    admins[0].setAccessLevelForRoom(lectureRoom1, AccessLevel::NO_LEVEL);

    println;

    lectureRoom1.openByUser(students[5]);
    lectureRoom1.openByUser(professors[1]);
    lectureRoom1.openByUser(employees[5]);
    lectureRoom1.openByUser(directors[1]);
    lectureRoom1.openByUser(admins[1]);

    println;


    // set upper access to student

    admins[1].setAccessLevelForUser(students[6], AccessLevel::RED);

    println;

    lectureRoom2.openByUser(students[6]);
    cabinet1.openByUser(students[6]);
    directorCabinet1.openByUser(students[6]);

    println;


    // set granted access to user for room

    admins[0].grantUserAccessToRoom(professors[2], directorCabinet2);
    admins[0].grantUserAccessToRoom(professors[3], directorCabinet2);
    admins[0].grantUserAccessToRoom(admins[0], directorCabinet1);

    println;

    directorCabinet2.openByUser(professors[3]);
    directorCabinet1.openByUser(professors[3]);
    directorCabinet2.openByUser(professors[2]);
    directorCabinet1.openByUser(professors[2]);
    directorCabinet2.openByUser(professors[1]);

    println;


    // remove granted access to user for room

    admins[1].removeGrantedAccessForUserToRoom(professors[2], directorCabinet2);
    admins[1].removeGrantedAccessForUserToRoom(professors[3], directorCabinet2);
    admins[0].removeGrantedAccessForUserToRoom(professors[0], directorCabinet2);

    println;


    // Other features

    directors[0].setCabinet(directorCabinet2);
    directors[1].setCabinet(directorCabinet1);

    println;

    directors[0].removeCabinet();
    directors[1].removeCabinet();

    println;

    directors[0].setCabinet(directorCabinet2);
    directors[1].setCabinet(directorCabinet1);

    println;

    cout << professors[0].toString() << "'s courses:" << endl;
    for (const auto& course : professors[0].getCourses())
        cout << course->toString() << endl;

    println;

    cout << students[9].toString() << "'s courses:" << endl;
    for (const auto& course : students[9].getCourses())
        cout << course->toString() << endl;

    println;

    cout << employees[0].toString() << "'s info: " << endl <<
            "Full name: " << employees[0].getFullName() << endl <<
            "Access level: " << employees[0].getAccessLevel() << endl <<
            "Telegram alias: " << employees[0].getTgAlias() << endl <<
            "University e-mail: " << employees[0].getUniversityEmail() << endl <<
            "Lab: " << employees[0].getLab().toString() << endl <<
            "Position: " << employees[0].getPosition() << endl;

    println;


    //=============================================================================
    //===============================New============================================
    //=============================================================================

    Guest guests[4] {
        Guest("Made", "Oka", "tourism"),
        Guest("Pape", "Laba", "tourism"),
        Guest("Jama", "Pera", "guide"),
        Guest("Amaren", "Dudared", "business")
    };

    conferenceRoom1.openByUser(guests[0]); // opened
    lectureRoom2.openByUser(guests[1]); // opened

    conferenceRoom1.openByUser(students[14]); // opened

    conferenceRoom2.openByUser(guests[2]); // cannot open
    conferenceRoom2.openByUser(guests[3]);  // cannot open

    conferenceRoom2.openByUser(students[15]);  // opened


    println;

    /* Before emergency */
    directorCabinet2.openByUser(guests[0]);
    directorCabinet1.openByUser(students[0]);
    directorCabinet2.openByUser(professors[2]);
    directorCabinet1.openByUser(employees[0]);
    directorCabinet1.openByUser(admins[0]);
    directorCabinet2.openByUser(directors[0]);

    println;

    // testing our system in case of emergency situation
    EmergencyTest::testRunEmergency();


    /* In time of emergency */
    directorCabinet2.openByUser(guests[0]);
    directorCabinet1.openByUser(students[0]);
    directorCabinet2.openByUser(professors[2]);
    directorCabinet1.openByUser(employees[0]);
    directorCabinet1.openByUser(admins[0]);
    directorCabinet2.openByUser(directors[0]);

    println;

    EmergencyTest::testStopEmergency();

    /* After emergency */
    directorCabinet2.openByUser(guests[0]);
    directorCabinet1.openByUser(students[0]);
    directorCabinet2.openByUser(professors[2]);
    directorCabinet1.openByUser(employees[0]);
    directorCabinet1.openByUser(admins[0]);
    directorCabinet2.openByUser(directors[0]);

    println;


    return 0;
}
