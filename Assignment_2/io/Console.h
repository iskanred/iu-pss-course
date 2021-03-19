#ifndef ASSIGNMENT_2_CONSOLE_H
#define ASSIGNMENT_2_CONSOLE_H

#include "../rooms/Room.h"
#include "../users/Director.h"
#include "../users/Admin.h"


/**
 * This namespace is an interface between
 *  other classes that do some logic and standard
 *  console I/O
 */
namespace Console {

    /* User - Room */

    void printUserOpenRoomSuccess(const User& user, const Room& room);

    void printUserOpenRoomFailure(const User& user, const Room& room);


    /* Director - Director cabinet */

    void printDirectorTakeCabinetSuccess(const Director &director,
                                         const DirectorCabinet& cabinet);

    void printDirectorTakeCabinetFailure(const Director &director,
                                         const DirectorCabinet& cabinet);

    void printDirectorRemoveCabinetSuccess(const Director &director,
                                           const DirectorCabinet& cabinet);

    void printDirectorRemoveCabinetFailure(const Director &director);


    /* Admin - User - Room - AccessLevel */

    void printAdminSetAccessLevelForUser(const Admin& admin,
                                         const User& user,
                                         const AccessLevel& accessLevel);

    void printAdminSetAccessLevelForRoom(const Admin& admin,
                                         const Room& room,
                                         const AccessLevel& accessLevel);

    void printAdminGrantUserAccessToRoomSuccess(const Admin& admin,
                                                const User& user,
                                                const Room& room);

    void printAdminGrantUserAccessToRoomFailure(const Admin& admin,
                                                const User& user,
                                                const Room& room);

    void printAdminRemoveGrantedAccessForUserToRoomSuccess(const Admin& admin,
                                                           const User& user,
                                                           const Room& room);

    void printAdminRemoveGrantedAccessForUserToRoomFailure(const Admin& admin,
                                                           const User& user,
                                                           const Room& room);
}


#endif //ASSIGNMENT_2_CONSOLE_H
