#ifndef data_structure
#define data_structure
#include "headfile.h"

class Node
{
public:
  int data;
  Node *next;
  Node *prev;
};

class Link
{
  //reference link:
  /* 
    https://blog.csdn.net/baidu_33621692/article/details/53468656
    */
private:
  Node *head;

public:
  Link();
  ~Link();
  bool insert(const int &data);
  bool insert(const uint &pos, const int &data);
  void push_back(const int &data);
  void erase(const uint &pos);
  void erase(const uint &beg, const uint &end);
  void remove(const int &data);
  int operator[](const uint &pos);
  int front();
  int back();
  int pop_back();
  int pop_front();
  void reverse();
  uint32_t size();
  void print();
};

// 双链表　头尾指针
class two_direction_link
{
private:
  int size_k; //链表长度
  int num_k;  //当前链表长度
  Node *head; //头指针，固定不动
  Node *tail; //尾部指针，始终指向最后一个节点的地址
public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  two_direction_link(int k);
  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int value);

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int value);

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront();

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast();

  /** Get the front item from the deque. */
  int getFront();
  /** Get the last item from the deque. */
  int getRear();

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty();

  /** Checks whether the circular deque is full or not. */
  bool isFull();
};

#endif