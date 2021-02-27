#ifndef ASSIGNMENT_2_ACCESSLEVEL_H
#define ASSIGNMENT_2_ACCESSLEVEL_H

#include <string>


/**
 * An attempt to create a powerful enum class as in Java
 *  with methods and fields
 */
class AccessLevel final {

    /** Inner enum */
    enum class AccessType {
        NO_LEVEL,
        GREEN,
        YELLOW,
        RED
    };


    AccessType access;


    /** Constructor for only in-class instances  */
    explicit AccessLevel(AccessType access);

public:
    /* Constants */

    static const AccessLevel NO_LEVEL;
    static const AccessLevel GREEN;
    static const AccessLevel YELLOW;
    static const AccessLevel RED;


    /* Overloaded Operators */

    bool operator==(const AccessLevel &rhs) const;

    bool operator!=(const AccessLevel &rhs) const;

    bool operator>(const AccessLevel& rhs) const;

    bool operator<(const AccessLevel& rhs) const;

    bool operator>=(const AccessLevel& rhs) const;

    bool operator<=(const AccessLevel& rhs) const;


    /* Public member-functions */

    /*
     * @return string-representation (actually just a name) of level of access
     */
    [[nodiscard]] std::string toString() const;
};


#endif //ASSIGNMENT_2_ACCESSLEVEL_H
