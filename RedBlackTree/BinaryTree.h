/**
 * @file   BinarySearchTree.h
 * @author student <student@student>
 * @date   Sun Nov 29 01:43:42 2020
 * 
 * @brief  An implementation of Binary Search Tree
 * 
 * 
 */
#include <iostream>
#include <cstdlib>
#include <limits>

#define BLACK false
#define RED true

#define MIN (std::numeric_limits<TYPE>::min())

//typedef int T;


template <class TYPE>
class BinaryTree
{
protected:
    class Node
    {
    public:
	TYPE data;
	Node* lc; //left child
	Node* rc; //right child
	Node* parent;
	Node(TYPE _data);
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
    BinaryTree()
      {
	nil = new Node;
	nil->color = BLACK;
	nil->data = MIN;
	root = nil;
      };
    BinaryTree(TYPE _data);
    ~BinaryTree();
    Node* getRoot();
    int LeftRotate(Node* _x);
    int RightRotate(Node* _x);
    int insert(Node* _x);
    int insert(TYPE _data);
    void inorder_treewalk() const;
    Node* successor(Node* _x) const;
    Node* predecessor(Node* _x) const;
    void test_successor();
    void test_predecessor();
    Node* tree_search(TYPE _data);
    Node* min();
    Node* max();
    void address() const;
    int transplant(Node* _u, Node* _v);
    int del(Node* _x);
};

/** 
 * Right rotate a node with the subtree under it.
 * 
 * @param _x the node to be rotated.
 * 
 * @return NULL
 */
template <class TYPE>
int BinaryTree<TYPE>::RightRotate(Node* _x)
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
  else _x->parent->rc = y;
  y->rc = _x;
  _x->parent = y;
};

/** 
 * Left rotate a node with the subtree
 * under it.
 * 
 * @param _x the node to be rotated 
 * 
 * @return NULL
 */
template <class TYPE>
int BinaryTree<TYPE>::LeftRotate(Node* _x)
{
  Node *y = _x->rc;
  _x->rc = y->lc;
  if (y->lc != nil)
    y->lc->parent = _x;
  y->parent = _x->parent;
  if (_x->parent == nil)
    root = y;
  else if (_x == _x->parent->rc)
    _x->parent->rc = y;
  else _x->parent->lc = y;
  y->lc = _x;
  _x->parent = y;
};

/** 
 * To get the root of a tree
 * 
 * 
 * @return root
 */
template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::getRoot()
{
  if(root != nil)
    return root;
  else
    return NULL;
};
/** 
 * Releases/deletes a node with the subtree below it
 * 
 * @param _x the node to be released
 */
template <class TYPE>
void BinaryTree<TYPE>::release(Node* _x)
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
BinaryTree<TYPE>::~BinaryTree()
{
    release(root);
};

/** 
 * Creates a node containing the given data
 * 
 * @param _data The given data
 * 
 * @return A new node containing the given data
 */
template <class TYPE>
BinaryTree<TYPE>::Node::Node(TYPE _data)
{
    data = _data;
    parent = lc = rc = NULL;
};

/** 
 * Searches the location of the node containing the data given
 * If there are more than one node, return the first one  met.
 *
 * @param _data the data to be searched.
 * 
 * @return the address of the node containing the data. 
 */
