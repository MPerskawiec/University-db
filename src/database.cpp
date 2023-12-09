#include "database.hpp"

Database::Database() {}

void Database::addStudent(std::shared_ptr<Student> student){
    studentsDb_.push_back(student);
}

std::vector<std::shared_ptr<Student>> Database::getStudents() const {
    return studentsDb_;
}