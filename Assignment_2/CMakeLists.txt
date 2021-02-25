cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment_2
        main.cpp

        enums/Lab.h
        enums/AccessLevel.h
        users/User.h
        users/Student.h
        users/Professor.h
        users/LabEmployee.h
        users/Director.h
        users/Admin.h

        enums/Lab.cpp
        enums/AccessLevel.cpp
        users/User.cpp
        users/Student.cpp
        users/Professor.cpp
        users/LabEmployee.cpp
        users/Director.cpp
        users/Admin.cpp
        )