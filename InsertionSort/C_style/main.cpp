/**
 * @file   main.cpp
 * @author Heyu Wang <hywang@walker-7.local>
 * @date   Wed Jul 29 18:42:06 2020
 * 
 * @brief  A C-style implementation of the following pseudo code
 * of insertion sort.
 *
 * INSERTION-SORT(A)
 * 1 for j = 2 to A.length
 * 2 	key = A[j]
 * 3 	// Insert A[j] into the sorted sequence A[1...j-1].
 * 4 	i = j - 1
 * 5 	while i >0 and A[i] > key
 * 6 		A[i + 1] = 1 A[i]
 * 7 		i = i - 1
 * 8 	A[i + 1] = key
 * 
 */

#include <iostream>
#include <cstdlib>

/** 
 * A C-style insertion sort.
 * 
 * @param A a input number sequence.  
 * @param length the length of the input.
 * 
 * @return error code. The sorted output sequence 
 * will store and update in A. 
 */
int INSERTION_SORT(double A[], int length);

int INSERTION_SORT(double A[], int length)
{
    for (int j = 1; j < length; j++)
    {
	double key = A[j];
	// Insert A[j] into the sorted sequence A[1...j-1].
	int i = j - 1;
	while (i >= 0 && A[i] > key)
	{
	    A[i + 1] = A[i];
	    i = i - 1;
	}
	A[i + 1] = key;
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

/// normal version.
int main(int argc, char *argv[])
{
    int N;
    std::cin >> N;
    double *A = NULL;
    if ((A = (double *)std::malloc(sizeof(double) * N)) == NULL)
    {
	std::cerr << "No enough memory" << std::endl;
	std::exit(-1);
    }
    for (int i = 0; i < N; i++)
	std::cin >> A[i];

    INSERTION_SORT(A, N);
    std::cout << "A: ";
    for (int i = 0; i < N; i++)
	std::cout << A[i] << " ";
    std::cout << std::endl;
    return 0;
};
