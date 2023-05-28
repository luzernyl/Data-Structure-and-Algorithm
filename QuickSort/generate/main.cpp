#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
#include <chrono>

int main(int argc, char *argv[])
{
  typedef std::chrono::high_resolution_clock myclock;
  myclock::time_point beginning = myclock::now();
  int n = -1;
  if (argc != 2)
    n = 1;
  else
    n = std::atoi(argv[1]);
  std::vector<int> arr(n);
  // obtain a seed from the timer
  myclock::duration d = myclock::now() - beginning;
  unsigned seed = d.count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> dist(0, 100);
  for (std::vector<int>::iterator arr_iterator = arr.begin();
       arr_iterator != arr.end();
       ++arr_iterator)
    *arr_iterator = dist(generator);
  std::cout << n << " ";
  for (std::vector<int>::iterator arr_iterator = arr.begin();
       arr_iterator != arr.end();
       ++arr_iterator)
    std::cout<< *arr_iterator << " ";
  std::cout << std::endl;
  return 0;
}
