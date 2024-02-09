#pragma once
#include <string>

#include "person.hpp"



class Student : public Person{
private:
    int indexNumber_;


public:
    Student(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const int& indexNumber);

    int getIndexNumber() const;

};
