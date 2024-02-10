#include "userinterface.hpp"

void UserInterface::run() {
    int choice;
    std::vector<std::shared_ptr<Person>> sortedPersons;
    do {
        std::cout << "\n***************************\n";
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n***************************\n";

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayPersons();
            break;
        case 3:
            searchBySurname();
            break;
        case 4:
            searchByPESEL();
            break;
        case 5:
            sortedPersons = database_.sortStudentsByPESEL();
            displayPersons(sortedPersons);
            break;
        case 6:
            sortedPersons = database_.sortStudentsBySurname();
            displayPersons(sortedPersons);
            break;
        case 7:
            removeStudentByIndexNumber();
            break;
        case 8:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);
}

void UserInterface::displayMenu() const {
    std::cout << "1. Add Student\n";
    std::cout << "2. Display Students\n";
    std::cout << "3. Search by Surname\n";
    std::cout << "4. Search by PESEL\n";
    std::cout << "5. Sort Students by PESEL\n";
    std::cout << "6. Sort Students by Surname\n";
    std::cout << "7. Remove Student by Index Number\n";
    std::cout << "8. Exit\n";
}

void UserInterface::displayPersons() const {
    auto students = database_.getStudents();

    if (students.size() == 0) {
        std::cout << "The student database is empty!!!\n";
    } else {
        for (const auto& student : students) {
            displayPerson(student);
        }
    }
}

void UserInterface::displayPersons(std::vector<std::shared_ptr<Person>> students) const {
    if (students.size() == 0) {
        std::cout << "The student database is empty!!!\n";
    } else {
        for (const auto& student : students) {
            displayPerson(student);
        }
    }
}

void UserInterface::displayPerson(std::shared_ptr<Person> person) const {

    std::cout << "Name: " << person->getName() << "\n";
    std::cout << "Surname: " << person->getSurname() << "\n";
    std::cout << "Adress: " << person->getAddress() << "\n";
    std::cout << "PESEL: " << person->getPESEL() << "\n";
    std::cout << "Gender: " << ((person->getGender() == Gender::Male) ? "Male" : "Female") << "\n";
    std::cout << "Position: " << ((person->getPosition() == Position::Employee) ? "Employee" : "Student") << "\n";

    if (person->getPosition() == Position::Student) {
        std::cout << "Index number: " << person->getIndexNumber() << "\n\n";
    }
}

void UserInterface::addStudent() {
    std::string name, surname, address, PESEL;
    int indexNumber;
    Gender gender;

    std::cout << "Enter student's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter student's surname: ";
    std::getline(std::cin, surname);

    std::cout << "Enter student's address: ";
    std::getline(std::cin, address);

    std::cout << "Enter student's index number: ";
    std::cin >> indexNumber;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter student's PESEL: ";

    std::getline(std::cin, PESEL);

    std::cout << "Enter student's gender (0 for Male, 1 for Female): ";
    int genderInput;
    std::cin >> genderInput;
    gender = (genderInput == 0) ? Gender::Male : Gender::Female;

    database_.addStudent(name, surname, address, PESEL, gender, indexNumber);
}

void UserInterface::searchBySurname() {
    std::string surname;

    std::cout << "Enter student's surname: ";
    std::cin >> surname;

    auto persons = database_.searchBySurname(surname);
    displayPersons(persons);
}

void UserInterface::searchByPESEL() {
    std::string PESEL;

    std::cout << "Enter student's PESEL: ";
    std::cin >> PESEL;

    auto person = database_.searchByPESEL(PESEL);
    displayPerson(person);
}

void UserInterface::removeStudentByIndexNumber() {
    int indexNumber;
    std::cout << "Enter student's index number: ";
    std::cin >> indexNumber;

    database_.removeStudentByIndexNumber(indexNumber);
}