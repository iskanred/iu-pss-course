cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment_2
        main.cpp

        enums/enums.h
        enums/Lab.h
        enums/AccessLevel.h
        enums/Course.h

        users/users.h
        users/User.h
        users/Student.h
        users/Professor.h
        users/LabEmployee.h
        users/Director.h
        users/Admin.h
        users/Guest.h

        rooms/rooms.h
        rooms/Room.h
        rooms/ClassRoom.h
        rooms/LectureRoom.h
        rooms/ConferenceRoom.h
        rooms/Cabinet.h
        rooms/DirectorCabinet.h

        #=====================

        enums/Lab.cpp
        enums/AccessLevel.cpp
        enums/Course.cpp

        users/User.cpp
        users/Student.cpp
        users/Professor.cpp
        users/LabEmployee.cpp
        users/Director.cpp
        users/Admin.cpp
        users/Guest.cpp

        rooms/Room.cpp
        rooms/ClassRoom.cpp
        rooms/LectureRoom.cpp
        rooms/ConferenceRoom.cpp
        rooms/Cabinet.cpp
        rooms/DirectorCabinet.cpp
        )