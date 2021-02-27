#include "DirectorCabinet.h"


/* Constructor */

DirectorCabinet::DirectorCabinet(std::string number) :
        Room(std::move(number), AccessLevel::RED)
{ }


/* Public member-functions */

std::string DirectorCabinet::toString() const {
    return "Director cabinet (#" + number +")";
}
