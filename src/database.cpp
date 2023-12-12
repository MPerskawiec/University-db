#include "database.hpp"

Database::Database() {}

void Database::addStudent(std::shared_ptr<Student> student) {
    studentsDb_.push_back(student);
}

std::vector<std::shared_ptr<Student>> Database::getStudents() const {
    return studentsDb_;
}

size_t Database::getNumberOfStudents() const {
    return studentsDb_.size();
}

std::vector<std::shared_ptr<Student>> Database::searchBySurname(const std::string& surname) const {
    std::vector<std::shared_ptr<Student>> studentsBySurname;

    std::copy_if(studentsDb_.begin(), studentsDb_.end(), std::back_inserter(studentsBySurname),
                 [&surname](const auto& student) { return student->getSurname() == surname; });

    return studentsBySurname;
}

std::shared_ptr<Student> Database::searchByPESEL(const std::string& PESEL) const {
    for (const auto& student : studentsDb_) {
        if (PESEL == student->getPESEL()) {
            return student;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Student>> Database::sortStudentsByPESEL() const {
    std::vector<std::shared_ptr<Student>> sortedStudents(studentsDb_);

    std::sort(sortedStudents.begin(), sortedStudents.end(), [](auto s1, auto s2) { return s1->getPESEL() < s2->getPESEL(); });

    return sortedStudents;
}

std::vector<std::shared_ptr<Student>> Database::sortStudentsBySurname() const {
    std::vector<std::shared_ptr<Student>> sortedStudents(studentsDb_);

    std::sort(sortedStudents.begin(), sortedStudents.end(), [](auto s1, auto s2) { return s1->getSurname() < s2->getSurname(); });

    return sortedStudents;
};

void Database::removeStudentByIndexNumber(const int& number) {
    studentsDb_.erase(std::remove_if(studentsDb_.begin(), studentsDb_.end(), [&number](auto student) {
                          return student->getIndexNumber() == number;
                      }),
                      studentsDb_.end());
}