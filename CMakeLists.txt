cmake_minimum_required(VERSION 3.20)
project(Code C)

set(CMAKE_C_STANDARD 99)

add_executable(Code main.c dependencies.h
        View View/userInterface.c View/userInterface.h
        Logic Logic/student.c Logic/student.h Logic/studentList.c
        DataAccess DataAccess/dataAccess.h DataAccess/dataBaseOperation.c)
