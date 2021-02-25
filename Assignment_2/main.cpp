#include "users/Student.h"
#include "users/LabEmployee.h"
#include "users/Admin.h"

/// For test

int main() {

    Professor professor("Adil", "Khan", "khan", "!",
                      {"LinAl-1", "Calculus", "ML-2"});

    Student student("Iskander", "Nafikov", "iskanred", "BS20-02", true);

    LabEmployee labEmployee("Oleg", "Bulichev", "bulich", Lab::CYBER_SECURITY, "1");


    Admin admin("Kulich", "Ebanov", "kulich", "123");

    admin.upAccess(student);

    return 0;
}
