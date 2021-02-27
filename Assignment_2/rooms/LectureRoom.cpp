#include "LectureRoom.h"


/* Constructor */

LectureRoom::LectureRoom(std::string number) :
        Room(std::move(number), AccessLevel::YELLOW), micCharged(true)
{ }


/* Public member-functions */

std::string LectureRoom::toString() const {
    return "({Lecture-room} #" + number + ")";
}


/* Setters */

void LectureRoom::setMicCharged(bool micCharged) {
    LectureRoom::micCharged = micCharged;
}


/* Getters */

bool LectureRoom::isMicCharged() const {
    return micCharged;
}

