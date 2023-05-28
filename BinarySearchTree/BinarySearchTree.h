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

typedef int T;

class BinaryTree
{
private:
    class Node
    {
    public:
	T data;
	Node* lc;
	Node* rc;
	Node* parent;
	Node(T _data);
    };
    Node* root;
    void inorder_treewalk(Node* _x) const;
    void release(Node* _x);
    //Node* successor(Node* _x) const;
    //Node* predecessor(Node* _x) const;
    Node* min(Node* _x) const;
    Node* max(Node* _x) const;
    void address(Node* _x) const;
    
public:
    BinaryTree() {root = NULL;};
    BinaryTree(T _data);
    ~BinaryTree();
    void insert(T _data);
    void inorder_treewalk() const;
    Node* successor(Node* _x) const;
    Node* predecessor(Node* _x) const;
    void test_successor();
    void test_predecessor();
    Node* tree_search(T _data);
    Node* min();
    Node* max();
    void address() const;
    T transplant(Node* _u, Node* _v);
    T del(Node* _x);
};

/** 
 * Releases/deletes a node with the subtree below it
 * 
 * @param _x the node to be released
 */
void BinaryTree::release(Node* _x)
{
    if (_x != NULL)
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
BinaryTree::~BinaryTree()
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
BinaryTree::Node::Node(T _data)
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
BinaryTree::Node* BinaryTree::tree_search(T _data)
{
  Node* x = root;
  bool flag = false;
  if (_data < root->data)
    {
      while ( _data < x->data && x->lc != NULL)
	{
	  x = x->lc;
	  if (_data == x->data)
	    {
	      flag = true;
	      return x;
	    }
	}
    }
  else
    {
      while (_data > x->data && x->rc != NULL)
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
BinaryTree::Node* BinaryTree::predecessor(Node* _x) const
{
  Node* x = _x;
  if (x->lc != NULL)
    return max(x->lc);
  Node* y = x->parent;
  while(y != NULL && x == y->lc)
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
void BinaryTree::test_predecessor()
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
BinaryTree::Node* BinaryTree::successor(Node* _x) const
{
    Node* x = _x;
    if (x->rc != NULL)
	return min(x->rc);
    Node* y = x->parent;
    while (y != NULL && x == y->rc)
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
void BinaryTree::test_successor()
{
    std::cout << "successor: " << successor(root->lc->lc->rc)->data << std::endl;
};

/** 
 * Find the minimum data in the whole tree
 * 
 * 
 * @return the minimum data
 */
BinaryTree::Node* BinaryTree::min()
{
  Node* x = min(root);
  std::cout << x->data << std::endl;
};

/** 
 * Find the minimum data under the node _x
 * 
 * @param _x The start node
 * 
 * @return The minimum data
 */
BinaryTree::Node* BinaryTree::min(Node* _x) const
{
    while (_x->lc != NULL)
	_x = _x->lc;
    return _x;
};

/** 
 * Find the maximum data in the whole tree
 * 
 * 
 * @return The maximum data
 */
BinaryTree::Node* BinaryTree::max()
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
BinaryTree::Node* BinaryTree::max(Node* _x) const
{
  while (_x->rc != NULL)
    _x = _x->rc;
  return _x;
};

/** 
 * Sorts the tree from smallest to largest
 * 
 */
void BinaryTree::inorder_treewalk() const
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
void BinaryTree::inorder_treewalk(Node* _x) const
{
    if (_x != NULL)
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
void BinaryTree::address() const
{
  address(root);
  std::cout<< std::endl;
};

/** 
 * Prints the address of every node under the start node
 * 
 * @param _x The start node
 */
void BinaryTree::address(Node* _x) const
{
  if (_x != NULL)
    {
      address(_x->lc);
      std::cout << "Address of "<< _x->data <<" : "<< _x << std::endl;
      address(_x->rc);
    }
};

/** 
 * Insert a new node into the tree while maintaining
 * BST properties
 * 
 * @param _data the data to be inserted
 */
void BinaryTree::insert(T _data)
{
    Node* y = NULL;
    Node* x = root;
    Node* p = new Node(_data);
    while (x != NULL)
    {
	y = x;
	if (p->data  < x->data)
	    x = x->lc;
	else
	    x = x->rc;
    }
    p->parent = y;
    if (y == NULL)
	root = p;
    else if (p->data < y->data)
	y->lc = p;
    else
	y->rc = p;
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
T BinaryTree::transplant(Node* _u, Node* _v)
{
  if (_u == NULL)
    {
      std::cerr << "Cannot transplant to a NULL !" << std::endl;
      std::exit(-1);
    }
  if (_u->parent == NULL)
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
T BinaryTree::del(Node* _x)
{
  if (_x->lc == NULL)
    {
      this->transplant(_x, _x->rc);
    }
  else if (_x->rc == NULL)
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
BinaryTree::BinaryTree(T _data)
{
    Node* p = new Node(_data);
    if (root == NULL)
	root = p;
};

