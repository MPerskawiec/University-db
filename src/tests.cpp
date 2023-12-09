#include <gtest/gtest.h>

#include "database.hpp"
#include "student.hpp"

TEST(databaseOperation, AddStudentsToDatabase) {
    // GIVEN
    std::shared_ptr<Student> Mariusz = std::make_shared<Student>("Mariusz", "Polak", "Polna 1, 62-860 Opa", 111, "96042006789", Gender::Male);
    std::shared_ptr<Student> Karol = std::make_shared<Student>("Karol", "Pawlak", "Kaliska 22, 62-860 Opa", 112, "97063006601", Gender::Male);

    Database studentsDb;

    // WHEN
    studentsDb.addStudent(Mariusz);
    studentsDb.addStudent(Karol);
    std::vector<std::shared_ptr<Student>> db = studentsDb.getStudents();

    // THEN
    ASSERT_EQ("Mariusz", db[0]->getName());
    ASSERT_EQ("Polak", db[0]->getSurname());
    ASSERT_EQ("Polna 1, 62-860 Opa", db[0]->getAdress());
    ASSERT_EQ(111, db[0]->getIndexNumber());
    ASSERT_EQ("96042006789", db[0]->getPESEL());
    ASSERT_EQ(Gender::Male, db[0]->getGender());

    ASSERT_EQ("Karol", db[1]->getName());
}
