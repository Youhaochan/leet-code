#include<huawei_code.h>

void huawei::compute_number_of_string()

{
	string word;
    cin>>word;
    sort(word.begin(),word.end());//
    word.erase(unique(word.begin(), word.end()),word.end());//　把重复的去除掉
    cout<<word.size()<<endl;
}

void huawei::sort_number()
{

	vector<int> vec;
	int number,i=0;
	int  word;
	cin>>number;
	int array[number];
	int sign;
	while(cin>>word)
	{
	
		vec.push_back(word);
		i = i+1;
		if (i>=number)
			break;

	}
	cin>>sign;
	sort(vec.begin(),vec.end());
	if(sign ==1)
	{

		for (i = 0; i<number ; i++)
		{

			cout<<vec[number-i-1]<<" ";
		} 
	}
	else
	{
	for(auto i : vec)
		cout<<i<<" ";

	}

}

void huawei::Arithmetic_sequence()
{
    int number, sum=0;
    while(cin>>number)
    {
        // if(number<0)
        //     return -1;
        for(int i = 1;i<=number;i++)
        {
            sum = sum+2+3*(i-1);
        }
        cout<<sum<<endl;
        
    }

}

int huawei::compute_bit_of_number(int n)
{
	 int bit=0;
    while(1)
    {
        n = n/10;
        bit++;
        if (n<=0)
            break;
    }
    return bit;
}

void huawei::natural_number()
{

 int data,bit=0,number=0,remaining;
    while(cin>>data)
    {
        number=0;
        for(int i=0; i<=data;i++)
        {

            bit =compute_bit_of_number(i);//求输入的　数值有多少位　　比如　６２０　就有３位
            
            remaining = int(i*i)%int(pow(double(10),double(bit)));//求余数
            if(remaining==i)
                number++;          
        }
        cout<<number<<endl;
        
    }

}

void huawei::negative_positive()
{

   int number, data;
    
    int negtive;
    int average=0;
    int i=0,sum=0,cn1=0,cn2=0;
    while(cin>>number)
    {
        i=0;
        negtive=0;
        sum=0;
        cn1=0;
        cn2=0;
        vector<int> vec;
     while(cin>>data)
    {
        vec.push_back(data);
        i++;
        if(i>=number)
            break;
        
    }
     for(int j=0;j<number;j++)
     {
         if(vec[j]<0)
             {negtive++;
             	cn1++;
             }
         if(vec[j]>0)
             {sum=sum+vec[j];
             	cn2++;
             }
         
     }
      float sum_2 = float(sum)/cn2;
      
       
     printf("%d %0.1f\n",cn1,sum_2);
        
        
    }
}

void huawei::add_star()
{

	 string data,copy;
    while(cin>>data)
    {
    	auto c = data.begin();
        int flag=0;
        // copy = data;
        for(c = data.begin(); c!=data.end();c++)
        {
           if(flag==0)
               {

                   if(*c>='0' && *c<='9')
                       {     
                        
                       // data.insert(c, '*');  这种写法　会报错，　
                       c=data.insert(c, '*'); //这种写法才是安全的，　要把当前插入新元素对应的迭代器位置返回回去
                       
                       	flag=1;
                       	continue;


             		  }
                   
               }
           if(flag==1)
                {
                    if(*c>='0' && *c<='9')
                         {                       	
                         	continue;                     	
                         }
                        
                     else
                     {
                         flag=0;
                         
                         c = data.insert(c, '*');
                     }

                }

        }
        if(*(c-1)>='0' && *(c-1)<='9')
        	data.push_back('*');
        cout<<data<<endl;        
        
        
    }

}

int huawei::extract_value(int data,int n)
{
	return data/pow(double(10),n-1);

}
void huawei::print_unit(int n)

{



}


