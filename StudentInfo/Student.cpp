#include "Student.h"
#include <cstdlib>
#include <iostream>
#include <vector>

Student::Student()
{
  std_no = -1;
  major = 'M';
  GPA = 0;
};

Student::Student(int stdnum, char maj, double gpa)
{
  std_no = stdnum;
  major = maj;
  GPA = gpa;
  if (major == 'M')
    major_num = 1;
  if (major == 'C')
    major_num = 2;
  if (major == 'P')
    major_num = 3;
};

int Student::get_major_num()
{
  return major_num;
};

char Student::get_major()
{
  return major;
 };

int Student::get_std_no()
{
  return std_no;
};

double Student::get_GPA()
{
  return GPA;
};

int Student::modify_GPA(double g)
{
  GPA = g;
  return 0;
};

Heap::Heap()
{
    data = NULL;
    length = 0;
};

Heap::Heap(Student *datahead, int l)
{
    data = new Student[l];
    for (int i = 0; i < l; i++)
      data[i] = datahead[i];
    length = l;
    for (int i = PARENT(l - 1); i >= 0; i--)
	shiftdown(i);
};

Heap::~Heap()
{
    delete[] data;
};


int Heap::get_length()
{
    return length;
};

int Heap::get_height()
{
    int l = length;
    int digits = 1;
    while (l >>= 1 != 0)
	digits++;
    return digits;
};

bool Heap::is_empty()
{
    bool result = false;
    if (length == 0)
	result = true;
    return result;
};

int Heap::shiftdown(int i)
{
    int lc = LEFTCHILD(i);
    if (lc >= length)
	return 0;
    int child = lc;
    int rc = RIGHTCHILD(i);
    if (rc < length && data[rc].get_major_num() > data[lc].get_major_num())
	child = rc;
    if (data[i].get_major_num() < data[child].get_major_num())
    {
	Student tmp = data[i];
	data[i] = data[child];
	data[child] = tmp;
	shiftdown(child);
    }
    else
	return 0;
};

int Heap::printout()
{
    for (int i = 0; i < length; i++)
      {std::cout << data[i].get_major() << " " << data[i].get_std_no() << " "
		 << data[i].get_GPA()<< " ";}
    std::cout << std::endl;
    return 0;
};

int Heap::sort_m()
{
    int l = length;
    while (length > 0)
    {
	Student tmp = data[0];
	data[0] = data[length - 1];
	data[length - 1] = tmp;
	length--;
	shiftdown(0);
    }
    length = l;
    return 0;
};

std::vector<Student> Heap::change()
{
  std::vector<Student> v;
  for (int i = 0; i < length; i++)
    {v.push_back(data[i]);}
  return v;
};
