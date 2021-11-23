//
// Created by raynor on 2021-11-23.
//

#include "userInterface.h"

void UImenu(){
    while(true){
        printf("\n=====Student Information management System=====\n");
        printf("=====Menu=====\n");
        printf("1. Display all students\n");
        printf("2. Sort the display\n");
        printf("3. Add student\n");
        printf("4. Modify student\n");
        printf("5. Delete student\n");
        printf("6. Search\n");
        printf("7. exit\n");
        printf("Plz input the choice(1~7): ");
        int choice=0;
        scanf("%d",&choice);
        switch (choice) {
            case 1:{
                UIdisplay();
                break;
            }
            case 2:{
                UIsort();
                break;
            }
            case 3:{
                UIaddStu();
                break;
            }
            case 4:{
                UImodify();
                break;
            }
            case 5:{
                UIdeleteStu();
                break;
            }
            case 6:{
                UIsearch();
                break;
            }
            case 7:{
                exit(0);
            }
            default:{
                break;
            }
        }
    }
}

void UImodify(){

}

void UIdeleteStu(){

}

void UIaddStu(){

}

void UIdisplay(){

}

void UIsort(){

}

void UIsearch(){

}