#include <leet_code.h>

int greedy_algorithm::Assign_cookies_easy(vector<int> &children,
                                          vector<int> &cookies)

{
  sort(children.begin(), children.end());
  sort(cookies.begin(), cookies.end());
  int child = 0, cookie = 0;
  while (child < children.size() && cookie < cookies.size())
  {
    if (children[child] < cookies[cookie])
      ++child;
    ++cookie;
  }
  return child;
}

int greedy_algorithm::candy(std::vector<int> &ratings)
{
  int size = ratings.size();
  if (size < 2)
  {
    return size;
  }
  vector<int> num(size, 1);
  for (int i = 1; i < size; ++i)
  {
    if (ratings[i] > ratings[i - 1])
    {
      num[i] = num[i - 1] + 1;
    }
  }
  for (int i = size - 1; i > 0; --i)
  {
    if (ratings[i] < ratings[i - 1])
    {
      num[i - 1] = max(num[i - 1], num[i] + 1);
    }
  }
  return accumulate(num.begin(), num.end(), 0);
}

std::string Leet_Code::int_to_hex(int data)
{
  if (!data)
    return "0";
  std::string output;
  std::string hex = {"123456789abcdef"};
  int num = 0;
  while (data && num < 8)
  {
    ++num;
    output += hex[data & 0xf];
    data >>= 4;
  }
  return output;
}

bool Leet_Code::power_of_two(int data)
{
  data = abs(data);
  int temp = 2;
  if (data == 1)
    return true;
  if (data == 0)
    return false;
  int bit = data & 0x01;
  std::cout << "bit is " << bit << "\n";
  if (bit)
    return false;
  else
    return true;
}

int Leet_Code::find_single_number(std::vector<int> data)
{
  // solution one
  // std::map<int, int> m;
  // for(int i=0; i<10; i++)
  // {
  // 	std::pair<int,int> p;
  // 	 p = std::make_pair(i,0);
  // 	m.insert(p);
  // }
  // for(auto d : nums)
  // {
  // 	m[d]++;
  // }
  // int output;
  // for(auto d : m)
  // {
  // 	if(d.second == 1)
  // 		{
  //             output = d.first;
  //             break;
  //         }
  // }
  // solution two
  int seen_once = 0, seen_twice = 0;
  for (auto d : data)
  {
    std::cout << "~seen_twice "
              << "& (seen_once ^ x) \n";
    std::cout << (~seen_twice) << " & "
              << "(" << (seen_once ^ d) << ") = " << (~seen_twice & (seen_once ^ d)) << "\n";
    seen_once = ~seen_twice & (seen_once ^ d);
    std::cout << "~seen_once "
              << "& (seen_twice ^ x) \n";
    std::cout << (~seen_once) << " & "
              << "(" << (seen_twice ^ d) << ") = " << (~seen_once & (seen_twice ^ d)) << "\n";

    seen_twice = ~seen_once & (seen_twice ^ d);

    std::cout << "after the one iteration \n";
    std::cout << " seen_once is:\n " << seen_once << ", \nseen_twice is: \n"
              << seen_twice << std::endl;
    std::cout << "******************************\n";
  }
  return seen_once;
}

std::vector<int> Leet_Code::find_single_number_2(std::vector<int> data)
{
  int seen_once = 0;
  std::vector<int> output;
  for (auto d : data)
  {
    seen_once = seen_once ^ d;
  }
  output.push_back(seen_once);
  std::reverse(data.begin(), data.end());
  for (auto d : data)
  {
    seen_once = seen_once ^ d;
  }
  output.push_back(seen_once);
  return output;
}

int Leet_Code::findMaximumXOR(std::vector<int> nums)
{
  std::vector<int> output;
  if (nums.size() == 1)
    return 0;
  for (int i = 0; i < nums.size() - 1; i++)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      output.push_back((nums[i] ^ nums[j]));
    }
  }

  return *std::max_element(output.begin(), output.end());
  // int s = output.size();
  // sort(output.begin(), output.end());
  // return output[s-1];
  ;
}

