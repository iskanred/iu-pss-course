#ifndef ASSIGNMENT_2_CONFERENCEROOM_H
#define ASSIGNMENT_2_CONFERENCEROOM_H

#include "Room.h"


class ConferenceRoom : public Room {

    size_t capacity;

public:
    /* Constructor */
    explicit ConferenceRoom(std::string number, short floor, size_t capacity);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;


    /* Getters */

    [[nodiscard]] size_t getCapacity() const;
};


#endif //ASSIGNMENT_2_CONFERENCEROOM_H
