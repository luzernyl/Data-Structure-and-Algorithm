#include <iostream>
#include "RedBlackIntervalTree.h"

int main (int argc, char *argv[])
{
  RedBlackIntervalTree<double> A;
  A.insert(17.5, 19.8);
  A.insert(21.2, 23.1);
  A.insert(5.6, 11.4);
  A.insert(15.35, 18.28);
  A.insert(4.67, 8.95);
  A.insert(7.34, 10.87);
  A.insert(20.45, 24.98);
  A.insert(18.35, 25.8);
  std::cout << "Format : [low, high, max]" << std::endl;
  A.inorder_treewalk();

  std::cout << std::endl;
  
  RedBlackIntervalTree<double>::Node* x = A.test_interval_search(14.65, 16.32);
  std::cout << "Interval overlapping with [14.65, 16.32] : " << std::endl;
  if (x != NULL)
    std::cout << "[" << x->low << " , " << x->high << "]" << std::endl;
  else
    std::cout << "This interval does not overlap with any interval in the tree !" << std::endl;

  x = A.test_interval_search(12.4, 14.8);
  std::cout << "Interval overlapping with [12.4, 14.8] : " << std::endl;
  if (x != NULL)
    std::cout << "[" << x->low << " , " << x->high << "]" << std::endl;
  else
    std::cout << "This interval does not overlap with any interval in the tree !" << std::endl;

  std::cout << std::endl;

  std::cout << "Deleting [15.35, 18.28]..." << std::endl;
  A.del(15.35, 18.28);
  A.inorder_treewalk();
  std::cout << std::endl;
  std::cout << "Deleting [18.35, 25.8]..." << std::endl;
  A.del(18.35, 25.8);
  A.inorder_treewalk();
  std::cout << std::endl;
  std::cout << "Deleting [20.45, 24.98]..." << std::endl;
  A.del(20.45, 24.98);
  A.inorder_treewalk();
  std::cout << std::endl;
  return 0;
};
