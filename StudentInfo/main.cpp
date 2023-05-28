#include "Student.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Merge.h"


int main (int argc, char *argv[])
{
  Student student1 = Student(1234,'M',3.5);
  Student student2 = Student(2901,'P',4.0);
  Student student3 = Student(3921,'C',3.8);
  Student arr[]={student1,student2,student3};
  Heap A(arr,3);
  A.printout();
  A.sort_m();
  A.printout();
  std::vector<Student> v;
  v =  A.change();
  arrange(v);
  printmerge(v);
  return 0;
};
