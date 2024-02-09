#include "student.hpp"

Student::Student(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& indexNumber)
    : Person(name, surname, address, PESEL, gender, Position::Student), indexNumber_(indexNumber){}


int Student::getIndexNumber() const {
    return indexNumber_;
}
