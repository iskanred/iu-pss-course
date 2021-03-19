#include "ClassRoom.h"


/* Constructor */

ClassRoom::ClassRoom(std::string number, short floor, size_t capacity) :
    Room(std::move(number), floor, AccessLevel::GREEN),
    capacity(capacity), markersNumber(FULL_MARKERS_NUMBER)
{ }


/* Public member-functions */

std::string ClassRoom::toString() const {
    return "({Class-room} #" + number + ")";
}


/* Setters */

void ClassRoom::updateMarkers() {
    ClassRoom::markersNumber = FULL_MARKERS_NUMBER;
}


/* Getters */

size_t ClassRoom::getMarkersNumber() const {
    return markersNumber;
}