string Leet_Code::longestCommonPrefix(vector<string> &strs)
{
  int n = strs.size();
  string output;
  if (!strs.size())
    return output;
  sort(strs.begin(), strs.end());
  int minimun_length = strs[0].size();
  // solution one
  // bool flag = false;
  // for(int i=0; i<minimun_length; i++)
  // {
  // 	for(int j=0; j<n-1 ;j++)
  // 	{
  // 		if(strs[j][i] ==strs[j+1][i])
  // 			continue;
  // 		else
  // 		{
  // 			flag = true;
  // 			break;
  // 		}
  // 	}
  // 	if(!flag)
  // 	{
  // 		output.push_back(strs[0][i]);
  // 	}
  // 	else
  // 	{
  // 		break;
  // 	}
  // }
  // solution two  more fast
  for (int i = 0; i < minimun_length; i++)
  {
    if (strs[0][i] == strs[n - 1][i])
      output.push_back(strs[0][i]);
    else
      break;
  }
  return output;
}

void Leet_Code::reverseString(vector<char> &s)
{
  //   official solution
  int n = s.size();
  for (int left = 0, right = n - 1; left < right; ++left, --right)
  {
    swap(s[left], s[right]);
  }
  // personal solution
  //     char temp;
  // int n = s.size();
  // for(int i=0; i< n-i-1; i++)
  // {
  //     temp = s[i];
  //     s[i] = s[n-i-1];
  //     s[n-i-1] = temp;
  // }
}

string Leet_Code::addStrings(string num1, string num2)
{
  int n1 = num1.size() - 1;
  int n2 = num2.size() - 1;
  int add = 0;
  string output;
  string m = "0123456789";
  while (n1 >= 0 | n2 >= 0)
  {
    int data1 = n1 >= 0 ? int(num1[n1] - '0') : 0; //不够位数的补零，方便对齐计算
    int data2 = n2 >= 0 ? int(num2[n2] - '0') : 0;
    cout << "data1 = " << data1 << " data2 = " << data2 << "\n";
    int sum = data1 + data2 + add;
    add = sum / 10;
    sum = sum % 10;
    output.push_back(m[sum]);
    --n1;
    --n2;
  }
  if (add)
  {
    output.push_back(m[add]);
  }
  reverse(output.begin(), output.end());
  return output;
}
string Leet_Code::convert(string s, int numRows)
{
  if (numRows == 1)
  {
    return s;
  }
  else if (numRows == 2)
  {
    string output;
    uint len = s.size();
    for (int i = 0; i < len; i = i + 2)
    {
      output.push_back(s[i]);
    }
    for (int i = 1; i < len; i = i + 2)
    {
      output.push_back(s[i]);
    }
    return output;
  }
  else
  {
    int len = s.size();
    vector<vector<char>> vec;
    vec.resize(numRows);
    int flag = -1;
    int i = 0;
    for (const auto &str : s)
    {
      vec[i].push_back(str);
      if (i + 1 >= numRows || i - 1 < 0)
      {
        flag = -flag;
      }
      i = i + 1 * flag;
    }
    string output;
    for (int i = 0; i < numRows; i++)
    {
      for (int j = 0; j < vec[i].size(); j++)
      {
        output.push_back(vec[i][j]);
      }
    }
    return output;
  }
}

