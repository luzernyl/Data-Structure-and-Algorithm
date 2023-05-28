# Quick Sort

We know that the standard quicksort algorithm is unstable. Actually there are some ways to solve this problem. For example, record the original subscripts of the data, and after sorting, sort the same elements according to their original subscripts.

For example: the input array is A = [0: 3.1, 1: 1.7, 2:6.4, 3:1.7, 4: 3.1], after sorting it, the result is

A = [3: 1.7, 1:1.7, 4:3.1, 0:3.1, 2:6.4], where the original subscript before the colon. Obviously this result is unstable. Now we only need to sort the two 1.7 and the two 3.1 according to their original subscripts, and we can get a stable result:

A = [1: 1.7, 3:1.7, 0:3.1, 4:3.1, 2:6.4].

Please write a program to implement this algorithm.

Requirement :

1. The structure of a single data is:
```cpp
class DATA
{
private:
  int index;
  double val;
};
```

Please consider the necessary construction, destruction and interface yourself.

2. Please use vector to construct the sorted array:
```cpp
int n;
std::vector<DATA> A(n);
```

Please decide how to input and output test data from text, and teach yourself how to complete vector initialization and data assignment (reminder: you can refer to my code, or cplusplus.com).

3. Complete the stable quick sort, given the function:
```cpp
int stable_quick_sort(std::vector<DATA> &_A);
```

Design other required intermediate link functions by yourself.