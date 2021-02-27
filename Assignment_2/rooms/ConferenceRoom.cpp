#include "ConferenceRoom.h"


/* Constructor */

ConferenceRoom::ConferenceRoom(std::string number, size_t capacity) :
        Room(std::move(number), AccessLevel::GREEN),
        capacity(capacity)
{ }


/* Public member-functions */

std::string ConferenceRoom::toString() const {
    return "Conference-room (#" + number + ")";
}


/* Getters */

size_t ConferenceRoom::getCapacity() const {
    return capacity;
}

