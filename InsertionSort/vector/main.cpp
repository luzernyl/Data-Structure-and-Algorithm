/**
 * @file   main.cpp
 * @author Heyu Wang <hywang@walker-7.local>
 * @date   Wed Jul 29 18:42:06 2020
 * 
 * @brief  An implementation of Insertion Sort 
 * by using vector.
 *
 */

#include <iostream>
#include <cstdlib>
#include <vector>

/** 
 * An insertion sort with vector.
 * 
 * @param _arr a vector for the input numbers.  
 * 
 * @return error code. The sorted output sequence 
 * will store and update in _arr. 
 */
int insertionSort(std::vector<double> &_arr);

int insertionSort(std::vector<double> &_arr)
{
    for (int j = 1; j < _arr.size(); j++)
    {
	double key = _arr[j];
	// Insert A[j] into the sorted sequence A[1...j-1].
	int i = j - 1;
	while (i >= 0 && _arr[i] > key)
	{
	    _arr[i + 1] = _arr[i];
	    i = i - 1;
	}
	_arr[i + 1] = key;
    }
    return 0;
};

/// naive version.
// #define N 5			/**< for array length. */

// int main(int argc, char *argv[])
// {
//     int A[N] = {3, 1, 4, 7, 2};
//     INSERTION_SORT(A, N);
//     std::cout << "A: ";
//     for (int i = 0; i < N; i++)
// 	std::cout << A[i] << " ";
//     std::cout << std::endl;
//     return 0;
// };

/// C-style version.
// int main(int argc, char *argv[])
// {
//     int N = -1;
//     std::cin >> N;
//     double *A = NULL;
//     if ((A = (double *)std::malloc(sizeof(double) * N)) == NULL)
//     {
// 	std::cerr << "No enough memory" << std::endl;
// 	std::exit(-1);
//     }
//     for (int i = 0; i < N; i++)
// 	std::cin >> A[i];
//     INSERTION_SORT(A, N);
//     insertionSort(A);
//     std::cout << "A: ";
//     for (int i = 0; i < N; i++)
// 	std::cout << A[i] << " ";
//     std::cout << std::endl;
//     return 0;
// };

/// vector version.
int main (int argc, char *argv[])
{
    int n = -1;
    std::cin >> n;
    std::vector<double> arr(n);
    for (std::vector<double>::iterator arr_iterator = arr.begin();
	 arr_iterator != arr.end();
	 ++arr_iterator)
	std::cin >> *arr_iterator;
    insertionSort(arr);
    std::cout << "A: ";
    for (std::vector<double>::iterator arr_iterator = arr.begin();
	 arr_iterator != arr.end();
	 ++arr_iterator)
	std::cout << *arr_iterator << " ";
    std::cout << std::endl;
    return 0;
};
