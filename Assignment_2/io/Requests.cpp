#include "Requests.h"

#include <fstream>



std::string Requests::readRequest() {

    std::ifstream requestsFin(requestsFilePath);
    std::string request;

    requestsFin >> request;

    requestsFin.close();

    return request;
}


void Requests::sendTestRequestForRunEmergency() {

    std::ofstream requestsFout(requestsFilePath);

    requestsFout << "run-emergency:fire";

    requestsFout.close();
}

void Requests::sendTestRequestForStopEmergency() {

    std::ofstream requestsFout(requestsFilePath);

    requestsFout << "stop-emergency";

    requestsFout.close();
}

