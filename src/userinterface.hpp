#pragma once

#include "person.hpp"
#include "student.hpp"
#include "database.hpp"

#include <iostream>

class UserInterface{
private:
    Database& database_;

    void displayMenu() const;
    void displayStudents() const;
    void displayStudents(std::vector<std::shared_ptr<Person>> students) const;
    void displayStudent(std::shared_ptr<Person> student) const;
    void addStudent();
    void searchBySurname();
    void searchByPESEL();
    void removeStudentByIndexNumber();

public:
    UserInterface(Database& database) : database_(database) {}

    void run();




};

