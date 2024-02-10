#include <gtest/gtest.h>

#include "database.hpp"
#include "student.hpp"

struct databaseOperation : public testing::Test {
    Database database_;

    databaseOperation() {
        database_.addStudent("Mariusz", "Polak", "Polna 1, 62-860 Opa", "98042006789", Gender::Male, 111);
        database_.addStudent("Karol", "Pawlak", "Kaliska 22, 62-860 Opa", "99042006789", Gender::Male, 112);
        database_.addStudent("Andrzej", "Polak", "Polna 1, 62-860 Opa", "97063006601", Gender::Male, 113);
    }
};

TEST_F(databaseOperation, AddStudentsToDatabase) {
    // GIVEN

    // WHEN
    std::vector<std::shared_ptr<Person>> db = database_.getStudents();

    // THEN
    ASSERT_EQ("Mariusz", db[0]->getName());
    ASSERT_EQ("Polak", db[0]->getSurname());
    ASSERT_EQ("Polna 1, 62-860 Opa", db[0]->getAddress());
    ASSERT_EQ(111, db[0]->getIndexNumber());
    ASSERT_EQ("98042006789", db[0]->getPESEL());
    ASSERT_EQ(Gender::Male, db[0]->getGender());

    ASSERT_EQ("Karol", db[1]->getName());
    ASSERT_EQ("Andrzej", db[2]->getName());
}

TEST_F(databaseOperation, SearchStudentsBySurname) {
    // GIVEN

    // WHEN
    auto searchStudents = database_.searchBySurname("Polak");
    auto searchStudent = database_.searchBySurname("Pawlak");

    // THEN
    ASSERT_EQ("Polak", searchStudents[0]->getSurname());
    ASSERT_EQ("Polak", searchStudents[1]->getSurname());
    ASSERT_EQ(2, searchStudents.size());

    ASSERT_EQ("Pawlak", searchStudent[0]->getSurname());
    ASSERT_EQ(1, searchStudent.size());
}

TEST_F(databaseOperation, SearchStudentsByPESEL) {
    // GIVEN

    // WHEN
    auto searchStudent1 = database_.searchByPESEL("111");
    auto searchStudent2 = database_.searchByPESEL("99042006789");

    // THEN
    ASSERT_EQ(nullptr, searchStudent1);
    ASSERT_EQ("Pawlak", searchStudent2->getSurname());
}

TEST_F(databaseOperation, SortStudentsByPESEL) {
    // GIVEN

    // WHEN
    auto sortedStudents = database_.sortStudentsByPESEL();

    // THEN
    ASSERT_EQ("97063006601", sortedStudents[0]->getPESEL());
    ASSERT_EQ("98042006789", sortedStudents[1]->getPESEL());
    ASSERT_EQ("99042006789", sortedStudents[2]->getPESEL());
}

TEST_F(databaseOperation, SortStudentsBySurname) {
    // GIVEN
    database_.addStudent("Tom", "Znak", "K 1, 62-860 Opa", "91063006601", Gender::Male, 113);

    // WHEN
    auto sortedStudents = database_.sortStudentsBySurname();

    // THEN
    ASSERT_EQ("Pawlak", sortedStudents[0]->getSurname());
    ASSERT_EQ("Znak", sortedStudents[3]->getSurname());
}

TEST_F(databaseOperation, RemoveStudentByIndexNumber) {
    // GIVEN

    // WHEN
    database_.removeStudentByIndexNumber(111);
    std::vector<std::shared_ptr<Person>> db = database_.getStudents();

    // THEN
    ASSERT_EQ(112, db[0]->getIndexNumber());
    ASSERT_EQ(113, db[1]->getIndexNumber());

}