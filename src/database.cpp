#include "database.hpp"

Database::Database() {}

void Database::addStudent(std::shared_ptr<Student> student) {
    studentsDb_.push_back(student);
}

std::vector<std::shared_ptr<Student>> Database::getStudents() const {
    return studentsDb_;
}

std::vector<std::shared_ptr<Student>> Database::searchBySurname(const std::string& surname) const {
    std::vector<std::shared_ptr<Student>> studentsBySurname;

    std::copy_if(studentsDb_.begin(), studentsDb_.end(), std::back_inserter(studentsBySurname),
                 [&surname](const auto& student) { return student->getSurname() == surname; });

    return studentsBySurname;
}

