#ifndef	huawei_code
#define huawei_code
#include<headfile.h>

class huawei
{
public:
// 编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次 
	//  input: abc
	//  output: 3
	void compute_number_of_string() ;

// 输入整型数组和排序标识，对其元素按照升序或降序进行排序（一组测试用例可能会有多组数据）
	// input
	// 8
	// 1 2 4 9 3 55 64 25
	// 0
	// output
	// 1 2 3 4 9 25 55 64
	void sort_number();

// 功能:等差数列 2，5，8，11，14。。。。

// 输入:正整数N >0

// 输出:求等差数列前N项和

// 返回:转换成功返回 0 ,非法输入与异常返回-1

// 本题为多组输入，请使用while(cin>>)等形式读取数据

	void Arithmetic_sequence();

// 自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n以内的自守数的个数

	int compute_bit_of_number(int n);
	void natural_number();

// 　自动售货机　没做
	void slot_machine(); //not done

// 首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。

// 输入描述:
// 首先输入一个正整数n，
// 然后输入n个整数。

// 输出描述:
// 输出负数的个数，和所有正整数的平均值。

	void negative_positive();

// 将一个字符中所有出现的数字前后加上符号“*”，其他字符保持不变
// 	输入
//
// Jkdi234klowe90a3
// 输出
// 
// Jkdi*234*klowe*90*a*3*
	void add_star();



	// 人民币转换

	void RMB_transfer();
	int extract_value(int data,int n);
	void print_unit(int n);
	void print_value(int n);

	// 
	// 投票统计

// 	输入描述:
// 输入候选人的人数，第二行输入候选人的名字，第三行输入投票人的人数，第四行输入投票。

// 输出描述:
// 每行输出候选人的名字和得票数量。

// 示例1
// 输入
// 复制
// 4
// A B C D
// 8
// A B C D E F G H
// 输出
// 复制
// A : 1
// B : 1
// C : 1
// D : 1
// Invalid : 4
	void vote();
	int compute_vote(string name_candidate, string vote_candidate);


// 

// 编写一个函数，传入一个int型数组，返回该数组能否分成两组，使得两组中各元素加起来的和相等，
// 并且，所有5的倍数必须在其中一个组中，所有3的倍数在另一个组中（不包括5的倍数），能满足以上条件，返回true；不满足时返回false。
	void euqal_();
	bool digui(int length, vector<int> vec,int diff, int sum, int n);

	void print_longest_number();


// 动态规划　找出所有可以走的路径
	void compute_trajectory();
	bool find_trajectory(int x, int y,int &num_line);

	void legal_ip();


};

#endif