template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::tree_search(TYPE _data)
{
  Node* x = root;
  bool flag = false;
  while (flag == false)
  {
      if (_data < x->data && x->lc != this->nil)
	{
	      x = x->lc;
	      if (_data == x->data)
		{
		  flag = true;
		  return x;
		}
	}
      else if (_data > x->data && x->rc != this->nil)
	{
	      x = x->rc;
	      if(_data == x->data)
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
 * Find the node with the largest data less than the data
 * of _x
 *
 * @param _x The start node.
 * 
 * @return The address of the predecessor node.
 */
template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::predecessor(Node* _x) const
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
 * Returns the data of the predecessor node
 * 
 */
template <class TYPE>
void BinaryTree<TYPE>::test_predecessor()
{
  std::cout << "Predecessor: "<< predecessor(root->rc->lc)->data << std::endl;
};

/** 
 * Find the node with the smallest data larger than the data
 * of _x
 *
 * @param _x The start node
 * 
 * @return The address of the successor node.
 */
template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::successor(Node* _x) const
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
 * Returns the data of the successor node.
 * 
 */
/*
template <class TYPE>
void BinaryTree<TYPE>::test_successor()
{
    std::cout << "successor: " << successor(root->lc->lc->rc)->data << std::endl;
};
*/

/** 
 * Find the minimum data in the whole tree
 * 
 * 
 * @return the minimum data
 */
template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::min()
{
  /*
    Node *x = this->root;
    if (x != this->nil)
	while (x->lc != this->nil)
	    x = x->lc;
    return x;
  */
  Node *x = min(root);
  std::cout << x->data << std::endl;
};

/** 
 * Find the minimum data under the node _x
 * 
 * @param _x The start node
 * 
 * @return The minimum data
 */
template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::min(Node* _x) const
{
    while (_x->lc != this->nil)
	_x = _x->lc;
    return _x;
};

/** 
 * Find the maximum data in the whole tree
 * 
 * 
 * @return The maximum data
 */
template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::max()
{
  Node* x = max(root);
  std::cout << x->data << std::endl;
};

/** 
 * Find the maximum data under the node _x
 * 
 * @param _x The start node
 * 
 * @return The maximum data
 */
template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::max(Node* _x) const
{
  while (_x->rc != this->nil)
    _x = _x->rc;
  return _x;
};

/** 
 * Sorts the tree from smallest to largest
 * 
 */
template <class TYPE>
void BinaryTree<TYPE>::inorder_treewalk() const
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
void BinaryTree<TYPE>::inorder_treewalk(Node* _x) const
{
    if (_x != this->nil)
    {
	inorder_treewalk(_x->lc);
	std::cout << _x->data << "\t";
	inorder_treewalk(_x->rc);
    }
};

/** 
 * Prints the address of each node in the whole tree
 * 
 */
template <class TYPE>
void BinaryTree<TYPE>::address() const
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
void BinaryTree<TYPE>::address(Node* _x) const
{
  if (_x != this->nil)
    {
      address(_x->lc);
      std::cout << "Address of "<< _x->data <<" : "<< _x << std::endl;
      address(_x->rc);
    }
};

template <class TYPE>
int BinaryTree<TYPE>::insert(TYPE _data)
{
  Node* x = new Node(_data);
  insert(x);
  return 0;
};

/** 
 * Insert a new node into the tree while maintaining
 * BST properties
 * 
 * @param _data the data to be inserted
 */
template <class TYPE>
int BinaryTree<TYPE>::insert(Node* _x)
{
    Node* y = this->nil;
    Node* x = this->root;
    _x->lc = _x->rc = this->nil;
    while (x != this->nil)
    {
	y = x;
	if (_x->data  < x->data)
	    x = x->lc;
	else
	    x = x->rc;
    }
    _x->parent = y;
    if (y == this->nil)
	this->root = _x;
    else if (_x->data < y->data)
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
int BinaryTree<TYPE>::transplant(Node* _u, Node* _v)
{
  if (_u == NULL)
    {
      std::cerr << "Cannot transplant to a NULL !" << std::endl;
      std::exit(-1);
    }
  if (_u->parent == this->nil)
    {
      root = _v;
    }
  else if (_u == _u->parent->lc)
    {
      _u->parent->lc = _v;
    }
  else
    {
      _u->parent->rc = _v;
    }
  //if (_v != NULL)
  _v->parent = _u->parent;
  return 0;
};

/** 
 * Deletes a node in the tree while maintaining
 * BST properties
 * 
 * @param _x the node to be deleted
 * 
 * @return NULL
 */
template <class TYPE>
int BinaryTree<TYPE>::del(Node* _x)
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
  delete _x;
  return 0;
};

/** 
 * Constructor. Creates a new tree with only a node
 * containing the given data
 * 
 * @param _data The given data.
 */
template <class TYPE>
BinaryTree<TYPE>::BinaryTree(TYPE _data)
{
    nil = new Node;
    nil->color = BLACK;
    nil->data = MIN;
    Node *r = new Node;
    r->data = _data;
    r->lc = nil;
    r->rc = nil;
    r->parent = nil;
    root = r;
};

