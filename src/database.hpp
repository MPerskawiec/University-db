#pragma once
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
};



