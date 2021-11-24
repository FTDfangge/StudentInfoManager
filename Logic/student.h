//
// Created by raynor on 2021-11-23.
//

#ifndef CODE_STUDENT_H
#define CODE_STUDENT_H

#include "../dependencies.h"
#include "../DataAccess/dataAccess.h"

struct Student{
    int stuId;
    char name[30];
    char gender[1];
    int age;
    int CScore;
    int EngScore;
};

void modifyStudent(struct Student* student); //Modify the student passed in
void printStudentInfo(struct Student* student); //Print all info of the student

struct StudentList{
    struct Student data;
    struct StudentList* next;
    struct StudentList* pre;
};

void add(struct Student* student, struct StudentList** list); //Add a student into the list
void delete(int stuId, struct StudentList** list); //Delete a student from the list
void modifyStudentInList(int stuId, struct StudentList** list); //Modify student
struct Student* getStudent(int stuId); //Get a student struct

#endif //CODE_STUDENT_H

