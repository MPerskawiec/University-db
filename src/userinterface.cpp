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
            addPerson();
            break;
        case 2:
            displayPersons(database_.getPersons());
            break;
       case 3:
            displayPersons(database_.getStudents());
            break;
       case 4:
            displayPersons(database_.getEmployees());
            break;
        case 5:
            searchBySurname();
            break;
        case 6:
            searchByPESEL();
            break;
        case 7:
            sortedPersons = database_.sortStudentsByPESEL();
            displayPersons(sortedPersons);
            break;
        case 8:
            sortedPersons = database_.sortStudentsBySurname();
            displayPersons(sortedPersons);
            break;
        case 9:
            removeStudentByIndexNumber();
            break;
        case 99:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 99);
}

void UserInterface::displayMenu() const {
    std::cout << "1. Add Person\n";
    std::cout << "2. Display all database\n";
    std::cout << "3. Display Students\n";
    std::cout << "4. Display Employees\n";
    std::cout << "5. Search by Surname\n";
    std::cout << "6. Search by PESEL\n";
    std::cout << "7. Sort Students by PESEL\n";
    std::cout << "8. Sort Students by Surname\n";
    std::cout << "9. Remove Student by Index Number\n";
    std::cout << "99. Exit\n";
}


void UserInterface::displayPersons(std::vector<std::shared_ptr<Person>> persons) const {
    if (persons.size() == 0) {
        std::cout << "The student database is empty!!!\n";
    } else {
        for (const auto& person : persons) {
            displayPerson(person);
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
    } else if (person->getPosition() == Position::Employee) {
        std::cout << "Salary: " << person->getSalary() << "\n\n";
    }
}

void UserInterface::addPerson() {
    std::string name, surname, address, PESEL;
    int indexNumber, salary;
    Position position;
    Gender gender;

    std::cout << "Enter person's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter person's surname: ";
    std::getline(std::cin, surname);

    std::cout << "Enter person's address: ";
    std::getline(std::cin, address);

    std::cout << "Enter person's PESEL: ";
    std::getline(std::cin, PESEL);

    std::cout << "Enter person's gender (0 for Male, 1 for Female): ";
    int genderInput;
    std::cin >> genderInput;
    gender = (genderInput == 0) ? Gender::Male : Gender::Female;

    std::cout << "Enter person's position(0 for Student, 1 for Employee): ";
    int positionInput;
    std::cin >> positionInput;
    position = (positionInput == 0) ? Position::Student : Position::Employee;

    if (position == Position::Student){
        std::cout << "Enter student's index number: ";
        std::cin >> indexNumber;
        database_.addStudent(name, surname, address, PESEL, gender, indexNumber);
    } else  if (position == Position::Employee){
        std::cout << "Enter employee's salary: ";
        std::cin >> salary;
        database_.addEmployee(name, surname, address, PESEL, gender, salary);
    } 

    
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