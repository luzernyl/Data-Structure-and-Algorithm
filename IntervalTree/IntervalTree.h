/**
 * @file   IntervalTree.h
 * @author Luzern Yuven Luis <student@student>
 * @date   Sun Dec 20 16:30:09 2020
 * 
 * @brief  An implementation of Interval Tree
 * 
 * 
 */

#include <iostream>
#include <cstdlib>
#include <limits>

#define BLACK false
#define RED true

#define MIN (std::numeric_limits<TYPE>::min())
#define MAX (std::numeric_limits<TYPE>::max())


template <class TYPE>
class IntervalTree
{
protected:
    class Node
    {
    public:
      TYPE data;
      TYPE low; //low endpoint
      TYPE high; //high endpoint
      TYPE maximum; //maximum value
      Node* lc; //left child
      Node* rc; //right child
      Node* parent;
      Node(TYPE _low, TYPE _high);
      Node(){};
      bool color = RED;
    };
    Node* root;
    Node* nil;
    void inorder_treewalk(Node* _x) const;
    void release(Node* _x);
    //Node* successor(Node* _x) const;
    //Node* predecessor(Node* _x) const;
    Node* min(Node* _x) const;
    Node* max(Node* _x) const;
    void address(Node* _x) const;
    
public:
    IntervalTree()
      {
	nil = new Node;
	nil->color = BLACK;
	nil->low = MIN;
	nil->high = MAX;
	nil->maximum = MAX;
	root = nil;
      };
    IntervalTree(TYPE _low, TYPE high);
    ~IntervalTree();
    int LeftRotate(Node* _x);
    int RightRotate(Node* _x);
    int insert(Node* _x);
    int insert(TYPE _low, TYPE _high);
    int del(Node* _x);
    int del(TYPE _low, TYPE _high);
    void inorder_treewalk() const;
    Node* successor(Node* _x) const;
    Node* predecessor(Node* _x) const;
    void test_successor();
    void test_predecessor();
    Node* tree_search(TYPE _low, TYPE _high);
    Node* min();
    Node* max();
    TYPE max(Node* _x, Node* _y, Node* _z);
    void address() const;
    int transplant(Node* _u, Node* _v);
   
};

/** 
 * Right rotate a node with the subtree under it 
 * while maintaining maximum values.
 * 
 * @param _x the node to be rotated.
 * 
 * @return NULL
 */
template <class TYPE>
int IntervalTree<TYPE>::RightRotate(Node* _x)
{
  Node *y = _x->lc;
  _x->lc = y->rc;
  if (y->rc != nil)
    y->rc->parent = _x;
  y->parent = _x->parent;
  if (_x->parent == nil)
    root = y;
  else if (_x == _x->parent->lc)
    _x->parent->lc = y;
  else
    _x->parent->rc = y;
  y->rc = _x;
  _x->parent = y;
   // Maintain maximum value
  y->maximum = _x->maximum;
  if (_x->lc != nil && _x->rc != nil)
    _x->maximum = max(_x, _x->lc, _x->rc);
  else if (_x->lc == nil && _x->rc != nil)
    {
      if (_x->rc->maximum > _x->high)
	_x->maximum = _x->rc->maximum;
      else
	_x->maximum = _x->high;
    }
  else if (_x->lc != nil && _x->rc == nil)
    {
      if (_x->lc->maximum = _x->high)
	_x->maximum = _x->lc->maximum;
      else
	_x->maximum = _x->high;
    }
  else
    _x->maximum = _x->high;
};

/** 
 * Left rotate a node with the subtree
 * under it while maintaining maximum values.
 * 
 * @param _x the node to be rotated 
 * 
 * @return NULL
 */
template <class TYPE>
int IntervalTree<TYPE>::LeftRotate(Node* _x)
{
  Node *y = _x->rc;
  _x->rc = y->lc;  // turn y's left subtree into _x's right subtree
  if (y->lc != nil)
    y->lc->parent = _x;
  y->parent = _x->parent; // link _x's parent to y
  if (_x->parent == nil)
    root = y;
  else if (_x == _x->parent->rc)
    _x->parent->rc = y;
  else
    _x->parent->lc = y;
  y->lc = _x; // put _x on y's left
  _x->parent = y;
  // Maintain maximum value
  y->maximum = _x->maximum;
  if (_x->lc != nil && _x->rc != nil)
    _x->maximum = max(_x, _x->lc, _x->rc);
  else if (_x->lc == nil && _x->rc != nil)
    {
      if (_x->rc->maximum > _x->high)
	_x->maximum = _x->rc->maximum;
      else
	_x->maximum = _x->high;
    }
  else if (_x->lc != nil && _x->rc == nil)
    {
      if (_x->lc->maximum = _x->high)
	_x->maximum = _x->lc->maximum;
      else
	_x->maximum = _x->high;
    }
  else
    _x->maximum = _x->high;
  
};

/** 
 * Releases/deletes a node with the subtree below it
 * 
 * @param _x the node to be released
 */
