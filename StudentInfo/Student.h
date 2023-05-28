/**
 * @file   Student.h
 * @author Luzern Yuven Luis <student@student>
 * @date   Sun Oct 11 19:11:29 2020
 * 
 * @brief  An implementation of heap.
 * 
 * 
 */

#ifndef __CRAZYSIGH_HEAP__
#define __CRAZYSIGH_HEAP__
#include <vector>

class Student
{
 private:
  int std_no;   //Student number, every student has a unique ID number.
  char major;   //Student major marked by one character, M for math,
                //P for Physics, C for Chemistry.
  double GPA;   //GPA range : 0 ~ 5
  int major_num; //An integer for every major.

 public:
#define PARENT(i) ((((i) + 1) >> 1 ) - 1 )
#define LEFTCHILD(i)  (((i+1) << 1 ) - 1 )
#define RIGHTCHILD(i) ((i+1) << 1 )
  
  /** 
   * Default constructor.
   * 
   *  
   */
  Student();
  /** 
   * Constructor, initialize data
   * 
   * @param std_no student ID
   * @param major student's major
   * @param GPA student's GPA
   */
  Student(int stdnum, char maj, double gpa);

  /** 
   * Get the major of each students.
   * 
   * 
   * @return The major of the student.
   */
  char get_major();

  /** 
   * Get the integer for every major
   * 
   * 
   * @return an integer for every major
   */
  int get_major_num();
  
  /** 
   * Get the ID of the student.
   * 
   * 
   * @return The ID of the student.
   */
  int get_std_no();
  
  /** 
   * Get the GPA of the student
   * 
   * 
   * @return the GPA of the student
   */
  double get_GPA();

  /** 
   * To change GPA value
   * 
   * @param g wanted GPA
   * 
   * @return new GPA
   */
  int modify_GPA(double g);
  
  
};

class Heap
{
 private:
  Student *data;  //Store data of heap.
  int length; //Number of the elements in the heap.
 public:
  /** 
      * Default constructor.
      * 
      */
     Heap();

     /** 
      * Constructor, initialize data with a bunch of elements pointed by 
      * datahead. 
      * 
      * @param datahead Pointer to the elements data.
      * @param l Total number of the elements data. 
      */
     Heap(Student *datahead, int l);

     /** 
      * Default destructor.
      * 
      */
     ~Heap();


     /** 
      * Get the length of the heap.
      * 
      * 
      * @return The length of the heap.
      */
     int get_length();

     /** 
      * Get the height of the heap.
      * 
      * 
      * @return The height of the heap.
      */
     int get_height();
/** 
      * Check if the heap has no data element.
      * 
      * 
      * @return True for empty. 
      */
     bool is_empty();


     /** 
      * Get the index of the right child node.
      * 
      * @param i The index of the current node.
      * 
      * @return The index of the right child node.
      */
     int right_child(int i);

     /** 
      * Shift down the i-th node to recover the properties of min-heap.
      * 
      * @param i The index of the broken node.
      * 
      * @return Error code, 0 for OK.
      */
     int shiftdown(int i);

     /** 
      * Print out all elements.
      * 
      * 
      * @return Error code, 0 for OK.
      */
     int printout();

     /** 
      * Sort all the elements by heap-sort method.
      * 
      * 
      * @return Error code, 0 for OK.
      */
     int sort_m();
     /** 
      * to change array into vector
      * 
      * 
      * @return array in vector
      */
     std::vector<Student> change();
};




#else
// Do nothing.
#endif
