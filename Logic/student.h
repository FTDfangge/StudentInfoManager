//
// Created by raynor on 2021-11-23.
//

#ifndef CODE_STUDENT_H
#define CODE_STUDENT_H

#endif //CODE_STUDENT_H
#include "../dependencies.h"

struct Student{
    int stuId;
    char name[30];
    char gender;
    int age;
    int CScore;
    int EngScore;
};

void modifyStudent(struct Student* student); //Modify the student passed in
void printStudentInfo(struct Student* student); //Print all info of the student

struct StudentList{
    struct Student data;
    struct Student* next;
    struct Student* pre;
};

void initializeFromDatabase(struct StudentList** list);
void writeToDatabase(struct StudentList** list);

void add(struct Student* student, struct StudentList** list); //Add a student into the list
void delete(int stuId, struct StudentList** list); //Delete a student from the list
void modifyStudent(int stuId, struct StudentList** list); //Modify student
struct Student* getStudent(int stuId); //Get a student struct
void sortById(struct StudentList** list); //Sort the list by id
void sortByName(struct StudentList** list); //Sort the list by name
void sortByGender(struct StudentList** list); //Sort the list by gender
void sortByAge(struct StudentList** list); //Sort the list by age
void sortByCScore(struct StudentList** list); //Sort the list by C score
void sortByEngScore(struct StudentList** list); //Sort the list by English score
