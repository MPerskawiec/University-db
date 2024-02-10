#pragma once

#include <string>

enum class Gender {
    Male,
    Female
};

enum class Position {
    Student,
    Employee
};

class Person {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string PESEL_;
    Gender gender_;
    Position position_;

public:
    Person(const std::string& name, const std::string& surname, const std::string& address, const std::string& PESEL, const Gender& gender, const Position& position);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getPESEL() const;
    Gender getGender() const;
    Position getPosition() const;
    virtual int getIndexNumber() const;


    virtual ~Person() = default;
};