template <class TYPE>
void IntervalTree<TYPE>::release(Node* _x)
{
    if (_x != this->nil)
    {
	release(_x->lc);
	release(_x->rc);
	delete _x;
    }	
};

/** 
 * Default destructor
 * 
 */
template <class TYPE>
IntervalTree<TYPE>::~IntervalTree()
{
    release(root);
};

/** 
 * Creates a node containing the given interval.
 * 
 * @param _low low endpoint of given interval.
 * @param _high high endpoint of given interval.
 * 
 * @return new node containing the given interval.
 */
template <class TYPE>
IntervalTree<TYPE>::Node::Node(TYPE _low, TYPE _high)
{
  low = _low;
  high = _high;
  maximum = _high;
  parent = lc = rc = NULL;
};


/** 
 * Searches the location of the node containing the interval given
 * If there are more than one node, return the first one  met.
 * 
 * @param _low low endpoint of given interval
 * @param _high high endpoint of given interval
 * 
 * @return address of the interval in the tree. NULL if not found
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* IntervalTree<TYPE>::tree_search(TYPE _low, TYPE _high)
{
  Node* x = root;
  bool flag = false;
  while (flag == false)
  {
      if (_low < x->low && x->lc != this->nil)
	{
	      x = x->lc;
	      if (_low == x->low && _high == x->high)
		{
		  flag = true;
		  return x;
		}
	}
      else if (_low > x->low && x->rc != this->nil)
	{
	      x = x->rc;
	      if(_low == x->low && _high == x->high)
		{
		  flag = true;
		  return x;
		}
	    
	}
  }
  if (flag == false)
    return NULL;
};


/** 
 * Find the node with the largest low endpoint less than the
 * low endpoint of _x
 *
 * @param _x The start node.
 * 
 * @return The address of the predecessor node.
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* IntervalTree<TYPE>::predecessor(Node* _x) const
{
  Node* x = _x;
  if (x->lc != this->nil)
    return max(x->lc);
  Node* y = x->parent;
  while(y != this->nil && x == y->lc)
    {
      x = y;
      y = y->parent;
    }
  return y;
};

/** 
 * Returns the interval of the predecessor node
 * 
 */
template <class TYPE>
void IntervalTree<TYPE>::test_predecessor()
{
  Node* x = predecessor(root->lc->rc);
  std::cout << "Predecessor: ["<< x->low << " , " << x->high << "]" << std::endl;
};

/** 
 * Find the node with the smallest low endpoint larger than the 
 * low endpoint of _x
 *
 * @param _x The start node
 * 
 * @return The address of the successor node.
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* IntervalTree<TYPE>::successor(Node* _x) const
{
    Node* x = _x;
    if (x->rc != this->nil)
	return min(x->rc);
    Node* y = x->parent;
    while (y != this->nil && x == y->rc)
    {
	x = y;
	y = y->parent;
    }
    return y;
};

/** 
 * Returns the interval of the successor node.
 * 
 */
template <class TYPE>
void IntervalTree<TYPE>::test_successor()
{
    Node* x = successor(root->lc->lc);
    std::cout << "successor: [" << x->low << " , " << x->high << "]" << std::endl;
};


/** 
 * Find the smallest low endpoint in the whole tree
 * 
 * 
 * @return the smallest low endpoint
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* IntervalTree<TYPE>::min()
{
  Node *x = min(root);
  std::cout << x->low << std::endl;
};

/** 
 * Find the smallest low endpoint under the node _x
 * 
 * @param _x The start node
 * 
 * @return The address of the node with the smallest low endpoint
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* IntervalTree<TYPE>::min(Node* _x) const
{
    while (_x->lc != this->nil)
	_x = _x->lc;
    return _x;
};

/** 
 * Find the maximum low endpoint in the whole tree
 * 
 * 
 * @return The maximum low endpoint
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* IntervalTree<TYPE>::max()
{
  Node* x = max(root);
  std::cout << x->low << std::endl;
};

/** 
 * Find the largest low endpoint under a node
 * 
 * @param _x the start node
 * 
 * @return address of the node containing the largest low endpoint
 */
template <class TYPE>
typename IntervalTree<TYPE>::Node* IntervalTree<TYPE>::max(Node* _x) const
{
    while (_x->rc != this->nil)
	_x = _x->rc;
    return _x;
};

/** 
 * Compares the values of the high endpoint of a node
 * to the maximum values of its children
 * 
 * @param _x the node
 * @param _y left child
 * @param _z right child
 * 
 * @return the largest maximum value of the three
 */
template <class TYPE>
TYPE IntervalTree<TYPE>::max(Node* _x, Node* _y, Node* _z)
{
  if (_x->high >= _y->maximum && _x->high >= _z->maximum)
    return _x->high;
  if (_y->maximum >= _x->high && _y->maximum >= _z->maximum)
    return _y->maximum;
  else
    return _z->maximum;
};

/** 
 * Sorts the tree from smallest to largest
 * 
 */
template <class TYPE>
void IntervalTree<TYPE>::inorder_treewalk() const
{
    inorder_treewalk(root);
    std::cout << std::endl;
};

