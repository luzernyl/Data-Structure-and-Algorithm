/**
 * @file   RedBlackIntervalTree.h
 * @author Luzern Yuven Luis <student@student>
 * @date   Sun Dec 20 16:10:51 2020
 * 
 * @brief  An implementation of Red Black Interval Tree
 * 
 * 
 */


#include "IntervalTree.h"
#include <iostream>

template <class TYPE>
class RedBlackTree;

template <class TYPE>
class RedBlackIntervalTree : public IntervalTree<TYPE>
{
 public :
  typedef typename IntervalTree<TYPE>::Node Node;

  /** 
   * Create a new tree with only 
   * one node containing the given interval.
   * 
   * @param _low low endpoint of given interval
   * @param _high high endpoint of given interval
   * 
   */
 RedBlackIntervalTree(TYPE _low, TYPE _high) : IntervalTree<TYPE>(_low,_high)
    {
      this->root->color = BLACK;
      this->low = _low;
      this->high = _high;
      this->maximum = _high;
    };

  /** 
   * Default Constructor
   * 
   *  
   */
  RedBlackIntervalTree(){};
  int insert(Node* _x);
  int insert(TYPE _low, TYPE _high);
  int del(Node* _x);
  int del(TYPE _low, TYPE _high);
  Node* interval_search(Node* _x);
  Node* test_interval_search(TYPE _low, TYPE _high);
};

/** 
 * Insert a node while maintaining
 * red-black properties and maximum values.
 * 
 * @param _x the node to be inserted.
 * 
 * @return NULL
 */
template <class TYPE>
int RedBlackIntervalTree<TYPE>::insert(Node* _x)
{
  Node* x = _x;
  IntervalTree<TYPE>::insert(x);
  x->color = RED;
  //If x's parent is black, no problem
  if (x->parent->color == BLACK)
    {
      //Do nothing
      this->root->color = BLACK;
      return 0;
    }
  // If x's parent is red, Problem !
  while (x->parent != this->nil && x->color==RED)
    {
      if (x->parent == x->parent->parent->lc)
	{
	  //y is uncle of x
	  Node* y = x->parent->parent->rc;
	  if (y->color == RED)
	    {
	      //case 1 : recolor and recurse on new x 
	      x->parent->color = y->color = BLACK;
	      x->parent->parent->color = RED;
	      x = x->parent->parent;
	      if (x->parent->color == BLACK)
		break;
	    }
	  else
	    {
	      if (x == x->parent->rc)
		{
		  //case 2 : LeftRotate x's parent
		  this->LeftRotate(x->parent);
		  x = x->lc;
		}
	      //case 3 : recolor and RightRotate x's grandparent
	      x->parent->color = BLACK;
	      x->parent->parent->color = RED;
	      this->RightRotate(x->parent->parent);
	      x = x->parent;
	    }
	}
      else if (x->parent == x->parent->parent->rc)
	{
	  // y is uncle of x
	  Node* y = x->parent->parent->lc;
	  if (y->color == RED)
	    {
	      //case 1 : recolor and recurse on new x
	      x->parent->color = y->color = BLACK;
	      x->parent->parent->color = RED;
	      x = x->parent->parent;
	      if (x->parent->color == BLACK)
		break;
	    }
	  else
	    {
	      if (x == x->parent->lc)
		{
		  //case 2 : RightRotate x's parent
		  this->RightRotate(x->parent);
		  x = x->rc;
		}
	      //case 3 : recolor and LeftRotate x's grandparent
	      x->parent->color = BLACK;
	      x->parent->parent->color = RED;
	      this->LeftRotate(x->parent->parent);
	      x = x->parent;
	    }
	}
    }
  this->root->color = BLACK;
};

/** 
 * Insert a node with the given interval while
 * maintaining red-black properties and 
 * maximum values
 * 
 * @param _low low endpoint of given interval
 * @param _high high endpoint of given interval
 * 
 * @return NULL
 */
template <class TYPE>
int RedBlackIntervalTree<TYPE>::insert(TYPE _low, TYPE _high)
{
  Node* x = new Node(_low, _high);
  insert(x);
  return 0;
};

/** 
 * Delete a node while maintaining
 * red-black properties and maximum values.
 * 
 * @param _x the node to be deleted
 * 
 * @return NULL
 */
