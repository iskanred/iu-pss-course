#ifndef ASSIGNMENT_2_ACCESSLEVEL_H
#define ASSIGNMENT_2_ACCESSLEVEL_H

#include <string>


/**
 * An attempt to create a powerful enum class as in Java
 *  with methods and fields
 *
 * This class is completely immutable
 * There are only 4 instances of this class that can exist in the program.
 *  These instances are static const members of this class
 *  - NO_LEVEL
 *  - GREEN
 *  - YELLOW
 *  - RED
 *
 * But there is always an option to add new types of access level, and extend this class
 */
class AccessLevel final {

    /** Inner enum */
    enum class AccessType {
        NO_LEVEL = 0,
        GREEN = 1,
        YELLOW = 2,
        RED = 3
    };


    const AccessType access;


    /** Constructor for only in-class instances  */
    explicit AccessLevel(AccessType access);

public:
    // Declaring copy constructor, no move constructor will be generated implicitly
    AccessLevel(const AccessLevel&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    AccessLevel& operator=(const AccessLevel&) = delete;


    /* Constants */

    /** These constants are the only instances of this class that can exist in the program */
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

    friend std::ostream &operator<<(std::ostream &out, const AccessLevel &accessLevel);


    /* Public member-functions */

    /*
     * @return string-representation (actually just a name) of level of access
     */
    [[nodiscard]] std::string toString() const;
};


#endif //ASSIGNMENT_2_ACCESSLEVEL_H