void huawei::print_value(int n)
{


}
void huawei::RMB_transfer()
{

string gewei[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
//构建十位、百位、千位、万位、亿位等其他单位的字典（数组），ot[10] 实际表示 "拾亿"，ot[15] 实际表示 "佰万亿"
string other[] = {"元", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟", "万"};



double money;
 while(cin>>money)
 {


 	int zhengshu = int(money);
 	int extract_number=0;
 	float xiaoshu = money - zhengshu;
 	int number = compute_bit_of_number(int(money));
 	vector<string> vec;
 	int m=0,flag=0;

// 处理小数
 	if(xiaoshu==0)
 		vec.push_back("整");
 	int xs = xiaoshu*100;
 	for(int i=0; i<2;i++)
 	{
		extract_number = xs%10;
		xs = int(xs/10);
		if(extract_number==0)
			continue;
		else if(extract_number!=0 && i==0)
		{
	 			vec.push_back("分");
				vec.push_back(gewei[extract_number]);			

		}
		else if(extract_number!=0 && i==1)
		{
			 			vec.push_back("角");
				vec.push_back(gewei[extract_number]);		
		} 

 	}

// 处理整数部分，如果整数部分等于０，就跳过
 	if(zhengshu!=0)
 	{

 	for(int i=0 ; i<number; i++)
 	{
 		// 一位一位的提取数值，从个位数开始提取
 		extract_number = zhengshu%10;
 		zhengshu = int(zhengshu/10);
 
 	
 		

 		if(m==0 && extract_number==0 &&flag==0)
 		{
	 		vec.push_back(other[m]);
	 		m++;
	 		flag=1;
	 		continue;
 		}
// 　这个是万位　为零的时候　要　表述应为　。。。几万零几千。。。　flag==0 意思是前面一个数值不是０
  		else if(m==4 && extract_number==0 &&flag==0)
 		{
 			vec.push_back("零");
	 		vec.push_back(other[m]);
	 		m++;
	 		flag=1;
	 		continue;
 		}
// 这个是亿位　为零的时候　要　表述应为　。。。几亿零几千。。。flag==0 意思是前面一个数值不是０，所以可以加一个零，否则就只能加万，省略掉零
  		else if(m==8 && extract_number==0 && flag==0)
 		{
 			vec.push_back("零");
	 		vec.push_back(other[m]);
	 		m++;
	 		flag=1;
	 		continue;
 		}
 		// 这里记录遇到的第一个零，并且设置flag=1,目的是为了检测下一个数值　是否还是零，如果是　则不做任何操作，遇到万位和亿位都为零除外，因为这个时候需要加单位万或者亿

 		if(extract_number==0 &&  flag==0)
	 		{
				// vec.push_back(other[m]);
				vec.push_back(gewei[extract_number]);
				m++;
				flag=1;
				continue;
	 		}

 		else if(extract_number==0 &&  flag==1)
	 		{
				// vec.push_back(other[m]);
				if(m==4 || m==8) // 这里用来防止万位和亿位因为前面都为零而跳过了
					vec.push_back(other[m]);
				m++;
				continue;
	 		}	
	 // 　这里就是既不是第一位数值，也不是万位，亿位，　数值又不是零的时候　进行操作
	 	else 
	 	{
	 			flag=0;
	 			// 　这里是如果输入是13.01 那么输出应该是　人民币拾叁元陆角肆分，但是如果没有这句条件语句　结果就会是　人民币壹拾叁元陆角肆分
	 			if(m==1 &&number==2)
	 			{
	 				vec.push_back(other[m]);
	 				continue;
	 				m++;
	 			}
	 			vec.push_back(other[m]);
				vec.push_back(gewei[extract_number]);
				m++;
	 	}

 	}
 	}
 	string rmb[] ={"人","民","币"};
 	vec.push_back(rmb[2]);
 	vec.push_back(rmb[1]);
 	vec.push_back(rmb[0]);
 	
 	reverse(vec.begin(),vec.end());
 	// vec.erase(unique(vec.begin(),vec.end()),vec.end());
 	for(auto a: vec )
 	{
 		cout<<a;
 	}
 	cout<<endl;
 }

}


void huawei::vote()
{

	int n_people,n_vote;
    string name_candidate, vote_candidate;
    vector<int> vec;
    string m,n;
    int accu=0;
    while(cin>>n_people)
	{
	// 如果是先用cin 输入字符　后面接着用getline来输入字符的时候　需要在cin后面清除掉换行符
	// 我们先看下cin>>与getline的工作方式，流提取运算符根据它后面的变量类型读取数据，
	// 从非空白符号开始，遇到Enter、Space、Tab键时结束。getline函数从istream中读取一行数据，当遇到“\n”时结束返回。
	// 造成程序错误结果的原因是，用户输入完年龄后按回车结束输入，把“\n”留在了输入流里，

	// 而cin不会主动删除输入流内的换行符，这样换行符就被getline读取到，getline遇到换行符返回，因此程序不会等待用户输入。
	// 解决的办法是手动清除换行符，在cin>>后加上 cin.ignore();
		cin.ignore();//手动清除换行符
		name_candidate.clear();
		vec.clear();
		vote_candidate.clear();
		getline(cin,name_candidate);
		cin>>n_vote; //投票人个数
		cin.ignore();//手动清除换行符
		getline(cin,vote_candidate);
	    istringstream name_candidate2(name_candidate);
	    while(name_candidate2>>m)
	    {
	    	//　为什么在while 循环里面定义　istringstream 变量vote_candidate2,　因为如果不从夫初始化，　
	    	// 第一次循环之后，　vvote_candidate2里面就不会再有数据了，因此需要重复初始化为原来的数值

	    	istringstream vote_candidate2(vote_candidate);
	    	int i=0;
	    	while(vote_candidate2>>n)
	    		{
	    			if(m==n)
	    			   	i++;	    			
	    		}
	    	vec.push_back(i);
	    	cout<<m<<" : ";
	    	cout<<i<<endl;

	    }
   		// accumulate带有三个形参：头两个形参指定要累加的元素范围，第三个形参则是累加的初值。
   		int sum = accumulate(vec.begin(),vec.end(),0);//　需要头文件 numeric
		
   		cout<<"Invalid : "<<n_vote-sum<<endl;


	}

}

bool huawei::digui(int length, vector<int> vec,int diff, int sum, int n)
{	
	//判断绝对值是否相等
	 if(n==length)
          return(abs(sum)==diff); 
 	//开始递归，一个数值一个数值的运算，　加法要，减法也要
     if(digui(length, vec, diff, sum + vec[n], n+1)||digui(length, vec, diff, sum - vec[n], n+1))
       return 1;
    else 
        return 0;	
}

void huawei::euqal_()
{
// 思路：参考：ld1230
// 1.接收数据，分别计算被5整出，被3整出的总和，以及将剩下数据保存起来
// 2.判断是否有可能存在解，如果没有，直接输出false
// 3.若可能的话，将问题转化成，利用剩下的数据进行加减运算，得到一个数，这个数的绝对值和sum5-sum3的绝对值相同
	// 加减运算　是直接在一个盒子里面　加或者减去　盒子外面剩余的数值，　运算完之后　如果绝对值也是相差　sum5-sum，　则说明可以均分
// 即为true，用递归的方式进行求解。

	int number;
    int sum3=0, sum5=0, sum=0,n;
    while(cin>>number)
    {
        vector<int> vec;
        sum3=0;sum5=0; sum=0;
      for(int i=0;i<number;i++)
          { 
                cin>>n;
              sum+=n;
                if(n%3==0)
                    sum3+=n;
                else if(n%5 ==0)
                    sum5+=n;
                else 
                    vec.push_back(n);
          }   
        if(sum%2!=0)
            cout<<"false"<<endl;
        else
        {
        int abso_diff = abs(sum3-sum5);       
        bool flag = digui(vec.size(), vec, abso_diff, 0, 0);
        if(flag==true)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl; 
        }
    }


}

void huawei::print_longest_number()
{
    string n;
    while(getline(cin,n))
  	{
  		string data,m;
		 for(int i=0;i<n.size();i++)
		  {    if(n[i]>='0' && n[i]<='9')
		          data.push_back(n[i]);
		       else
		          data.push_back(' ');
		       
		  }
		     vector<int> vec;
		     int Max;
		    istringstream data2(data);
		    while(data2>>m)
		    {
		        vec.push_back(m.size());
		        // cout<<m.size()<<endl;
		    }
		    //find the biggest and its index
		    auto max = max_element(vec.begin(), vec.end());
		    Max =*max;
		    // auto min = min_element(vec.begin(), vec.end());
		    // Min =*min;

		    istringstream data3(data);
		    while(data3>>m)
		    {
		        if(m.size()==Max)
		            cout<<m;
		    }
		    cout<<','<<Max<<endl;
  	}

}

bool huawei::find_trajectory(int x, int y,int &num_line)
{
    if(x==0||y==0)
    {
        num_line+=1;
        return 1;
    }
    else
     find_trajectory(x-1,y,num_line);
     find_trajectory(x,y-1,num_line);
    
}
void huawei::compute_trajectory()
{
	// 思路就是　先往左边走一步(x-1)（步骤１）　和往往上一步(y-1)(步骤２)，　
	// 步骤１：刚才往左边走完一步之后　又有俩种选择　往左还是往上，
	// 步骤２：　刚才往上走一步之后　也有俩种选择　往左还是往上
	// 俩个步骤停止的criteria 都是通过检测x or y是否到达了边界
    int x,y;
    while(cin>>x>>y)
  {  
         int num_line=0;
        find_trajectory(x-1,y,num_line);
        find_trajectory(x,y-1,num_line);
        cout<<num_line<<endl;
    
   }
    
}

void huawei::legal_ip()
{
	// .首先合法的IP地址为: A.B.C.D,其中A,B,C,D的取值范围为0-255。
	    int a,b,c,d;
    char q,w,e;
    while(cin>>a>>q>>b>>w>>c>>e>>d)
    {
        if(q=='.'&&w=='.'&&e=='.')
        { 
            if(a>=0&&a<=255&&b>=0&&b<=255&&c>=0&&c<=255&&d>=0&&d<=255)
                cout<<"YES"<<endl;
            else
               cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}