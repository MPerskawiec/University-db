#include "database.hpp"

Database::Database() {}

void Database::addStudent(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& indexNumber) {
    database_.push_back(std::make_shared<Student>(name, surname, address, PESEL, gender, indexNumber));
}

std::vector<std::shared_ptr<Person>> Database::getStudents() const {
    std::vector<std::shared_ptr<Person>> students;

    std::copy_if(database_.begin(), database_.end(), std::back_inserter(students),
                [](const auto& person){ return person->getPosition() == Position::Student; });

    return students;
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