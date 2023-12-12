#include <iostream>
#include "database.hpp"
#include "student.hpp"
#include "userinterface.hpp"

int main() {
    Database database;
    UserInterface userInterface(database);

    userInterface.run();

    return 0;
}
