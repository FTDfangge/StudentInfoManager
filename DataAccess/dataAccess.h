//
// Created by raynor on 2021-11-23.
//

#ifndef CODE_DATAACCESS_H
#define CODE_DATAACCESS_H
#include "../dependencies.h"
#include "../Logic/student.h"

void printDatabase();
void initializeFromDatabase(struct StudentList** list);
void addDBSync(struct Student* stu);
void deleteDBSync();
void modifyDBSync();

void sortById(struct StudentList** list); //Sort the list by id
void sortByName(struct StudentList** list); //Sort the list by name
void sortByGender(struct StudentList** list); //Sort the list by gender
void sortByAge(struct StudentList** list); //Sort the list by age
void sortByCScore(struct StudentList** list); //Sort the list by C score
void sortByEngScore(struct StudentList** list); //Sort the list by English score

#endif //CODE_DATAACCESS_H



