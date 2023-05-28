/**
 * @file   Merge.h
 * @author Luzern Yuven Luis <student@student>
 * @date   Mon Oct 12 23:06:34 2020
 * 
 * @brief  An implementation of MergeSort.
 * 
 * 
 */

//#ifndef ___MERGE_SORT__
#define __MERGE_SORT__
#include <vector>
#include <limits>
#include "Student.h"

/** 
 * Merge two sorted array parts to a sorted one.
 * 
 * @param _A The object array.
 * @param _p The start index for the first sorted part.
 * @param _q The last index for the first part.
 * @param _r The last index for the second sorted part.
 * 
 * @return int Error code. 0 for OK.
 */
int Merge(std::vector<Student> &_A, int _p, int _q, int _r);

/** 
 * Apply Merge Sort by Divide-and-Conquer strategy.
 * 
 * @param _A The object array.
 * @param _p The start index to sort.
 * @param _q The last index to sort.
 * 
 * @return int Error code. 0 for OK.
 */
int _MergeSort(std::vector<Student> &_A, int _p, int _q);
/** 
 * A user interface for Merge Sort, just call _MergeSort.
 * 
 * @param _A The object array
 * 
 * @return int Error code. 0 for OK
 */
int arrange(std::vector<Student> &_A);

/** 
 * To printout the sorted array
 * 
 * 
 * @return Sorted array
 */
int printmerge(std::vector<Student> &_A);
