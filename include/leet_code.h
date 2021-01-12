#ifndef leet_code
#define leet_code

#include<headfile.h>
class greedy_algorithm
{
public:
	int 
	Assign_cookies_easy(vector<int>& children,
						vector<int>& cookies);
	int candy(std::vector<int> & ratings);
	// 1.2 位运算，　进制运算
	// 数字转换位１６进制
	
};

class Leet_Code
{
public:
	std::string int_to_hex(int data);
	bool power_of_two(int data);
	int find_single_number(std::vector<int> data);
	std::vector<int>
	find_single_number_2(std::vector<int> data);
	int findMaximumXOR(std::vector<int> nums);
	void reverseString(vector<char>& s) ;
	string longestCommonPrefix(vector<string>& strs);
	string addStrings(string num1, string num2);
	string convert(string s, int numRows);
	string findReplaceString(string S, 
							 vector<int>& indexes, 
							 vector<string>& sources, 
							 vector<string>& targets);
};

#endif