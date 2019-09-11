#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>
#include <list>
#include "../include/grade.h"
#include "../include/Student_Info.h"

int main() {
    std::cout << "Hello, welcome to the grade calculator" << std::endl;
    //Calculating homework grades
    std::vector<double> homework;
    //read_hw(std::cin, homework);<--(to read and store an individual set of homework grades)

    std::vector<Student_Info> students;
    Student_Info record;
    std::string::size_type maxlen = 0;
    std::string end;

    while (read(std::cin, record, end)) {
        maxlen = std::max(maxlen, record.name.size());
        students.push_back(record);
        if(end == "No"){
            break;
        }
    }

    //Sorting the individual record of Student info objects in alphabetical order

    std::sort(students.begin(), students.end(), compare);
    std::cout << std::endl;

    std::list<Student_Info> fail;
    extract_fails(students);

    for (std::vector<Student_Info>::size_type i = 0; i != students.size(); ++i)
    {
        std::cout << students[i].name << std::string (maxlen + 1 - students[i].name.size(), ' ');

        //compute and write the grade
        try {
            double final_grade = grade(students[i]);
            std::streamsize sf = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade << std::setprecision(sf) << std::endl;
        }
        catch (std::domain_error& e) {
            std::cout << e.what();
        }
    }


    for (std::list<Student_Info>::iterator iter = fail.begin(); iter != (fail.end()); ++iter)
    {
        std::cout << (*iter).name << std::string (maxlen + 1 - (*iter).name.size(), ' ');

        //compute and write the grade
        try {
            double fail_grade = grade((*iter));
            std::streamsize sf = std::cout.precision();
            std::cout << std::setprecision(3) << fail_grade << std::setprecision(sf) << std::endl;
        }
        catch (std::domain_error& e) {
            std::cout << e.what();
        }
    }
    return 0;
}