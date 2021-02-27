#include "AccessLevel.h"


/* Constants */

const AccessLevel AccessLevel::NO_LEVEL = AccessLevel(AccessType::NO_LEVEL);

const AccessLevel AccessLevel::GREEN = AccessLevel(AccessType::GREEN);

const AccessLevel AccessLevel::YELLOW = AccessLevel(AccessType::YELLOW);

const AccessLevel AccessLevel::RED = AccessLevel(AccessType::RED);


/* Constructor */

AccessLevel::AccessLevel(AccessLevel::AccessType access) :
    access(access)
{ }


/* Overloaded Operators */

bool AccessLevel::operator==(const AccessLevel &rhs) const {
    return access == rhs.access;
}

bool AccessLevel::operator!=(const AccessLevel &rhs) const {
    return !(rhs == *this);
}

bool AccessLevel::operator>(const AccessLevel& rhs) const {
    return access > rhs.access;
}

bool AccessLevel::operator<(const AccessLevel& rhs) const {
    return access < rhs.access;
}

bool AccessLevel::operator>=(const AccessLevel &rhs) const {
    return access >= rhs.access;
}

bool AccessLevel::operator<=(const AccessLevel &rhs) const {
    return access <= rhs.access;
}

std::ostream &operator<<(std::ostream &out, const AccessLevel &accessLevel)  {
    out << accessLevel.toString();
    return out;
}


/* Public member-functions */

std::string AccessLevel::toString() const {
    switch (access) {
        case AccessType::NO_LEVEL :
            return "[NO_LEVEL]";

        case AccessType::YELLOW :
            return "[YELLOW]";

        case AccessType::GREEN :
            return "[GREEN]";

        case AccessType::RED :
            return "[RED]";
    }
}
