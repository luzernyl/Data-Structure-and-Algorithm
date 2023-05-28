/**
 * @file   main.cpp
 * @author Luzern Yuven Luis <student@student>
 * @date   Mon Oct 19 22:52:02 2020
 * 
 * @brief  An implementation of a stable quicksort.
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>

class DATA
{
private:
  int index;   //starting index of every number
  double val;  //number to be sorted

public:
  /** 
   * Default constructor.
   * 
   */
  DATA()
  {
    index = -1;
    val = 0;
  };
  /** 
   * Constructor to initalize
   * 
   * @param ind the array index of each number
   * @param j the value of each number
   */
  DATA(int ind, double j)
  {
    index = ind;
    val = j;
  };
  /** 
   * To set index for every element in the array
   * 
   * @param i the index of every element.
   * 
   * @return index
   */
  int set_index(int i)
  {
    index = i;
    return index;
  };

  /** 
   * To set the value for an element in the array
   * 
   * @param j the value of the element
   * 
   * @return value
   */
  double set_value(double j)
  {
    val = j;
    return val;
  };
  /** 
   * To get the index of element
   * 
   * 
   * @return the index of the element
   */
  int get_index()
  {
    return index;
  };

  /** 
   * To get the value for an element
   * 
   * 
   * @return the value of the element
   */
  double get_value()
  {
    return val;
  };



};

/** 
 * A stable quicksort, first sort array according to value, then sort identical  * elements according to index.
 * 
 * @param A the array to be sorted.
 * @param m the number of elements in the array
 * 
 * @return sorted array
 */
int stable_quick_sort(std::vector<DATA> &A, int m);

/** 
 * quicksort to sort elements according to value.
 * 
 * @param A array to be sorted
 * @param a the starting element 
 * @param b the last element
 * 
 * @return a sorted array
 */
int quicksort(std::vector<DATA> &A, int a, int b);

/** 
 * Partitioning the array according to the value of the elements
 * 
 * @param A array to be partitioned.
 * @param p the starting element
 * @param q the last element
 * 
 * @return index of pivot element.
 */
int partition(std::vector<DATA> &A,int p, int q);

/** 
 * Partitioning the array according to the index of the elements.
 * 
 * @param A1 the array to be sorted, containing elements with identical
 *            values but different indices.
 * @param p the starting element
 * @param q the last element
 * 
 * @return index of pivot element.
 */
int partition_index(std::vector<DATA> &A1, int p,int q);

/** 
 * Quicksort an array according to the index of the elements.
 * 
 * @param A1 the array to be sorted, containing elements with identical
 *           values but different indices.
 * @param c the starting element.
 * @param d the last element
 * 
 * @return a sorted array
 */
int quicksort_index(std::vector<DATA> &A1, int c, int d);

/** 
 * A function to printout array
 * 
 * @param A the array to be printed.
 * 
 * @return print array
 */
int printout(std::vector<DATA> &A);

int stable_quick_sort(std::vector<DATA> &A)
{
  int n = A.size();
    if (n > 3)
    {
      int  p = partition(A, 0, n-1);
        quicksort(A, 0, p);
	quicksort(A, p + 1, n-1);
    }
    else
    {
	if (n == 0 || n == 1)
	    return 0;
	else if (n == 2)
	{
	  if (A[0].get_value() > A[1].get_value())
	    {
	        DATA tmp = A[0];
		A[0] = A[1];
	        A[1] = tmp;
	    }
	      return 0;
	}
	else if (n == 3)
	{
	  DATA  tmp;
	  if (A[1].get_value() <= A[0].get_value() &&
	      A[1].get_value() <= A[2].get_value())
	    {
	      if (A[0].get_value() <= A[2].get_value())
		{
		    tmp = A[1];
		    A[1] = A[0];
		    A[0] = tmp;
		}
	      else if (A[0].get_value() >= A[2].get_value())
		{
		    tmp = A[2];
		    A[2] = A[0];
		    A[0] = A[1];
		    A[1] = tmp;
		}
	    }
	  else if (A[2].get_value() <= A[0].get_value()
		   && A[2].get_value() <= A[1].get_value())
	    {
	      if (A[0].get_value() <= A[1].get_value())
		{
		    tmp = A[0];
		    A[0] = A[2];
		    A[2] = A[1];
		    A[1] = tmp;

		    
		}
	      else if (A[0].get_value() >= A[1].get_value())
		{
		    tmp = A[2];
		    A[2] = A[0];
		    A[0] = tmp;
		}
	    }
	}
    }
    //std::vector<DATA> A1;
    for (int i = 0; i < n; i++)
      {
	if (A[i].get_value() == A[i+1].get_value())
	  {
	    std::vector<DATA> A1;
	    int memo = i; //save the index of the starting element of A1
		int j = i+1;
		A1.push_back(A[i]); //insert identical elements to a new array
		while (A[j].get_value() == A[i].get_value())
		  {
		    A1.push_back(A[j]);
		    j++;
		  }
		int memo1 = j; //save the index of the last element of A1
		int m = A1.size();
                int p1 = partition_index(A1, 0, m-1);
                quicksort_index(A1, 0, p1);
                quicksort_index(A1, p1+1, m-1);
     
                int k = 0;
		//replace sorted elements to array.
                for(int i = memo; i < j; i++)
                {
		  A[i] = A1[k]; 
		   k++;
                }
	  }
      }
     
};

