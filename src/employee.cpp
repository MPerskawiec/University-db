#include "employee.hpp"

Employee::Employee(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& salary)
    : Person(name, surname, address, PESEL, gender, Position::Employee), salary_(salary) {}

int Employee::getSalary() const{
    return salary_;
}