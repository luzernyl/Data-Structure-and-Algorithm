# Organize Student Information

The structure of student information is :
```cpp
class Student
{
private:
  int std_no;    // Student number, every student has a unique ID number.
  char major;    // Student major marked by one character, M for math, P for 
                 // Physics, C for Chemistry.    
  double GPA;    // GPA range: 0 ~ 5
};
```

Design a C++ algorithm with :
1. Function 
```cpp
int sort_m(Student *A, int n);
```

2. Function
```cpp
int arrange(Student *A, int n);
```

Array A stores the data of n students. Use MergeSort to sort the results of Question 1 (already sorted by major) on the basis of GPA; observe the stability of MergeSort.

Work requirements:

1. Write a report of no more than 2 A4 pages giving your observations and conclusions.

2. Submit a project file package: Student.zip. After decompression, the folder Student is required. There is a file Student.h in it, including all class and function definitions; there is a file Student.cpp in it, including all function implementations; there is a file main in it .cpp, including the main program and all test codes; there is a file Makefile inside, which can generate the executable file main and run the test.

3. Fill in the missing parts by yourself, consider the content and format of the test data, and design the test content by yourself.