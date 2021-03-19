#include "Console.h"

#include <iostream>

namespace Console {

    /* User - Room */

    void printUserOpenRoomFailure(const User &user, const Room &room) {
        std::cout << user.toString() << " cannot open the "
                  << room.toString() << std::endl;
    }

    void printUserOpenRoomSuccess(const User &user, const Room &room) {
        std::cout << user.toString() << " has opened the "
                  << room.toString() << std::endl;
    }


    /* Director - Director cabinet */

    void printDirectorTakeCabinetSuccess(const Director &director,
                                         const DirectorCabinet &cabinet) {
        std::cout << director.toString()
             << " has taken " << cabinet.toString() << std::endl;
    }

    void printDirectorTakeCabinetFailure(const Director &director,
                                         const DirectorCabinet &cabinet) {
        std::cout << "Director " << director.toString()
             << " has tried to take " << cabinet.toString()
             << ", but this cabinet is already taken by "
             << cabinet.getDirector()->toString() << std::endl;
    }

    void printDirectorRemoveCabinetSuccess(const Director &director, const DirectorCabinet &cabinet) {
        std::cout << cabinet.toString() << " is not "
             << director.toString() << "'s cabinet more" << std::endl;
    }

    void printDirectorRemoveCabinetFailure(const Director &director) {
        std::cout << director.toString() << " has tried to remove his cabinet, "
                                            "but he has no cabinet" << std::endl;
    }


    /* Admin - User - Room - AccessLevel */

    void printAdminSetAccessLevelForUser(const Admin &admin,
                                         const User &user,
                                         const AccessLevel &accessLevel) {
        std::cout << admin.toString() << " has updated " << user.toString()
             << "'s access level to " << accessLevel.toString() << std::endl;
    }

    void printAdminSetAccessLevelForRoom(const Admin &admin,
                                         const Room &room,
                                         const AccessLevel &accessLevel) {
        std::cout << admin.toString() << " has updated access level of " << room.toString()
             << " to " << accessLevel.toString() << std::endl;
    }

    void printAdminGrantUserAccessToRoomSuccess(const Admin &admin,
                                                const User &user,
                                                const Room &room) {
        std::cout << admin.toString() << " has granted for " << user.toString()
             << " access to " << room.toString() << std::endl;
    }

    void printAdminGrantUserAccessToRoomFailure(const Admin &admin,
                                                const User &user,
                                                const Room &room) {
        std::cout << admin.toString() << " has tried to grant access for "
             << user.toString() << " to " << room.toString()
             << ", but " << user.toString()
             << " has already had access to this room" << std::endl;
    }

    void printAdminRemoveGrantedAccessForUserToRoomSuccess(const Admin &admin,
                                                           const User &user,
                                                           const Room &room) {
        std::cout << admin.toString() << " has removed granted access for " << user.toString()
             << " to " << room.toString() << std::endl;
    }

    void printAdminRemoveGrantedAccessForUserToRoomFailure(const Admin &admin,
                                                           const User &user,
                                                           const Room &room) {
        std::cout << admin.toString() << " has tried to remove granted access for "
             << user.toString() << " to " << room.toString()
             << ", but " << user.toString()
             << " hasn't had a granted access to this room" << std::endl;
    }
}