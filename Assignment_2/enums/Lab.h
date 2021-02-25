#ifndef ASSIGNMENT_2_LAB_H
#define ASSIGNMENT_2_LAB_H

#include <string>


/**
 * An attempt to create a powerful enum class as in Java
 *  with methods and fields
 */
class Lab {

    /** Inner enum */
    enum class LabType {
        DATA_SCIENCE,
        CYBER_SECURITY,
        NETWORKS,
        SOFTWARE_ENGINEERING,
        OPERATING_SYSTEMS,
        ROBOTICS
    };


    /* Fields */

    LabType lab;


    /** Constructor for only in-class instances  */
    explicit Lab(LabType lab);

public:
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
    std::string toString();

};

#endif //ASSIGNMENT_2_LAB_H
