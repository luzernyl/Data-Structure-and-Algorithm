# Linked List

In the current linked list template, add the following operations:

1. Node<T>* find(T _val); //Find the value _val in the linked list, if it exists, return the address of the previous node of the first node containing the value; if not, return NULL;

2. void del(Node<T>* _add); //Delete the node at the next position of the node whose address is _add;

3. Please consider how to deal with the empty linked list and the linked list with only one node in the above operation;

4. void insert(T _val); //Add a node in the linked list, store the _val value, and keep the linked list always in order. For the same element, the element inserted later is sorted later.