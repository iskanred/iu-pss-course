#ifndef ASSIGNMENT_2_ACCESSLEVEL_H
#define ASSIGNMENT_2_ACCESSLEVEL_H

#include <string>


/**
 * An attempt to create a powerful enum class as in Java
 *  with methods and fields
 */
class AccessLevel {

    /** Inner enum */
    enum class AccessType {
        NO_LEVEL,
        GREEN,
        YELLOW,
        RED
    };

    /* Fields */

    AccessType access;

    /** Constructor for only in-class instances  */
    explicit AccessLevel(AccessType access);

public:
    /* Constants */

    /** These constant are the only instances of these class that can be used in a program */
    static const AccessLevel NO_LEVEL;
    static const AccessLevel GREEN;
    static const AccessLevel YELLOW;
    static const AccessLevel RED;


    /* Public member-functions */

    /**
     * @return an upper (by 1) level of access
     * If it is already max (RED), then return RED
     */
    AccessLevel getUpperAccessLevel();

    /*
     * @return string-representation (actually just a name) of level of access
     */
    std::string toString();
};

#endif //ASSIGNMENT_2_ACCESSLEVEL_H
