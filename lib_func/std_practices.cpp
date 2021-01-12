#include <std_practices.h>

void
STD::practices_string()
{
    string test("youhaochan is from guangdong province heyuan city");
    for(auto iter = test.begin(); iter!= test.end(); iter++) //cbegin is const iterator
    {
        cout<<*iter;
    }
    cout<<endl;
    for(auto iter = test.rbegin(); iter != test.rend(); iter++) //crbegin() 是ｃｏｎｓｔ
        cout << *iter;
    cout<<endl;

    test.resize(100);
    cout<<"test the difference of str.size() and str.length()\n "<<"test.size() = "<<test.size()
        <<"\n test.length() = "<<test.length()<<endl;

    // access data
    test.at(10) = 5;//at()  return reference
    test.back();
    test.front(); // both return reference

    // modifiers
    std::string str;
    std::string str2="Writing ";
    std::string str3="print 10 and then 5 more";
    // Extends the string by appending additional characters at the end of its current value:
    str.append(str2);                       // "Writing "
    str.append(str3,6,3);                   // "10 "

    std::string base="The quick brown fox jumps over a lazy dog.";
    // Assigns a new value to the string, replacing its current contents.
    str.assign(base);
    std::cout << str << '\n';
    str.assign(base,10,9);
    std::cout << str << '\n';         // "brown fox"
    // insert replace erase 
    str.clear();
    str = "yyyyhhhhcccc";
    str.insert(0,"ooo");
    cout<<str<<"\n";
    str.replace(str.begin()+4, str.begin()+8,"replace");
    // str.replace(4, 8,"replace"); ok
    cout<<str<<"\n";
    str.erase(str.begin(),str.begin()+4);
    // str.erase(0,4); ok
    str.pop_back();// delete the last character
    cout<<str<<endl;

    //string operations
    char *c = new char[str.size()+1];
    strcpy(c, str.c_str());
    cout<<c<<endl; 
    delete[] c;
    
    //find 	
    // size_t find (const string& str, size_t pos = 0) const noexcept;	
    // size_t find (const char* s, size_t pos = 0) const;	
    // size_t find (const char* s, size_t pos, size_type n) const;	
    // size_t find (char c, size_t pos = 0) const noexcept;
    // return value
    // The position of the first character of the first match.
    // If no matches were found, the function returns string::npos.
    str.clear();
    str = "youhaohaochanchan";
    std::size_t found = str.find("hao");//从前往后查找
    if (found!=std::string::npos)
       std::cout << "first 'hao' found at: " << found << '\n';
    found = str.rfind("hao");//从后往前查找
    if (found!=std::string::npos)
       std::cout << "first 'hao' found at (searching from the back): " << found << '\n';       
    found = str.find("hai");//查找的字符串要全部匹配的上，不然就不算是找到
    if (found!=std::string::npos)
       std::cout << "first 'hai' found at: " << found << '\n';
    else
        std::cout <<"hai is not found"<<endl;

    // find_first_of
    str = ("Please, replace the vowels in this sentence by asterisks.");
    found = str.find_first_of("aeiou");
    while (found!=std::string::npos)
    {
    str[found]='*';
    found=str.find_first_of("aeiou",found+1);
    }
    std::cout << str << '\n';

    // substr()
    // string substr (size_t pos = 0, size_t len = npos) const;
    str="We think in generalities, but we live in details.";                                    
    str2 = str.substr (3,5);  
    cout<<str2<<endl; 

    // 比较俩个字符串是否相等
    // int compare (const string& str) const noexcept;
    // int compare (size_t pos, size_t len, const string& str) const;
    // int compare (size_t pos, size_t len, const string& str,
    //              size_t subpos, size_t sublen) const;    
    std::string stra ("green apple");
    std::string strb ("red apple");

    if (stra.compare(strb) != 0)
    std::cout << stra << " is not " << strb << '\n';

    if (stra.compare(6,5,"apple") == 0)
    std::cout << "still, " << stra << " is an apple\n";

    if (strb.compare(strb.size()-5,5,"apple") == 0)
    std::cout << "and " << strb << " is also an apple\n";

    if (stra.compare(6,5,strb,4,5) == 0)
    std::cout << "therefore, both are apples\n";

    // 也可以这样比较
    if(stra.substr(6,5) == strb.substr(4,5))
    {
        cout<<"they are both apples \n";
    }
}

