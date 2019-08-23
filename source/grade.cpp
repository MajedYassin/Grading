#include <vector>
#include <stdexcept>
#include <algorithm>
#include "../include/grade.h"


//Calculates homework grade
double median(std::vector<double>& vec){
    typedef std::vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0){
        throw std::domain_error("Empty vector of grades!");
    }
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    double median = size % 2 == 0 ? (vec[mid - 1] + vec[mid]) /2 : vec[mid];
    return median;
}

double grade(double midterm, double finals, std::vector<double>& hw){
    if (hw.size() == 0) {
        throw std::domain_error("No homework was done");
    }
    return grade(midterm, finals, median(hw));
}

double grade(double midterm, double finals, double median){
    return 0.4*finals + 0.2*midterm + 0.4*median;
}

