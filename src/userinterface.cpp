#include "userinterface.hpp"

void UserInterface::run() {
    int choice;
    std::vector<std::shared_ptr<Student>> sortedStudents;
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
            displayStudents();
            break;
        case 3:
            searchBySurname();
            break;
        case 4:
            searchByPESEL();
            break;
        case 5:
            sortedStudents = database_.sortStudentsByPESEL();
            displayStudents(sortedStudents);
            break;
        case 6:
            sortedStudents = database_.sortStudentsBySurname();
            displayStudents(sortedStudents);
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

void UserInterface::displayStudents() const {
    auto students = database_.getStudents();

    if (students.size() == 0) {
        std::cout << "The student database is empty!!!\n";
    } else {
        for (const auto& student : students) {
            displayStudent(student);
        }
    }
}

void UserInterface::displayStudents(std::vector<std::shared_ptr<Student>> students) const {
    if (students.size() == 0) {
        std::cout << "The student database is empty!!!\n";
    } else {
        for (const auto& student : students) {
            displayStudent(student);
        }
    }
}

void UserInterface::displayStudent(std::shared_ptr<Student> student) const {
    if (student == nullptr) {
        std::cout << "Student not found! \n";
    } else {
        std::cout << "Name: " << student->getName() << "\n";
        std::cout << "Surname: " << student->getSurname() << "\n";
        std::cout << "Adress: " << student->getAddress() << "\n";
        std::cout << "Index number: " << student->getIndexNumber() << "\n";
        std::cout << "PESEL: " << student->getPESEL() << "\n";
        std::cout << "Gender: " << ((student->getGender() == Gender::Male) ? "Male" : "Female")
                  << "\n\n";
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

    auto student = std::make_shared<Student>(name, surname, address, indexNumber, PESEL, gender);
    database_.addStudent(student);
}

void UserInterface::searchBySurname() {
    std::string surname;

    std::cout << "Enter student's surname: ";
    std::cin >> surname;

    auto students = database_.searchBySurname(surname);
    displayStudents(students);
}

void UserInterface::searchByPESEL() {
    std::string PESEL;

    std::cout << "Enter student's PESEL: ";
    std::cin >> PESEL;

    auto student = database_.searchByPESEL(PESEL);
    displayStudent(student);
}

void UserInterface::removeStudentByIndexNumber() {
    int indexNumber;
    std::cout << "Enter student's index number: ";
    std::cin >> indexNumber;

    database_.removeStudentByIndexNumber(indexNumber);
}