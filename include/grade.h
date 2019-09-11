#ifndef GRADING_GRADE_H
#define GRADING_GRADE_H

#include <vector>
#include <list>
#include "Student_Info.h"

bool compare(const Student_Info& , const Student_Info& );

std::istream& read(std::istream&, Student_Info& , std::string&);
std::istream& read_hw(std::istream&, std::vector<double>&);

double median(std::vector<double>& vec);

double grade(Student_Info& s);

double grade(double, double, double);

//double grade(double, double, std::vector<double>& );

bool fgrade(Student_Info& s);

std::list<Student_Info> extract_fails(std::vector<Student_Info>& students);

#endif //UNTITLED_GRADE_H
