# Assignemnt 4

Implementation of Wendex Taxi backend

## System Requirments
The program was successfully tested on **Windows 10** with **MinGW** compiler. It should work with any other system and other compilers, but there can appear some troubles.

## Tools Requirments
**C++ 17** |
**CMake 3.17**

## Project Files
```     
       main.cpp
       
       users/User.cpp users/User.h
       users/Passenger.cpp users/Passenger.h
       users/Driver.cpp users/Driver.h

       order/Order.cpp order/Order.h
       order/PotentialOrder.cpp order/PotentialOrder.h

       time/TimeStamp.cpp time/TimeStamp.h
       time/TimeDuration.cpp time/TimeDuration.h

       location/Location.cpp location/Location.h

       payment/Payment.h

       cars/cars.h
       cars/CarType.cpp cars/CarType.h
       cars/Car.cpp cars/Car.h
       cars/EconomyCar.cpp cars/EconomyCar.h
       cars/ComfortCar.cpp cars/ComfortCar.h
       cars/ComfortPlusCar.cpp cars/ComfortPlusCar.h
       cars/BusinessCar.cpp cars/BusinessCar.h

       io/Console.cpp io/Console.h

       logic/PassengerGateway.cpp logic/PassengerGateway.h
       logic/DriverGateway.cpp logic/DriverGateway.h
       logic/System.cpp logic/System.h
       logic/DBHelper.cpp logic/DBHelper.h 
       
       test/Test.cpp test/Test.h
```

## How to Run?

Compile source files ```*.cpp``` and ```*.h``` with any **C++** compiler or if you have **Cmake** build-tool you can use it to build project. Further, it is easy to open project folder with **CLion** IDE.

## Author
**Iskander Nafikov BS20-02**

## Documentation
All necessary documentation you can find inside the source files.