void STD::practices_vector()
{
    //iterators
    vector<int> vec(10,1);
    vec.begin();
    vec.end();
    vec.rbegin();
    vec.rend();
    vec.cbegin();
    vec.crbegin();

    // capacity
    vec.size();
    vec.resize(5);

    // access elements
    vec.at(1);
    vec.front();
    vec.back();

    // modifiers
    //  void assign (InputIterator first, InputIterator last);
    vector<int> vec2(5,2);
    vec.assign(vec2.begin(), vec2.end());
    vec.push_back(10);
    vec.pop_back(); //delete the last element　没有返回值
    // vec.insert()  vec.erase()  vec.clear() is the same as string
}

void STD::practices_map()
{
    //initilise
    std::map<int,char> m;
    m[1] = 'y';
    m[3] = 'h';
    m[2] = 'c';
    m.insert(make_pair(0,'k'));
    
    // iterator
    for(const auto& d :m)
    {
        cout<<d.first <<"-->"<<d.second<<"\n";
    }
    for(auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout<<(*iter).first <<" ----> " <<iter->second <<"\n";
    }  
    // inversely printing the map
    cout<<" inversely printing the map\n";
    for(auto iter = m.crbegin(); iter != m.crend(); iter++)
    {
        cout<<(*iter).first <<" ----> " <<iter->second <<"\n";
    }  

    // capacity
    if(m.empty())
        cout<<"map is not empty \n";
    else
        cout<<"map is empty \n";
    cout<<" the size of map is: "<<m.size()<<"\n";
    
    // access element
    char a = m[1];
    char &b = m.at(2);

    // modifiers
    std::map<char,int> mymap;
    /*****insert*******/
    // first insert function version (single parameter):
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );
    std:pair<char, int> p = std::make_pair('m',100);
    mymap.insert(p);
    mymap.insert ( std::make_pair('q',10));
    std::pair<std::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( std::pair<char,int>('z',500) );
    if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    std::map<char,int>::iterator it = mymap.begin();
    // 如果key　已经存在，　那么不会插入该 key-value，　返回值会是一个ｆａｌｓｅ
    // 如果成功插入，　则返回true；
    mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
    auto success = mymap.emplace('y',200); //Inserts a new element in the map if its key is unique
    if(success.second)
    {
        cout<<" successfullt insert a unique key-value \n";
        cout<<" the inserted data is: "<<"["<<success.first->first<<":"
            <<success.first->second<<"]\n";
    }
    else
    {
        cout<<" failure to insert a key-value because it already exits \n";
    }
    
    // third insert function version (range insertion):
    std::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));
  // showing contents:
    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    /*****erase*******/
    it = mymap.find('c');
    mymap.erase(it);
    mymap.erase('m');
    it = mymap.find('b');
    mymap.erase(it, --(mymap.end()));
    // show content:
    cout<<"after erase the contents\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    // swap
    // void swap (map& x);
    
    // mymap.clear(); //remove all elements;
    //  count() -> return value
    //  1 if the container contains an element 
    // whose key is equivalent to k, or zero otherwise.
    if(mymap.count('c')==1)
    {
        cout<<" 'c' is an element of mymap\n";
    } 
    else
    {
        cout<<"'c' is not an element\n";
    }
    
    // ultimap
    std::multimap<char,int> mymm;

    mymm.insert (std::make_pair('x',10));
    mymm.insert (std::make_pair('y',20));
    mymm.insert (std::make_pair('z',30));
    mymm.insert (std::make_pair('z',40));

    // access data by using multimap.find();
    // print content:
    std::cout << "elements in mymm:" << '\n';
    std::cout << "y => " << mymm.find('y')->second << '\n';
    std::cout << "z => " << mymm.find('z')->second << '\n';
    for(auto iter = mymm.cbegin(); iter!= mymm.cend(); iter++)
    {
        cout<<"["<<iter->first<<" : "<<iter->second<<"]\n";
    }
    mymm.erase(mymm.find('z'));// only erase one element by iterator
    cout<<"after erase element\n";
    for(auto iter = mymm.cbegin(); iter!= mymm.cend(); iter++)
    {
        cout<<"["<<iter->first<<" : "<<iter->second<<"]\n";
    }    
    // mymm['z'] = 100; // error multi map does not have operator[]
    mymm.insert(std::make_pair('z',100));
    mymm.insert(std::make_pair('z',200));
    mymm.insert(std::make_pair('z',300));
    cout<<"add repeated elements \n";
    for(auto iter = mymm.cbegin(); iter!= mymm.cend(); iter++)
    {
        cout<<"["<<iter->first<<" : "<<iter->second<<"]\n";
    }     
    // if input the key value, it will erase all 'z';
    mymm.erase('z');
    cout<<"after erase element \n";
    for(auto iter = mymm.cbegin(); iter!= mymm.cend(); iter++)
    {
        cout<<"["<<iter->first<<" : "<<iter->second<<"]\n";
    }

}