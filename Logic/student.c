//
// Created by raynor on 2021-11-23.
//

#include "student.h"

void modifyStudent(struct Student* student){//Modify the student passed in
    printf("\nPlz input the new information of the student:\nstudentId, name, gender, age, CScore, EngScore:");
    scanf("%d %s %s %d %d %d",
          &(*student).stuId, (*student).name, (*student).gender, &(*student).age,
          &(*student).CScore, &(*student).EngScore);
    printf("\nModified.\n");
}

void printStudentInfo(struct Student* student) { //Print all info of the student
    printf("\n| %d | %s | %s | %d | %d | %d |\n",
            (*student).stuId, (*student).name, (*student).gender, (*student).age,
            (*student).CScore, (*student).EngScore);
}