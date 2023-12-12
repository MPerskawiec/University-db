#include "student.hpp"

Student::Student(const std::string& name, const std::string& surname, const std::string& address, const int& indexNumber, const std::string& PESEL, const Gender& gender)
    : name_(name),
      surname_(surname),
      address_(address),
      indexNumber_(indexNumber),
      PESEL_(PESEL),
      gender_(gender) {}

std::string Student::getName() const {
    return name_;
}
std::string Student::getSurname() const {
    return surname_;
}
std::string Student::getAddress() const {
    return address_;
}
int Student::getIndexNumber() const {
    return indexNumber_;
}
std::string Student::getPESEL() const {
    return PESEL_;
}
Gender Student::getGender() const {
    return gender_;
}
