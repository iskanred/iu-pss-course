#include "Emergency.h"

#include "../io/Console.h"
#include "../io/Requests.h"


/* Private static functions */

void Emergency::runEmergency(const std::string &cause) {
    if (emergency)
        return;

    Emergency::cause = cause;
    emergency = true;

    Console::printRunEmergency(cause);
}

void Emergency::stopEmergency() {
    if (!emergency)
        return;

    Emergency::cause = std::string();
    emergency = false;

    Console::printStopEmergency();
}

void Emergency::readRequest() {
    while(true) {
        std::string request = Requests::readRequest();

        if (request.find(runEmergencyRequest) != std::string::npos)
            runEmergency(getCause(request));

        if (request.find(stopEmergencyRequest) != std::string::npos)
            stopEmergency();
    }
}

std::string Emergency::getCause(const std::string& emergencyRequest) {
    return emergencyRequest.substr(emergencyRequest.find(runEmergencyRequest) +
            runEmergencyRequest.length() + 1, emergencyRequest.length());
}


/* Public static functions */

void Emergency::listenForEmergency() {
    if (isListen)
        return;

    isListen = true;
    readThread = new std::thread(readRequest);
}



/* Getters */

bool Emergency::isEmergency() {
    return emergency;
}

const std::string &Emergency::getCause() {
    return cause;
}
