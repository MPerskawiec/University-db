#pragma once
#include <string>

enum class Gender {
    Male,
    Female
};

class Student {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    int indexNumber_;
    std::string PESEL_;
    Gender gender_;

public:
    Student(const std::string& name, const std::string& surname, const std::string& address, const int& indexNumber, const std::string& PESEL, const Gender& gender);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    int getIndexNumber() const;
    std::string getPESEL() const;
    Gender getGender() const;

};
