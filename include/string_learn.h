#ifndef string_learn_h
#define string_learn_h
#include <headfile.h>

class string_learn
{
public:
  void initialise();
  void print_initialise();
  void input(); // 这里用来研究　ｓｔｒｉｎｇ类型的输入方法
  void print_vector(vector<string> vec);
  string name;
  string age;
  string job;
  string country;
  string gender;
};

#endif