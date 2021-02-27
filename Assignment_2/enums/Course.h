#ifndef ASSIGNMENT_2_COURSE_H
#define ASSIGNMENT_2_COURSE_H


#include <string>


/**
 * An attempt to create a powerful enum class as in Java
 *  with methods and fields
 *
 * This class is completely immutable
 * There are only 13 instances of this class that can exist in the program.
 *  These instances are static const members of this class
 *  - ANALYTICAL_GEOMETRY_I
 *  - INTRODUCTION_TO_PROGRAMMING_I
 *  - MATH_ANALYSIS_I
 *  - ENGLISH_FOR_ACADEMIC_PURPOSES_I
 *  - DISCRETE_MATH
 *  - PHILOSOPHY
 *  - COMPUTER_ARCHITECTURE
 *  - ANALYTICAL_GEOMETRY_II
 *  - INTRODUCTION_TO_PROGRAMMING_II
 *  - MATH_ANALYSIS_II
 *  - THEORETICAL_COMPUTER_SCIENCE
 *  - DATA_STRUCTURES_AND_ALGORITHMS
 *
 * But there is always an option to add new types of course, and extend this class
 */
class Course final {

    /** Inner enum */
    enum class CourseType {
        ANALYTICAL_GEOMETRY_I,
        INTRODUCTION_TO_PROGRAMMING_I,
        MATH_ANALYSIS_I,
        ENGLISH_FOR_ACADEMIC_PURPOSES_I,
        DISCRETE_MATH,
        PHILOSOPHY,
        COMPUTER_ARCHITECTURE,

        ANALYTICAL_GEOMETRY_II,
        INTRODUCTION_TO_PROGRAMMING_II,
        MATH_ANALYSIS_II,
        ENGLISH_FOR_ACADEMIC_PURPOSES_II,
        THEORETICAL_COMPUTER_SCIENCE,
        DATA_STRUCTURES_AND_ALGORITHMS
    };


    const CourseType courseType;


    /** Constructor for only in-class instances  */
    explicit Course(CourseType courseType);

public:
    // Declaring copy constructor, no move constructor will be generated implicitly
    Course(const Course&) = delete;

    // Declaring copy-assignment-operator, no move-assignment-operator will be generated implicitly
    Course& operator=(const Course&) = delete;


    /* Constants */

    /** These constant are the only instances of these class that can be used in a program */
    static const Course ANALYTICAL_GEOMETRY_I;
    static const Course INTRODUCTION_TO_PROGRAMMING_I;
    static const Course MATH_ANALYSIS_I;
    static const Course ENGLISH_FOR_ACADEMIC_PURPOSES_I;
    static const Course DISCRETE_MATH;
    static const Course PHILOSOPHY;
    static const Course COMPUTER_ARCHITECTURE;
    static const Course ANALYTICAL_GEOMETRY_II;
    static const Course INTRODUCTION_TO_PROGRAMMING_II;
    static const Course MATH_ANALYSIS_II;
    static const Course ENGLISH_FOR_ACADEMIC_PURPOSES_II;
    static const Course THEORETICAL_COMPUTER_SCIENCE;
    static const Course DATA_STRUCTURES_AND_ALGORITHMS;


    /* Overloaded operators */

    friend std::ostream &operator<<(std::ostream &out, const Course &course);


    /* Public member-functions */

    /*
     * @return string-representation (actually just a name) of level of access
     */
    [[nodiscard]] std::string toString() const;
};


#endif //ASSIGNMENT_2_COURSE_H
