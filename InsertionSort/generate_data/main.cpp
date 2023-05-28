/**
 * @file   main.cpp
 * @author Heyu Wang <hywang@walker-7.local>
 * @date   Sat Aug  8 09:59:10 2020
 * 
 * @brief  Generate integer ramdon sequence, and 
 * the seeds are provided by a timer from chrono lib.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
#include <chrono>

int bigsmall(std::vector<double> &_arr);

int bigsmall(std::vector<double> &_arr)
{
    for (int j = 1; j < _arr.size(); j++)
    {
	double key = _arr[j];
	// Insert A[j] into the sorted sequence A[1...j-1].
	int i = j - 1;
	while (i >= 0 && _arr[i] < key)
	{
	    _arr[i + 1] = _arr[i];
	    i = i - 1;
	}
	_arr[i + 1] = key;
    }
    return 0;
};

int main(int argc, char *argv[])
{
    typedef std::chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();
    // Just do something ...
    int n = -1;
    if (argc != 2)
	n = 1;
    else
	n = std::atoi(argv[1]);
    std::vector<double> arr(n);
    // obtain a seed from the timer
    myclock::duration d = myclock::now() - beginning;
    unsigned seed = d.count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (std::vector<double>::iterator arr_iterator = arr.begin();
	 arr_iterator != arr.end();
	 ++arr_iterator)
	*arr_iterator = dist(generator);
    std::cout << n << " ";
    /*for (std::vector<double>::iterator arr_iterator = arr.begin();
	 arr_iterator != arr.end();
	 ++arr_iterator)
	std::cout << *arr_iterator << " ";
	std::cout << std::endl;*/
    bigsmall(arr);
    for(int i = 0; i < n; i++)
      {
	std::cout << arr[i] << " ";
      }
    std::cout << std::endl;
    return 0;
};
