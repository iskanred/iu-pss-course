#include "Course.h"


/** Constructor for only in-class instances  */
Course::Course(CourseType courseType) : courseType(courseType)
{ }

/* Constants */

const Course Course::ANALYTICAL_GEOMETRY_I = Course(CourseType::ANALYTICAL_GEOMETRY_I);

const Course Course::INTRODUCTION_TO_PROGRAMMING_I = Course(CourseType::INTRODUCTION_TO_PROGRAMMING_I);

const Course Course::MATH_ANALYSIS_I = Course(CourseType::MATH_ANALYSIS_I);

const Course Course::ENGLISH_FOR_ACADEMIC_PURPOSES_I = Course(CourseType::ENGLISH_FOR_ACADEMIC_PURPOSES_I);

const Course Course::DISCRETE_MATH = Course(CourseType::DISCRETE_MATH);

const Course Course::PHILOSOPHY = Course(CourseType::PHILOSOPHY);

const Course Course::COMPUTER_ARCHITECTURE = Course(CourseType::COMPUTER_ARCHITECTURE);

const Course Course::ANALYTICAL_GEOMETRY_II = Course(CourseType::ANALYTICAL_GEOMETRY_II);

const Course Course::INTRODUCTION_TO_PROGRAMMING_II = Course(CourseType::INTRODUCTION_TO_PROGRAMMING_II);

const Course Course::MATH_ANALYSIS_II = Course(CourseType::MATH_ANALYSIS_II);

const Course Course::ENGLISH_FOR_ACADEMIC_PURPOSES_II = Course(CourseType::ENGLISH_FOR_ACADEMIC_PURPOSES_II);

const Course Course::THEORETICAL_COMPUTER_SCIENCE = Course(CourseType::THEORETICAL_COMPUTER_SCIENCE);

const Course Course::DATA_STRUCTURES_AND_ALGORITHMS = Course(CourseType::DATA_STRUCTURES_AND_ALGORITHMS);


/* Overloaded Operators */

std::ostream &operator<<(std::ostream &out, const Course &course) {
    out << course.toString();
    return out;
}


/* Public member-functions */

std::string Course::toString() const {
    switch (courseType) {
        case CourseType::ANALYTICAL_GEOMETRY_I :
            return "Analytical-Geometry-I";

        case CourseType::INTRODUCTION_TO_PROGRAMMING_I :
            return "Introduction-To-Programming-I";

        case CourseType::MATH_ANALYSIS_I :
            return "Mathematical-Analysis-I";

        case CourseType::ENGLISH_FOR_ACADEMIC_PURPOSES_I :
            return "English-For-Academic-Purposes-I";

        case CourseType::DISCRETE_MATH :
            return "Discrete-Math";

        case CourseType::PHILOSOPHY :
            return "Philosophy";

        case CourseType::COMPUTER_ARCHITECTURE :
            return "Computer-Architecture";

        case CourseType::ANALYTICAL_GEOMETRY_II :
            return "Analytical-Geometry-II";

        case CourseType::INTRODUCTION_TO_PROGRAMMING_II :
            return "Introduction-To-Programming-II";

        case CourseType::MATH_ANALYSIS_II :
            return "Mathematical-Analysis-II";

        case CourseType::ENGLISH_FOR_ACADEMIC_PURPOSES_II :
            return "English-For-Academic-Purposes-II";

        case CourseType::THEORETICAL_COMPUTER_SCIENCE :
            return "Theoretical-Computer-Science";

        case CourseType::DATA_STRUCTURES_AND_ALGORITHMS :
            return "Data-Structures-And-Algorithms";
    }
}
