#ifndef pointer_h
#define pointer_h

#include <iostream>
#include <string>

class pointer
{
public:
  void define_pointer(int a);                                // 指针的定义和初始化
  void array_pointer();                                      // 指针数组　－　可以定义用来存储指针的数组
  void pointer_operation(const int array[], int size_array); //指针的算数运算
  double transfer_pointer2function(int *arr, int size);      // 通过引用或地址传递参数，使传递的参数在调用函数中被改变。
  int *from_fun_return_pointer();                            //　从函数返回指针　－C++ 允许函数返回指针到局部变量、静态变量和动态内存分配
  void pointer_vs_array();                                   //　指针ｖｓ数组
  int &from_fun_return_yinyong(int *arr);
};

#endif
