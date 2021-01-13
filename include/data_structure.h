#ifndef data_structure
#define data_structure
#include "headfile.h"

class Node
{

public:
  int data;
  Node *next;
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

#endif