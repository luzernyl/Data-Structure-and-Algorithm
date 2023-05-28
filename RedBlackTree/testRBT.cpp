#include <iostream>
#include "RedBlackTree.h"

int main (int argc, char *argv[])
{
  RedBlackTree<int> A;
  A.insert(16);
  A.insert(8);
  A.insert(24);
  A.insert(4);
  A.insert(12);
  A.insert(20);
  A.insert(28);
  A.insert(2);
  A.insert(6);
  A.insert(10);
  A.insert(14);
  A.insert(18);
  A.insert(22);
  A.insert(26);
  A.insert(30);
  A.insert(1);
  A.insert(3);
  A.insert(5);
  A.insert(7);
  A.insert(9);
  A.insert(11);
  A.insert(13);
  A.insert(15);
  A.insert(17);
  A.insert(19);
  A.insert(21);
  A.insert(23);
  A.insert(25);
  A.insert(27);
  A.insert(29);
  A.insert(31);
  A.inorder_treewalk();
  
  RedBlackTree<int>::Node* r = A.getRoot();
  // Deleting 20
  A.del(r->rc->lc);
  A.inorder_treewalk();
  // Deleting 8
  A.del(r->lc);
  A.inorder_treewalk();
  return 0;
};
