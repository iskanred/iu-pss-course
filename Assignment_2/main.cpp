#include "users/Professor.h"
#include "users/Student.h"
#include "users/LabEmployee.h"
#include "users/Admin.h"
#include "rooms/ClassRoom.h"
#include "rooms/DirectorCabinet.h"

/// For test

int main() {

    Professor professor("Adil", "Khan", "khan", "!",
                      {"DSA", "ML-2"});

    Student student("Iskander", "Nafikov", "iskanred", "BS20-02", true);

    LabEmployee labEmployee("Oleg", "Bulichev", "bulich", Lab::CYBER_SECURITY, "Product manager");


    Admin admin("Maxim", "Indusov", "max_indus", "12345678");

    admin.setAccessLevelForUser(professor, AccessLevel::RED);

    DirectorCabinet directorCabinet("A123");

    directorCabinet.openByUser(admin);

    directorCabinet.openByUser(professor);

    admin.setAccessLevelForUser(professor, AccessLevel::YELLOW);

    directorCabinet.openByUser(professor);

    return 0;
}
