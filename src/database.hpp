#pragma once
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>
#include "student.hpp"

class Database {
private:
    std::vector<std::shared_ptr<Student>> studentsDb_;

public:
    Database();
    void addStudent(std::shared_ptr<Student> student);
    std::vector<std::shared_ptr<Student>> getStudents() const;
    size_t getNumberOfStudents() const;
    std::vector<std::shared_ptr<Student>> searchBySurname(const std::string& surname) const;
    std::shared_ptr<Student> searchByPESEL(const std::string& PESEL) const;
    std::vector<std::shared_ptr<Student>> sortStudentsByPESEL() const;
    std::vector<std::shared_ptr<Student>> sortStudentsBySurname() const;
    void removeStudentByIndexNumber(const int& number);
};
