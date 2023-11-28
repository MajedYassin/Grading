# Grading

## Description 
The program takes a list user input studen names, alongside the respective grades from each students coursework, midterm and final exams then:
- Calculates the overall final grade of each student, based on a pre-defined grade weighting; 
- Sorts the students into a list ordered from highest to lowest grade;  
- Calculates the Median grade of said list of students;


## Technology 
Software Requirements: 
- language: C++ version 11.
- CMake minimum version 3.14.

## Setup 
clone project file from Git address and load CMake project in build folder: 

```
$ git clone "https://github.com/MajedYassin/Grading.git"
$ cd <cloned repository>
$ mkdir build 
$ cd build
$ cmake ..
$ make -j "number of threads available" 

```
