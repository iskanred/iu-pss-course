#ifndef ASSIGNMENT_2_CLASSROOM_H
#define ASSIGNMENT_2_CLASSROOM_H

#include "Room.h"


class ClassRoom : public Room {

    static const size_t FULL_MARKERS_NUMBER = 5;

    size_t capacity;

    size_t markersNumber;

public:
    /* Constructor */
    explicit ClassRoom(std::string number, short floor, size_t capacity);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;


    /* Setters */

    void updateMarkers();


    /* Getters */

    [[nodiscard]] size_t getMarkersNumber() const;
};


#endif //ASSIGNMENT_2_CLASSROOM_H
