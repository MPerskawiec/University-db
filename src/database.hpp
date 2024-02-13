#pragma once
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>
#include "student.hpp"
#include "employee.hpp"

class Database {
private:
    std::vector<std::shared_ptr<Person>> database_;

public:
    Database();
    void addStudent(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& indexNumber);
    void addEmployee(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& salary);

    std::vector<std::shared_ptr<Person>> getStudents() const; 
    std::vector<std::shared_ptr<Person>> getEmployees() const; 
    std::vector<std::shared_ptr<Person>> getPersons() const; 

    std::vector<std::shared_ptr<Person>> searchBySurname(const std::string& surname) const;
    std::shared_ptr<Person> searchByPESEL(const std::string& PESEL) const;

    std::vector<std::shared_ptr<Person>> sortStudentsByPESEL() const;
    std::vector<std::shared_ptr<Person>> sortStudentsBySurname() const;
    void removeStudentByIndexNumber(const int& number);
};
