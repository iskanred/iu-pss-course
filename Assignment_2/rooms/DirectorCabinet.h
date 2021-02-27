#ifndef ASSIGNMENT_2_DIRECTORCABINET_H
#define ASSIGNMENT_2_DIRECTORCABINET_H

#include "Cabinet.h"


class DirectorCabinet : public Room {

public:
    /* Constructor */
    explicit DirectorCabinet(std::string number);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;
};


#endif //ASSIGNMENT_2_DIRECTORCABINET_H
