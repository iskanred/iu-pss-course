#ifndef ASSIGNMENT_2_LECTUREROOM_H
#define ASSIGNMENT_2_LECTUREROOM_H

#include "Room.h"


class LectureRoom : public Room {

    bool micCharged;

public:
    /* Constructor */
    explicit LectureRoom(std::string number, short floor);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;


    /* Setters */

    void setMicCharged(bool micCharged);


    /* Getters */

    [[nodiscard]] bool isMicCharged() const;
};


#endif //ASSIGNMENT_2_LECTUREROOM_H
