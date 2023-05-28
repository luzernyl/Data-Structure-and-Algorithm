#include "BinarySearchTree.h"
#include <iostream>

int main(int argc, char* argv[])
{
  BinaryTree A;
   A.insert(6);
    A.insert(3);
    A.insert(9);
    A.insert(1);
    A.insert(2);
    A.insert(7);
    A.insert(11);
    A.insert(5);
    A.insert(4);
    A.insert(4);
    A.test_successor();
    A.min();
    A.max();
    A.test_predecessor();
    A.address();
    std::cout << "Address of 11 : "<< A.tree_search(11) << std::endl;
    std::cout << "Address of 8  : "<< A.tree_search(8) << std::endl;
    std::cout << "Address of 20 : "<< A.tree_search(20) << std::endl;
    std::cout << "Address of 0  : "<< A.tree_search(0) << std::endl;
    A.inorder_treewalk();
    std::cout << "Deleting 3..." << std::endl;
    A.del(A.tree_search(3));
    A.inorder_treewalk();
    std::cout << "Deleting 9..." << std::endl;
    A.del(A.tree_search(9));
    A.inorder_treewalk();
  return 0;
};
