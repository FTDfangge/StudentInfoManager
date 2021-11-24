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
    char log1[255];
    snprintf(log1, 255, "ADD; STUID: %d;", (*student).stuId);
    logWrite(log1);
} //Add a student into the list

void delete(int stuId, struct StudentList** list){
    //judge if the student exist in the list.
    struct StudentList* listPtr = *list;
    while (listPtr){
        if(listPtr->data.stuId == stuId){
            printf("\nstudent found, it will be deleted ");

            if(listPtr->pre == NULL){
                *list = listPtr->next;
            } else{
                listPtr->pre->next = listPtr->next;
                listPtr->next->pre = listPtr->pre;
            }

            deleteDBSync(stuId);
            char log2[255];
            snprintf(log2, 255, "DELETE; STUID: %d;", stuId);
            logWrite(log2);
            return;
        }
        listPtr = listPtr->next;
    }
} //Delete a student from the list

void modifyStudentInList(int stuId, struct StudentList** list){
    //judge if the student exist in the list.
    struct StudentList* listPtr = *list;
    while (listPtr){
        if(listPtr->data.stuId == stuId){
            printf("\nstudent found, plz input the new data(except student id) "
                   "format like this(name gender age CScore EngScore):\n");
            scanf("%s %s %d %d %d",listPtr->data.name, listPtr->data.gender, &(listPtr->data.age),
                  &(listPtr->data.CScore), &(listPtr->data.EngScore));

            modifyDBSync(&(listPtr->data));
            char log2[255];
            snprintf(log2, 255, "MODIFY; STUID: %d;", stuId);
            logWrite(log2);
            return;
        }
        listPtr = listPtr->next;
    }
} //Modify student

struct Student* getStudent(int stuId){

} //Get a student struct