string Leet_Code::findReplaceString(string S,
                                    vector<int> &indexes,
                                    vector<string> &sources,
                                    vector<string> &targets)
{
  // solution one

  // uint len_index = indexes.size();
  // map<int,string> sou, tas;
  // for(uint i=0; i<len_index; i++)
  // {
  // 	sou.insert(make_pair(indexes[i], sources[i]));
  // 	tas.insert(make_pair(indexes[i], targets[i]));
  // }
  // sort(indexes.begin(), indexes.end());
  // uint len_S = S.size();
  // string output;
  // uint n=0;
  // uint j=0;
  // auto equal_or_not = [](const string S, const uint j,const uint index, map<int, string> sou) ->bool
  // {
  // 	for(uint i=0; i< sou[index].size(); i++)
  // 	{
  // 		// cout<<"S[j+1]: "<<S[j+i] << "~~~ sou: "<<sou[index][i]<<"\n";
  // 		if(S[j+i] == sou[index][i])
  // 		{
  // 			continue;
  // 		}
  // 		else
  // 			return false;
  // 	}
  // 	return true;
  // };
  // while(n < len_index && j<len_S)
  // {
  // 	cout<<"j: "<<j<<" indexes[n]: "<<indexes[n]<<"\n";
  // 	if(equal_or_not(S, j, indexes[n], sou) &&  j == indexes[n] )
  // 	{
  // 		output += tas[indexes[n]];
  // 		j = j +(sou[indexes[n]]).size();
  // 		++n;
  // 	}
  // 	else
  // 	{
  // 		if(j == indexes[n])
  // 			++n;
  // 		output += S[j];
  // 		++j;
  // 	}
  // }
  // while(j<len_S)
  // {
  // 	output += S[j];
  // 	++j;
  // }
  // return output;

  // solution two
  /*
        判断S下标indexes[i]处开始的子字符串是否为sources[i]，是的话替换为targets[i]
        需要注意的是直接改变S的话相关的下标对应的字符会发生改变
        解决这一点的方法是从后往前开始替换，这样替换位置之前的下标与字符的关系就不会被改变
        需要注意的是indexes的顺序并不是有序的，需要先对其进行排序，注意保留indexes,sources,targets之间的对应关系
        */
  map<int, pair<string, string>> m;
  for (int i = 0; i < indexes.size(); ++i)
  {
    m[indexes[i]] = make_pair(sources[i], targets[i]);
  }
  for (auto iter = m.rbegin(); iter != m.rend(); ++iter)
  { //map的键是顺序排序的，这里需要逆序访问
    if (S.substr((*iter).first, (*iter).second.first.size()) == (*iter).second.first)
    {
      S.replace((*iter).first, (*iter).second.first.size(), (*iter).second.second);
    }
  }
  return S;
}

int Leet_Code::leastInterval(vector<char> &tasks, int n)
{
  std::vector<int> task_vec(26);
  for (auto t : tasks)
  {
    task_vec[t - 'A']++;
  }
  std::sort(task_vec.begin(), task_vec.end(), [](const int &a, const int &b) { return a > b; });
  int max_count = 1;
  while (task_vec[0] == task_vec[max_count] && max_count < task_vec.size())
  {
    ++max_count;
  }
  int len = tasks.size();
  return max(len, max_count + (task_vec[0] - 1) * (n + 1));
}

bool Leet_Code::isValid(string s)
{
  int n = s.length();
  if (n == 0)
    return true;
  if ((s.size() % 2 != 0))
    return false;
  stack<char> st;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{')
      st.push(s[i]);
    if (s[i] == ')')
    {
      if (!st.empty() && st.top() == '(')
        st.pop();
      else
        return false;
    }
    if (s[i] == ']')
    {
      if (!st.empty() && st.top() == '[')
        st.pop();
      else
        return false;
    }
    if (s[i] == '}')
    {
      if (!st.empty() && st.top() == '{')
        st.pop();
      else
        return false;
    }
  }
  if (st.empty())
    return true;
  return false;
}
string Leet_Code::reverseParentheses(string s)
{
  std::stack<string::iterator> beg;
  for (auto iter = s.begin(); iter != s.end(); ++iter)
  {
    if (*iter == '(')
      beg.push(iter);
    if (*iter == ')')
    {
      auto start = beg.top(); //提取首位迭代器
      beg.pop();              //弹出首位迭代器
      reverse(start, iter);
    }
  }
  auto comp = [](char a) -> bool {
    return (a == '(' || a == ')');
  };
  s.erase(remove_if(s.begin(), s.end(), comp), s.end());
  return s;

  // 作者：sean-113
  // 链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/solution/li-yong-zhan-de-xian-jin-hou-chu-si-xian-eoji/
  // 来源：力扣（LeetCode）
  // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}
int Leet_Code::evalRPN(vector<string> &tokens)
{
  int partial_result;
  stack<int> temp;
  if (tokens.size() == 1)
  {
    return stoi(tokens[0]);
  }
  for (const auto &s : tokens)
  {
    if (s != "*" &&
        s != "/" &&
        s != "+" &&
        s != "-")
    {
      temp.push(std::stoi(s));
    }
    else
    {
      int data1 = temp.top();
      temp.pop();
      int data2 = temp.top();
      temp.pop();
      if (s == "/")
        partial_result = data2 / data1;
      if (s == "*")
        partial_result = data2 * data1;
      if (s == "+")
        partial_result = data2 + data1;
      if (s == "-")
        partial_result = data2 - data1;
      temp.push(partial_result);
    }
  }
  return temp.top();
}