
#ifndef GUARD_Student_Info
#define GUARD_Student_Info

#include <vector>
#include <string>
#include <iostream>

struct Student_Info{
    double midterm, finals;
    std::vector<double> homework;
    std::string name;
    //Constructor
    Student_Info(){
        midterm = 0.0;
        finals = 0.0;
        homework.clear();
    }
};

#endif //UNTITLED_STUDENT_INFO_H
