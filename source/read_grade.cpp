#include "../include/Student_Info.h"
#include "../include/grade.h"
#include <limits>
#include <list>

//Sorting Student names in alphabetic order
bool compare(const Student_Info & x, const Student_Info & y){
    return x.name < y.name;
}

//Requesting USer input for Student_Info parameters: name, final and midterm grade
//Request User input of homework grades to send to read_hw
std::istream& read(std::istream& is, Student_Info& s, std::string& end) {
    std::cout << "What is the student's name? ";
    is >> s.name;
    std::cout << std::endl;
    std::cout << "What were your midterm and final exam grades: ";
    is >> s.midterm >> s.finals;
    std::cout << "What are the homework grades: ";
    read_hw(is, s.homework);
    std::cout << "Are there any more students? ";
    is >> end;
    return is;
}

//Take Homework grade input and push into vector hw
std::istream& read_hw(std::istream& in, std::vector<double>& hw){
    if(in){
        hw.clear();
        double x;
        while (in >> x){
            hw.push_back(x);
            }
    }
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}


//Fail grade Criteria
bool fgrade(Student_Info& s){
    return grade(s) < 60;
}

/*
//Separating Pass and Fail grades into vectors
std::vector<Student_Info> extract_fails(std::vector<Student_Info>& students){
    std::vector<Student_Info> pass, fail;

    std::vector<Student_Info>::size_type i = 0;

    while(i != students.size()){
        if(fgrade(students[i])){
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else {
            ++i;
        }
    }
    students = pass;
    return fail;
}*/

//Re-written Pass/Fail vector as a list using iterators as opposed to indices
std::list<Student_Info> extract_fails(std::vector<Student_Info>& students){
    std::vector<Student_Info>::iterator iter = students.begin();
    std::list<Student_Info> fail;
    while(iter != students.end()){
        if(fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}


