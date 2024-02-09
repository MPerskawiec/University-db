#pragma once
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>
#include "student.hpp"

class Database {
private:
    std::vector<std::shared_ptr<Person>> database_;

public:
    Database();
    void addStudent(std::shared_ptr<Student> student);

    std::vector<std::shared_ptr<Person>> getStudents() const; 

    size_t getNumberOfStudents() const;

    std::vector<std::shared_ptr<Person>> searchBySurname(const std::string& surname) const;

    std::shared_ptr<Person> searchByPESEL(const std::string& PESEL) const;

    std::vector<std::shared_ptr<Person>> sortStudentsByPESEL() const;
    std::vector<std::shared_ptr<Person>> sortStudentsBySurname() const;

    void removeStudentByIndexNumber(const int& number);
};
