#ifndef ASSIGNMENT_2_REQUESTS_H
#define ASSIGNMENT_2_REQUESTS_H

#include <string>


namespace Requests {

    static inline const std::string requestsFilePath = "../requests.txt";

    std::string readRequest();


    // For Test

    void sendTestRequestForRunEmergency(const std::string& cause);

    void sendTestRequestForStopEmergency();
}


#endif //ASSIGNMENT_2_REQUESTS_H
