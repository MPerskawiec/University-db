#include "person.hpp"

Person::Person(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const Position& position)
    : name_(name),
      surname_(surname),
      address_(address),
      PESEL_(PESEL),
      gender_(gender),
      position_(position) {}

std::string Person::getName() const {
    return name_;
}
std::string Person::getSurname() const {
    return surname_;
}
std::string Person::getAddress() const {
    return address_;
}
std::string Person::getPESEL() const {
    return PESEL_;
}
Gender Person::getGender() const {
    return gender_;
}
Position Person::getPosition() const {
    return position_;
}

int Person::getIndexNumber() const{
    return 0;
 }