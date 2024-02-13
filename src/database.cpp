#include "database.hpp"

Database::Database() {
    addStudent("Adam1", "Kowalski1", "Skierniewice 123", "987", Gender::Male, 3);
    addStudent("Adam2", "Kowalski2", "Skierniewice 123", "986", Gender::Male, 2);
    addStudent("Adam3", "Kowalski3", "Skierniewice 123", "985", Gender::Male, 1);

    addEmployee("Olek1", "Kowalski1", "Skierniewice 123", "887", Gender::Male, 3600);
    addEmployee("Olek2", "Kowalski2", "Skierniewice 123", "886", Gender::Male, 2600);
    addEmployee("Olek3", "Kowalski3", "Skierniewice 123", "885", Gender::Male, 1600);
}

void Database::addStudent(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& indexNumber) {
    database_.push_back(std::make_shared<Student>(name, surname, address, PESEL, gender, indexNumber));
}

void Database::addEmployee(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& salary) {
    database_.push_back(std::make_shared<Employee>(name, surname, address, PESEL, gender, salary));
}

std::vector<std::shared_ptr<Person>> Database::getStudents() const {
    std::vector<std::shared_ptr<Person>> students;

    std::copy_if(database_.begin(), database_.end(), std::back_inserter(students),
                 [](const auto& person) { return person->getPosition() == Position::Student; });

    return students;
}

std::vector<std::shared_ptr<Person>> Database::getEmployees() const {
    std::vector<std::shared_ptr<Person>> employees;

    std::copy_if(database_.begin(), database_.end(), std::back_inserter(employees),
                 [](const auto& person) { return person->getPosition() == Position::Employee; });

    return employees;
}

std::vector<std::shared_ptr<Person>> Database::getPersons() const {
    return database_;
}

std::vector<std::shared_ptr<Person>> Database::searchBySurname(const std::string& surname) const {
    std::vector<std::shared_ptr<Person>> personBySurname;

    std::copy_if(database_.begin(), database_.end(), std::back_inserter(personBySurname),
                 [&surname](const auto& student) { return student->getSurname() == surname; });

    return personBySurname;
}

std::shared_ptr<Person> Database::searchByPESEL(const std::string& PESEL) const {
    for (const auto& person : database_) {
        if (PESEL == person->getPESEL()) {
            return person;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Person>> Database::sortStudentsByPESEL() const {
    std::vector<std::shared_ptr<Person>> sortedStudents = getStudents();

    std::sort(sortedStudents.begin(), sortedStudents.end(), [](auto s1, auto s2) { return std::stoi(s1->getPESEL()) < std::stoi(s2->getPESEL()); });

    return sortedStudents;
}

std::vector<std::shared_ptr<Person>> Database::sortStudentsBySurname() const {
    std::vector<std::shared_ptr<Person>> sortedStudents = getStudents();

    std::sort(sortedStudents.begin(), sortedStudents.end(), [](auto s1, auto s2) { return s1->getSurname() < s2->getSurname(); });

    return sortedStudents;
};

void Database::removeStudentByIndexNumber(const int& number) {
    database_.erase(std::remove_if(database_.begin(), database_.end(), [&number](auto person) {
                        auto student = std::dynamic_pointer_cast<Student>(person);
                        if (student) {
                            if (student->getIndexNumber() == number) {
                                return true;
                            }
                        }
                        return false;
                    }),
                    database_.end());
}