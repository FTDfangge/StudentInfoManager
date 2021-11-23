cmake_minimum_required(VERSION 3.20)
project(Code C)

set(CMAKE_C_STANDARD 99)

set(INC_DIR C:/Program\ Files/MySQL/MySQL\ Server\ 8.0/include)

set(LINK_DIR C:/Program\ Files/MySQL/MySQL\ Server\ 8.0/lib)

include_directories(${INC_DIR})

link_directories(${LINK_DIR})
link_libraries(libmysql)

add_executable(Code main.c dependencies.h
        View View/userInterface.c View/userInterface.h
        Logic Logic/student.c Logic/student.h Logic/studentList.c
        DataAccess DataAccess/dataAccess.h DataAccess/dataBaseOperation.c)
target_link_libraries(Code libmysql)