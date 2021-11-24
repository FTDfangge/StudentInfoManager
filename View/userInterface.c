//
// Created by raynor on 2021-11-23.
//

#include "userInterface.h"

void UImenu(){
    struct StudentList* studentList = (struct StudentList*) malloc(sizeof (struct StudentList));
    studentList->pre = NULL;
    studentList->next = NULL;
    initializeFromDatabase(&studentList);
    while(true){
        printf("\n=====Student Information management System=====\n");
        printf("=====Menu=====\n");
        printf("1. Display all students\n");
        printf("2. Sort the display\n");
        printf("3. Add student\n");
        printf("4. Modify student\n");
        printf("5. Delete student\n");
        printf("6. Search\n");
        printf("7. Check log file\n");
        printf("8. exit\n");
        printf("Plz input the choice(1~7): ");
        int choice=0;
        scanf("%d",&choice);
        switch (choice) {
            case 1:{
                UIdisplay();
                break;
            }
            case 2:{
                UIsort(&studentList);
                break;
            }
            case 3:{
                UIaddStu(&studentList);
                break;
            }
            case 4:{
                UImodify(&studentList);
                break;
            }
            case 5:{
                UIdeleteStu(&studentList);
                break;
            }
            case 6:{
                UIsearch(&studentList);
                break;
            }
            case 7:{
                UIlog();
                break;
            }
            case 8:{
                exit(0);
            }
            default:{
                break;
            }
        }
    }
}

void UImodify(struct StudentList** list){

}

void UIdeleteStu(struct StudentList** list){

}

void UIaddStu(struct StudentList** list){
    printf("\n=====Add a student=====\n");

    struct Student* student = (struct Student*) malloc(sizeof (struct Student));
    printf("Plz input the student info:\n"
           "studentId: ");
    scanf("%d",&(*student).stuId);
    printf("\nstudent name: ");
    scanf("%s",(*student).name);
    printf("\nstudent gender: ");
    scanf("%s",(*student).gender);
    printf("\nstudent age: ");
    scanf("%d", &(*student).age);
    printf("\nstudent C score: ");
    scanf("%d", &(*student).CScore);
    printf("\nstudent English score: ");
    scanf("%d", &(*student).EngScore);
    printf("\nAdding...\n");

    add(student, list);

}

void UIdisplay(){
    //Directly call the data access layer
    printDatabase();
}

void UIsort(struct StudentList** list){
    printf("\n1. Student id\n2. name\n3. gender\n4. age\n5. C score\n6. English Score\n");
    printf("\nPlz select the attribute to sort: ");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
        case 1:{
            sortById();
            break;
        }
        case 2:{
            sortByName();
            break;
        }
        case 3:{
            sortByGender();
            break;
        }
        case 4:{
            sortByAge();
            break;
        }
        case 5:{
            sortByCScore();
            break;
        }
        case 6:{
            sortByEngScore();
            break;
        }
        default:
            break;
    }
}

void UIsearch(struct StudentList** list){

}

void UIlog(){

}
