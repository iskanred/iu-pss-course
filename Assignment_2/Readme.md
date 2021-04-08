# Assignemnt 2 & 3

Implementation of access-levels system at a university

## System Requirments
The program was successfully tested on **Windows 10** with **MinGW** compiler. It should work with any other system and other compilers, but there can appear some troubles.
It might not work with some versions of **MinGW** on **Windows** system due to the threads mechanism.

## Tools Requirments
**C++ 17** |
**CMake 3.17**

## Project Files
```     
        main.cpp
        CMakeLists.txt
        requests.txt


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
```

## How to Run?

Compile source files ```*.cpp``` with any **C++** compiler or if you have **Cmake** build-tool you can use it to build project. Further, it is easy to open project folder with **CLion** IDE.

## Author
**Iskander Nafikov BS20-02**

## Documentation
All necessary documentation you can find inside the source files.