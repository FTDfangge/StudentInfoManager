//
// Created by raynor on 2021-11-23.
//

#ifndef CODE_USERINTERFACE_H
#define CODE_USERINTERFACE_H
#include "../dependencies.h"
#include "../DataAccess/dataAccess.h"

void UImenu();
void UIdisplay();
void UIaddStu(struct StudentList** list);
void UImodify(struct StudentList** list);
void UIdeleteStu(struct StudentList** list);
void UIsort(struct StudentList** list);
void UIsearch(struct StudentList** list);



#endif //CODE_USERINTERFACE_H
