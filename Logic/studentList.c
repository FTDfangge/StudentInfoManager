//
// Created by raynor on 2021-11-23.
//

#include "student.h"

void add(struct Student* student, struct StudentList** list){
    //judge if the student exist in the list.
    struct StudentList* listPtr = *list;
    while (listPtr){
        if(listPtr->data.stuId == (*student).stuId){
            printf("\nERROR: The student is already existed, add failed.\n");
            return;
        }
        listPtr = listPtr->next;
    }

    //Add to the list
    struct StudentList* newnode = (struct StudentList*) malloc(sizeof (struct StudentList));
    newnode->data = *student;
    newnode->pre = NULL;
    newnode->next = *list;
    (*list)->pre = newnode;
    *list = newnode;
    addDBSync(student);
} //Add a student into the list

void delete(int stuId, struct StudentList** list){

} //Delete a student from the list

void modifyStudentInList(int stuId, struct StudentList** list){

} //Modify student

struct Student* getStudent(int stuId){

} //Get a student struct

