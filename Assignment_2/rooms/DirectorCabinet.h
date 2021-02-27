#ifndef ASSIGNMENT_2_DIRECTORCABINET_H
#define ASSIGNMENT_2_DIRECTORCABINET_H

#include "Room.h"
#include "../users/Director.h"


class Director;

class DirectorSetter;


class DirectorCabinet : public Room {

    friend class DirectorSetter; // a director has access to private members of the director cabinet


    const Director* director;

public:
    /* Constructors */

    explicit DirectorCabinet(std::string number);

    DirectorCabinet(std::string number, Director& director);


    /* Public member-functions */

    [[nodiscard]] std::string toString() const override;


    /* Getters */

    /**
     * (Nullable)!
     *
     * @return - pointer to a director;
     *         - 'nullptr' if it is no director
     *                  associated to this director cabinet yet
     */
    [[nodiscard]] const Director *getDirector() const;
};



/**
 * DirectorSetter class
 *  is necessary to set a director to the director cabinet
 *
 * This class is an interface between Director-class
 *  and DirectorCabinet-class
 *
 * Director should have access to 'director'-field of DirectorCabinet
 *
 * However, Director shouldn't have access to other private
 *  entities of DirectorCabinet-class, so this interface helps them
 *  interact saving encapsulation
 */
class DirectorSetter {

    friend class Director;

    static bool setDirectorToCabinet(const Director& director, DirectorCabinet& cabinet);

public:
    /* Deleting all possible ways to create an instance of this class */

    DirectorSetter() = delete;

    ~DirectorSetter() = delete;

    // Declaring copy constructor, no move constructor will be generated implicitly
    DirectorSetter(const DirectorSetter&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    DirectorSetter& operator=(const DirectorSetter&) = delete;
};


#endif //ASSIGNMENT_2_DIRECTORCABINET_H
