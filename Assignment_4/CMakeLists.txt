cmake_minimum_required(VERSION 3.17)
project(Assignment_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(
#================================================
        Assignment_4
#================================================
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

        test/Test.cpp test/Test.h)