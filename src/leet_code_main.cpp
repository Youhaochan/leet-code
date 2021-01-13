#include <leet_code.h>

int main()
{
  /**最易懂的贪心算法*/
  Leet_Code lc;
  std::string s = "a(bcdefghijkl(mno)p)q";
  std::string output = lc.reverseParentheses(s); // output should be "apmnolkjihgfedcbq"
  cout << output;
  // int n=2;
  // std::cout<<lc.leastInterval(tasks,2);
  // 　　　int p = 10;
  // int *a, *b;
  // a = &p;
  // b = a;

  // *b = 100;
  // cout<<"a = " << *a << ", b = "<< *b <<"\n";

  return 1;
}
