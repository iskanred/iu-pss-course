cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment_2

        io/io.h
        io/Console.h
        io/Requests.h

        emergency/emergencies.h
        emergency/Emergency.h
        emergency/EmergencyTest.h

        enums/enums.h
        enums/Lab.h
        enums/AccessLevel.h
        enums/Course.h

        users/users.h
        users/User.h
        users/UniversityUser.h
        users/Guest.h
        users/Student.h
        users/Professor.h
        users/LabEmployee.h
        users/Director.h
        users/Admin.h

        rooms/rooms.h
        rooms/Room.h
        rooms/ClassRoom.h
        rooms/LectureRoom.h
        rooms/ConferenceRoom.h
        rooms/Cabinet.h
        rooms/DirectorCabinet.h

        #=====================

        main.cpp

        io/Console.cpp
        io/Requests.cpp

        emergency/Emergency.cpp
        emergency/EmergencyTest.cpp

        enums/Lab.cpp
        enums/AccessLevel.cpp
        enums/Course.cpp

        users/User.cpp
        users/UniversityUser.cpp
        users/Guest.cpp
        users/Student.cpp
        users/Professor.cpp
        users/LabEmployee.cpp
        users/Director.cpp
        users/Admin.cpp

        rooms/Room.cpp
        rooms/ClassRoom.cpp
        rooms/LectureRoom.cpp
        rooms/ConferenceRoom.cpp
        rooms/Cabinet.cpp
        rooms/DirectorCabinet.cpp
        )