#include "EmergencyTest.h"

#include "../io/Requests.h"

#include <thread>
#include <chrono>


namespace EmergencyTest {

    void testRunEmergency() {
        Requests::sendTestRequestForRunEmergency("fire");
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    void testStopEmergency() {
        Requests::sendTestRequestForStopEmergency();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}