//
// Created by raynor on 2021-11-23.
//
#include "dataAccess.h"

void finish_with_error(MYSQL* con){
    printf("%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void printDatabase(){
    MYSQL* con = mysql_init(NULL);
    if (con == NULL)
    {
        finish_with_error(con);
    }
    if (mysql_real_connect(con, "localhost", "user1", "123456",
                           "sims", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "SELECT * FROM students"))
    {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;


    while ((row = mysql_fetch_row(result)))
    {
        for(int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);
}

void initializeFromDatabase(struct StudentList** list){
    struct StudentList* pointer = *list;

    MYSQL* con = mysql_init(NULL);
    if (con == NULL)
    {
        finish_with_error(con);
    }
    if (mysql_real_connect(con, "localhost", "user1", "123456",
                           "sims", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "SELECT * FROM students"))
    {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        //Each row is a student
        struct Student student;
        student.stuId = atoi(row[0]);
        strcpy(student.name, row[1]);
        strcpy(student.gender, row[2]);
        student.age = atoi(row[3]);
        student.CScore = atoi(row[4]);
        student.EngScore = atoi(row[5]);
        pointer->data = student; //Firstly, store the current student in the current node.

        //Then construct a new node for the next.
        struct StudentList* listNode = (struct StudentList*) malloc(sizeof (struct StudentList));
        listNode->pre = pointer;
        listNode->next = NULL;
        pointer->next = listNode;
        pointer = listNode;


        printf("\n");
    }
    pointer->pre->next = NULL;

    mysql_free_result(result);
    mysql_close(con);
}

void addDBSync(struct Student* stu){
    MYSQL* con = mysql_init(NULL);
    if (con == NULL)
    {
        finish_with_error(con);
    }
    if (mysql_real_connect(con, "localhost", "user1", "123456",
                           "sims", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    char sql[255];
    snprintf(sql, 255, "INSERT INTO students VALUES(%d,'%s','%s',%d,%d,%d);",
             (*stu).stuId, (*stu).name, (*stu).gender, (*stu).age, (*stu).CScore, (*stu).EngScore);
    if (mysql_query(con, sql)){
        finish_with_error(con);
    }
    printf("inserted into the database!\n");
    mysql_close(con);
}

void deleteDBSync(){
    MYSQL* con = mysql_init(NULL);
    if (con == NULL)
    {
        finish_with_error(con);
    }
    if (mysql_real_connect(con, "localhost", "user1", "123456",
                           "sims", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }
}

void modifyDBSync(){
    MYSQL* con = mysql_init(NULL);
    if (con == NULL)
    {
        finish_with_error(con);
    }
    if (mysql_real_connect(con, "localhost", "user1", "123456",
                           "sims", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }
}

void sortById(struct StudentList** list){

} //Sort the list by id

void sortByName(struct StudentList** list){

} //Sort the list by name

void sortByGender(struct StudentList** list){

} //Sort the list by gender

void sortByAge(struct StudentList** list){

} //Sort the list by age

void sortByCScore(struct StudentList** list){

} //Sort the list by C score

void sortByEngScore(struct StudentList** list){

} //Sort the list by English score