int quicksort(std::vector<DATA> &A, int a, int b)
{
  int n = A.size();
    if (b-a > 0)
    {
      int p = partition(A, a, b);
	quicksort(A, a, p);
	quicksort(A, p + 1, b);
    }      
};

int quicksort_index(std::vector<DATA> &A1, int c, int d)
{
  int m = A1.size();
  if (d-c > 0)
    {
      int p2 = partition_index(A1, c, d);
      quicksort_index(A1, c , p2);
      quicksort_index(A1, p2+1, d);
    }
};

int partition(std::vector<DATA> &A, int p, int q)
{
  int n = q-p+1;
  if (n <= 0)
	return 0;
    int left = p;
    int right = q;
    DATA  pivot = A[p];
    while (left != right)
    {
      while (A[right].get_value() >= pivot.get_value() && right > left)
	    right--;
      while (A[left].get_value() <= pivot.get_value() && right > left)
	    left++;
	if (right > left)
	{
	    DATA tmp = A[left];
	    A[left] = A[right];
	    A[right] = tmp;
	    right--;
	}
    }
    A[p] = A[left];
    A[left] = pivot;
    return left;
};

int partition_index(std::vector<DATA> &A1, int p, int q)
{
  int m = q-p+1;
  if (m <= 0)
	return 0;
    int left = p;
    int right = q;
    DATA  pivot = A1[p];
    while (left != right)
    {
      while (A1[right].get_index() >= pivot.get_index() && right > left)
	    right--;
      while (A1[left].get_index() <= pivot.get_index() && right > left)
	    left++;
	if (right > left)
	{
	    DATA tmp = A1[left];
	    A1[left] = A1[right];
	    A1[right] = tmp;
	    right--;
	}
    }
    A1[p] = A1[left];
    A1[left] = pivot;
    return left;
};

int printout(std::vector<DATA> &A)
{
  int n = A.size();
  for (int i = 0; i < n; i++)
    {
      std::cout<< A[i].get_index() << " : " << A[i].get_value()<< " ,";
    }
  std::cout<< std::endl;
 };

int main (int argc, char*argv[])
{
  typedef std::chrono::high_resolution_clock myclock;
  int n = -1;
  std::cin >> n;
  std::vector<DATA> A;
  std::vector<int> arr(n);
  double j;
  for (std::vector<int>::iterator arr_iterator = arr.begin();
       arr_iterator != arr.end();
       ++arr_iterator)
    std::cin >> *arr_iterator;
  for (int i = 0; i < n; i++)
    {
      std::cin >> arr[i];
      DATA da = DATA(i,arr[i]);
      A.push_back(da);
      A[i].set_value(arr[i]);
    }
  
  for (int i = 0; i < n; i++)
    {
      A[i].set_index(i);
    }
  printout(A);
  // Start the timer.
  myclock::time_point beginning = myclock::now();
  stable_quick_sort(A);
  // Stop the timer.
  myclock::duration d = myclock::now() - beginning;
  printout(A);
  for(std::vector<int>::iterator arr_iterator = arr.begin();
      arr_iterator != arr.end();
      ++arr_iterator)
    std::cout << *arr_iterator << " ";
  std::cout << std::endl;
  std::cout << "time: "<< d.count() << std::endl;
  return 0;
};

