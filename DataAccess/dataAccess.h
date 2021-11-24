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
void deleteDBSync(int stuId);
void modifyDBSync(struct Student* stu);

void sortById(); //Sort the list by id
void sortByName(); //Sort the list by name
void sortByGender(); //Sort the list by gender
void sortByAge(); //Sort the list by age
void sortByCScore(); //Sort the list by C score
void sortByEngScore(); //Sort the list by English score
void search(char* attribute, char* value); //Search by "attribute" and value is "value".

void logPrint(); //Print the log file
void logWrite(char* string); //Write to the log file

#endif //CODE_DATAACCESS_H



