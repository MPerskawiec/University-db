#pragma once

#include "person.hpp"

class Employee : public Person {
    int salary_;

public:

    Employee(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& salary);

    int getSalary() const override;
};