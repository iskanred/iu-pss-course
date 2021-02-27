#ifndef ASSIGNMENT_2_CABINET_H
#define ASSIGNMENT_2_CABINET_H

#include "Room.h"


class Cabinet : public Room {

    size_t computersNumber;

public:
    /* Constructor */
    explicit Cabinet(std::string number, size_t computersNumber);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;

    void addComputers(size_t computersNumber);

    void removeComputers(size_t computersNumber);


    /* Getters */

    [[nodiscard]] size_t getComputersNumber() const;
};


#endif //ASSIGNMENT_2_CABINET_H
