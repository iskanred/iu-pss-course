#include "AccessLevel.h"


/* Constants */

const AccessLevel AccessLevel::NO_LEVEL = AccessLevel(AccessType::NO_LEVEL);

const AccessLevel AccessLevel::GREEN = AccessLevel(AccessType::GREEN);

const AccessLevel AccessLevel::YELLOW = AccessLevel(AccessType::YELLOW);

const AccessLevel AccessLevel::RED = AccessLevel(AccessType::RED);


/* Constructor */

AccessLevel::AccessLevel(AccessLevel::AccessType access) {
    AccessLevel::access = access;
}


/* Public member-functions */

AccessLevel AccessLevel::getUpperAccessLevel() {
    switch (access) {
        case AccessType::NO_LEVEL :
            return GREEN;

        case AccessType::GREEN :
            return YELLOW;

        case AccessType::YELLOW :
        case AccessType::RED :
            return RED;
    }
}


std::string AccessLevel::toString() {
    switch (access) {
        case AccessType::NO_LEVEL :
            return "NO_LEVEL";

        case AccessType::YELLOW :
            return "YELLOW";

        case AccessType::GREEN :
            return "GREEN";

        case AccessType::RED :
            return "RED";
    }
}
