/**
 * @file   merge.cpp
 * @author Luzern Yuven Luis <student@student>
 * @date   Mon Oct 12 22:06:50 2020
 * 
 * @brief  An implementation of Mergesort.
 * 
 * 
 */


#include <vector>
#include <limits>
#include "Student.h"
#include "Merge.h"
#include <iostream>

int Merge(std::vector<Student> &_A, int _p, int _q, int _r)
{
    int n1 = _q - _p + 1;
    int n2 = _r - _q;
    std::vector<Student> L(n1 + 1);
    std::vector<Student> R(n2 + 1);
    for (int i = 0; i < n1; i++)
        L[i] = _A[_p + i];
    for (int i = 0; i < n2; i++)
        R[i] = _A[_q + 1 + i];
    const int infty = std::numeric_limits<double>::max();
    L[n1].modify_GPA(infty);
    R[n2].modify_GPA(infty);
    int i = 0;
    int j = 0;
    for (int k = _p; k < _r + 1; k++)
    {
      if (L[i].get_GPA() <= R[j].get_GPA())
        {
            _A[k] = L[i];
            i++;
        }
        else
        {
            _A[k] = R[j];
            j++;
        }
    }
    return 0;
};

int _MergeSort(std::vector<Student> &_A, int  _p, int _r)
{
    int q;
    if (_p < _r)
    {
        q = (_p + _r) / 2;
        _MergeSort(_A, _p, q);
        _MergeSort(_A, q + 1, _r);
        Merge(_A, _p, q, _r);
    }
    return 0;
};

int arrange(std::vector<Student> &_A)
{
    _MergeSort(_A, 0, _A.size() - 1);
    return 0;
};

int printmerge(std::vector<Student> &_A)
{
  for (int i = 0; i < _A.size() ; i++)
    {
      std::cout << _A[i].get_major() << " " << _A[i].get_std_no() << " " <<
	_A[i].get_GPA() << " ";
    }
  std::cout << std::endl;
  return 0;
};