template <class TYPE>
int RedBlackIntervalTree<TYPE>::del(Node* _x)
{
  Node* y = _x;
  bool original_color_y = y->color;
  Node* x;
  
  // x has no left child
  if (_x->lc == this->nil)
    {
      x = _x->rc;
      // replaces _x with _x's right child
      this->transplant(_x, _x->rc);
    }
  
  // x has no right child
  else if (_x->rc == this->nil)
    {
      x = _x->lc;
      // replaces _x with _x's left child
      this->transplant(_x, _x->lc);
    }
  
  // x has two children
  else
    {
      // y is _x's successor
      y = this->min(_x->rc);
      // Always make the color of the succeeding node
      // the same as the color of the deleted node
      original_color_y = y->color;
      x = y->rc;
      if (y->parent != _x) // y is not _x's direct child
	{
	  // y's right child replaces y
	  this->transplant(y, y->rc);
	  // make _x's right child as y's right child
	  y->rc = _x->rc;
	  y->rc->parent = y;
	}
      // replaces _x with its successor
      this->transplant(_x, y);
      y->lc = _x->lc;
      y->lc->parent = y;
      y->color = x->color;
      // Now y has replaces _x's position
    }
  // BST delete complete

  // Start fixing maximum values
  Node* p = _x->parent;
  while(p->maximum == _x->high)
    {
      if (p->lc == this->nil && p->rc == this->nil) //p has no child
	p->maximum = p->high;
      else if (p->lc == this->nil && p->rc != this->nil) // p has a right child
	{
	  if (p->rc->maximum > p->high)
	    p->maximum = p->rc->maximum;
	  else
	    p->maximum = p->high;
	}
      else if (p->lc != this->nil && p->rc == this->nil) // p has a left child
	{
	  if (p->lc->maximum > p->high)
	    p->maximum = p->lc->maximum;
	  else
	    p->maximum = p->high;
	}
      else // p has two children
	p->maximum = IntervalTree<TYPE>::max(p,p->lc,p->rc);
      
      p = p->parent;
    }
  
  
  // Start fixing red-black problems
  // Only fix if the deleted node is black
  // If red then directly delete
  if (original_color_y == BLACK)
    {
      while (x != this->root && x->color == BLACK)
	{
	  // If x is a left child
	  if (x == x->parent->lc)
	    {
	      // w is x's sibling
	      Node* w = x->parent->rc;
	      // case 1
	      // w is red
	      if (w->color == RED)
		{
		  w->color = BLACK;
		  x->parent->color = RED;
		  this->LeftRotate(x->parent);
		  // Redefine w as x's parent right child
		  w = x->parent->rc;
		}
	      // Continue to case 2
	      // Now solving black height problem in x's tree
	      // w's children are both black
	      if (w->lc->color == BLACK && w->rc->color == BLACK)
		{
		  w->color = RED;
		  // Redefine x as x's parent
		  x = x->parent;
		}
	      else
		{
		  // case 3
		  // w's children have different colors
		  if (w->rc->color == BLACK)
		    {
		      w->lc->color = BLACK;
		      w->color = RED;
		      this->RightRotate(w);
		      // Redefine w as its parent
		      w = x->parent->rc;
		    }
		  // Continue to case 4
		  // w's children are both red
		  w->color = x->parent->color;
		  x->parent->color = BLACK;
		  w->rc->color = BLACK;
		  this->LeftRotate(x->parent);
		  // set x as root to terminate while loop
		  x = this->root;
		}
	    }
	  // x is a right child
	  else if (x == x->parent->rc)
	    {
	      // w is x's sibling
	      Node* w = x->parent->lc;
	      // case 1 : w is red
	      if (w->color == RED)
		{
		  w->color = BLACK;
		  x->parent->color = RED;
		  this->RightRotate(x->parent);
		  // Redefine w as x's parent left child
		  w = x->parent->lc;
		}
	      // Continue to case 2
	      // Now solving black height problem in x's subtree
	      // w's children are both black
	      if (w->rc->color == BLACK && w->lc->color == BLACK)
		{
		  w->color = RED;
		  // Redefine x as x's parent
		  x = x->parent;
		}
	      else
		{
		  // case 3
		  // w's children has different colors
		  if (w->lc->color = BLACK)
		    {
		      w->rc->color = BLACK;
		      w->color = RED;
		      this->LeftRotate(w);
		      // Redefine w as its parent
		      w = x->parent->lc;
		    }
		  // Continue to case 4
		  // w's children are both red
		  w->color = x->parent->color;
		  x->parent->color = BLACK;
		  w->lc->color = BLACK;
		  this->RightRotate(x->parent);
		  // set x as root to terminate while loop
		  x = this->root;
		}
	    }
	}
    }
  // color root as BLACK
  x->color = BLACK;
  delete _x;
  return 0;
};

/** 
 * Deletes a node with the given interval.
 * Only deletes one if there is more than one.
 * 
 * @param _low low endpoint of given interval
 * @param _high high endpoint of given interval
 * 
 * @return 0
 */
template <class TYPE>
int RedBlackIntervalTree<TYPE>::del(TYPE _low, TYPE _high)
{
  Node* x = IntervalTree<TYPE>::tree_search(_low,_high);
  if (x != NULL)
    del(x);
  else
    std::cout << "There is no such interval in the tree !" << std::endl;
  return 0;
};

/** 
 * Finds an interval that overlaps the interval in the given node
 * 
 * @param _x the given node
 * 
 * @return the overlapping interval, NULL if not found
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* RedBlackIntervalTree<TYPE>::interval_search(Node* _x)
{
  Node* x = this->root;
  while (x != this->nil && (_x->low > x->high || x->low > _x->high) ) // testing not overlap
    // doesn't overlap
    {
      if (x->lc != this->nil && _x->low <= x->lc->maximum)
	x = x->lc;
      else
	x = x->rc;
    }
  if (x != this->nil)
    return x;
  else
    return NULL;
};

/** 
 * Finds an interval that overlaps the given interval
 * 
 * @param _low low endpoint of given interval
 * @param _high high endpoint of given interval
 * 
 * @return the overlapping interval, NULL if not found
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* RedBlackIntervalTree<TYPE>::test_interval_search(TYPE _low, TYPE _high)
{
  Node* i = new Node(_low,_high);
  Node* x = interval_search(i);
  delete i;
  return x;
};
