#ifndef ASSIGNMENT_2_LAB_H
#define ASSIGNMENT_2_LAB_H

#include <string>


/**
 * An attempt to create a powerful enum class as in Java
 *  with methods and fields
 *
 * This class is completely immutable
 * There are only 6 instances of this class that can exist in the program.
 *  These instances are static const members of this class
 *  - DATA_SCIENCE
 *  - CYBER_SECURITY
 *  - NETWORKS
 *  - SOFTWARE_ENGINEERING
 *  - OPERATING_SYSTEMS
 *  - ROBOTICS
 *
 * But there is always an option to add new types of lab, and extend this class
 */
class Lab final {

    /** Inner enum */
    enum class LabType {
        DATA_SCIENCE,
        CYBER_SECURITY,
        NETWORKS,
        SOFTWARE_ENGINEERING,
        OPERATING_SYSTEMS,
        ROBOTICS
    };


    const LabType lab;


    /** Constructor for only in-class instances  */
    explicit Lab(LabType lab);

public:
    // Declaring copy constructor, no move constructor will be generated implicitly
    Lab(const Lab&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    Lab& operator=(const Lab&) = delete;


    /* Constants */

    /** These constant are the only instances of these class that can be used in a program */
    static const Lab DATA_SCIENCE;
    static const Lab CYBER_SECURITY;
    static const Lab NETWORKS;
    static const Lab SOFTWARE_ENGINEERING;
    static const Lab OPERATING_SYSTEMS;
    static const Lab ROBOTICS;


    /* Public member-functions */

    /*
     * @return string-representation (actually just a name) of level of access
     */
    [[nodiscard]] std::string toString() const;
};


#endif //ASSIGNMENT_2_LAB_H