/** 
 * Sorts the node and the subtree under it 
 * from smallest to largest
 *
 * @param _x The start node 
 */
template <class TYPE>
void IntervalTree<TYPE>::inorder_treewalk(Node* _x) const
{
    if (_x != this->nil)
    {
	inorder_treewalk(_x->lc);
	std::cout << "[" << _x->low << " , " << _x->high << " , " << _x->maximum << "]" << "\t";
	inorder_treewalk(_x->rc);
    }
};

/** 
 * Prints the address of each node in the whole tree
 * 
 */
template <class TYPE>
void IntervalTree<TYPE>::address() const
{
  address(root);
  std::cout<< std::endl;
};

/** 
 * Prints the address of every node under the start node
 * 
 * @param _x The start node
 */
template <class TYPE>
void IntervalTree<TYPE>::address(Node* _x) const
{
  if (_x != this->nil)
    {
      address(_x->lc);
      std::cout << "Address of ["<< _x->low << " , " << _x->high << "] : "<< _x << std::endl;
      address(_x->rc);
    }
};

/** 
 * Inserts a node with the given interval
 * 
 * @param _low low endpoint of the given interval
 * @param _high high endpoint of the given interval
 * 
 * @return NULL
 */
template <class TYPE>
int IntervalTree<TYPE>::insert(TYPE _low, TYPE _high)
{
  Node* x = new Node(_low, _high);
  insert(x);
  return 0;
};

/** 
 * Insert a new node into the tree while maintaining
 * BST properties and maximum values
 * 
 * @param _data the node to be inserted
 */
template <class TYPE>
int IntervalTree<TYPE>::insert(Node* _x)
{
    Node* y = this->nil;
    Node* x = this->root;
    _x->lc = _x->rc = this->nil;
    while (x != this->nil)
    {
	y = x;
	if (_x->maximum > x->maximum)
	  x->maximum = _x->maximum;
	if (_x->low  < x->low)
	    x = x->lc;
	else
	    x = x->rc;
    }
    _x->parent = y;
    if (y == this->nil)
	this->root = _x;
    else if (_x->low < y->low)
	y->lc = _x;
    else
	y->rc = _x;
    return 0;
};

/** 
 * Transplants a node and the subtree under it 
 * with a new subtree
 * 
 * @param _u The original node
 * @param _v The new node
 * 
 * @return NULL
 */
template <class TYPE>
int IntervalTree<TYPE>::transplant(Node* _u, Node* _v)
{
  if (_u == NULL)
    {
      std::cerr << "Cannot transplant to a NULL !" << std::endl;
      std::exit(-1);
    }
  if (_u->parent == this->nil) // _u is root
    {
      root = _v;
      root->maximum = _u->maximum;
    }
  else if (_u == _u->parent->lc) // _u is a left child
    {
      _u->parent->lc = _v;
    }
  else // _u is a right child
    {
      _u->parent->rc = _v;
    }
  //if (_v != NULL)
  _v->parent = _u->parent;
  return 0;
};

/** 
 * Deletes a node in the tree while maintaining
 * BST properties and maximum values
 * 
 * @param _x the node to be deleted
 * 
 * @return NULL
 */
template <class TYPE>
int IntervalTree<TYPE>::del(Node* _x)
{
  if (_x->lc == this->nil)
    {
      this->transplant(_x, _x->rc);
    }
  else if (_x->rc == this->nil)
    {
      this->transplant(_x, _x->lc);
    }
  else
    {
      //search for x's successor, to maintain BST property
      Node* y = min(_x->rc);
      if (y->parent != _x)   //y is not _x's child
	{
	  this->transplant(y, y->rc); //only changes y's position, y is still recorded
	  y->rc = _x->rc; //set x's right child as y's right child to connect _x's right subtree to y
	  y->rc->parent = y;
	}
      this->transplant(_x, y); //y replaces _x's position, bringing _x's whole right subtree with it
      y->lc = _x->lc;       //make _x left subtree y's left subtree
      y->lc->parent = y;
    }
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
	p->maximum = max(p,p->lc,p->rc);
      
      p = p->parent;
    }
  delete _x;
  return 0;
};

template <class TYPE>
int IntervalTree<TYPE>::del(TYPE _low, TYPE _high)
{
   Node* x = tree_search(_low,_high);
  if (x != NULL)
    del(x);
  else
    std::cout << "There is no such interval in the tree !" << std::endl;
  return 0;
};
/** 
 * Constructor. Creates a new tree with only a node
 * containing the given interval
 * 
 * @param _data The given interval.
 */
template <class TYPE>
IntervalTree<TYPE>::IntervalTree(TYPE _low, TYPE _high)
{
    nil = new Node;
    nil->color = BLACK;
    nil->low = MIN;
    nil->high = MAX;
    Node *r = new Node;
    r->low = _low;
    r->high = _high;
    r->maximum = _high;
    r->lc = nil;
    r->rc = nil;
    r->parent = nil;
    root = r;
};

