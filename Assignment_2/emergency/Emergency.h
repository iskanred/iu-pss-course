#ifndef ASSIGNMENT_2_EMERGENCY_H
#define ASSIGNMENT_2_EMERGENCY_H

#include <string>
#include <thread>


/**
 * This class is an interface between emergency-sensors system
 *  and this system of access levels for rooms and users
 */
class Emergency {

    const static inline std::string runEmergencyRequest = "run-emergency";

    const static inline std::string stopEmergencyRequest = "stop-emergency";


    static inline bool emergency = false;

    static inline std::string cause = std::string();

    static inline bool isListen = false;

    static inline std::thread *readThread;


    /* Private static functions */

    static void runEmergency(const std::string& cause);

    static void stopEmergency();


    [[noreturn]] static void readRequest();

    static std::string getCause(const std::string& emergencyRequest);

public:

    /* Public static functions */

    static void listenForEmergency();


   /* Getters */

   static bool isEmergency();

   static const std::string &getCause();

public:
    /* Deleting all possible ways to create an instance of this class */

    Emergency() = delete;

    ~Emergency() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    Emergency(const Emergency&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    Emergency& operator=(const Emergency&) = delete;
};


#endif //ASSIGNMENT_2_EMERGENCY_H
