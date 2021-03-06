#include "DirectorCabinet.h"


/* Constructor */

/**
 * We can create a director cabinet and do not associate a director to it then
 *  because a director itself can set the cabinet from its class
 *
 * So, it will be associated automatically, when such a director takes this cabinet
 */
DirectorCabinet::DirectorCabinet(std::string number)
    : Room(std::move(number), AccessLevel::RED), director(nullptr)
{ }

DirectorCabinet::DirectorCabinet(std::string number, Director& director) :
        Room(std::move(number), AccessLevel::RED)
{
    director.setCabinet(*this);
}


/* Public member-functions */

std::string DirectorCabinet::toString() const {
    return "({Director-cabinet} #" + number +")";
}

/* Getters */

/**
 * (Nullable)!
 *
 * @return - pointer to a director;
 *         - 'nullptr' if it is no director
 *                  associated to this director cabinet yet
 */
const Director *DirectorCabinet::getDirector() const {
    return director;
}



/* DirectorSetter */

/**
 * @return - 'true' if director had been set to cabinet
 *         - 'false' if director hadn't been set to cabinet
 *              (what means that another director has already taken this cabinet
 */
bool DirectorSetter::setDirectorToCabinet(Director* director, DirectorCabinet& cabinet) {
    if (cabinet.director == nullptr || director == nullptr) {
        cabinet.director = director;
        return true;
    }
    return false; // if this is already another director's cabinet
}
