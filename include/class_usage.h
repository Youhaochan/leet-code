#ifndef class_h
#define class_h
#include <string.h>
#include <iostream>

using namespace std;
struct sale_data_struct
{
  string isbn() const { return this->bookNo; }

  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

class sale_data_class
{
public:
  // sale_data_class();
  // ~sale_data_class();
  string isbn() const { return this->bookNo; }
  void set_bookid(string bookmame)
  {
    bookNo = bookmame;
  }

private:
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

#endif