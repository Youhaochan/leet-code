#include <iostream>
#include <string>
#include <pointer.h>
using namespace std;

void pointer::array_pointer(){

	int var[] = {10,20,30};
 
   for (int i=0; i<3;i++)
   {
   		cout<<"before change the value of array: "<<*(var+i)<<endl;
      	*(var+i)=i;   // 这是正确的语法
     	cout<<"after change the value of array: "<<*(var+i)<<endl;
   }

// 定义一个指向整形或者ｃｈａｒ型的数组指针
    int var1[] = {100,200,300};
	int *ptr[3];// 这李把ptr声明为一个数组，由３个整数指针组成

	/***********/
	int (*ptr1)[3];//这是一个指向维度为３的整形数组的指针
	ptr1=&var1;// 　这里定义了一个指向３个整型的指针，　所以只要把数组的首元素赋值给指针，就可以用索引来对数组进行便利
	// 例如下面的
	/***********/
   for(int i=0;i<3;i++)
   {

   	cout<<"print the pointer: "<<(*ptr1)[i]<<endl;
   }

   for(int i=0; i<sizeof(var1)/sizeof(var1[0]);i++)
   {

   		ptr[i]=&var1[i];//save the array address in pointer array

   }

   for(int i=0; i<sizeof(var1)/sizeof(var1[0]);i++)
   {

   		cout<<"print the pointer array: "<<*ptr[i]<<endl;
   }
}

double pointer::transfer_pointer2function(int *arr,int size)
{
	double sum=0.0;
	for(int i=0;i<size;i++)
	{
			sum+=*arr;// 或者 sum+=arr[i];
			arr++;

	}
	return sum;
}


int *pointer::from_fun_return_pointer()
{//C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
	static int r[10]; 
	srand(time (NULL));
	for(int i=0;i<sizeof(r)/sizeof(r[0]);i++)
	{

		r[i] = rand();
		cout<<"the number generated is: "<<r[i]<<endl;
	}
	return r;
}

int &pointer::from_fun_return_yinyong( int *arr) // 这里是返回一个引用的函数　得到左值，　左指是不能给别人赋值的　只能放在等号左边
{//C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
	cout<< "the first element in this array is "<<*arr<<endl;
	return arr[0];
}

void pointer::pointer_operation(const int array[], int size_array){

	const int *ptr;
	ptr = array; // transfer the address of array to pointer
	auto s=sizeof(array)/sizeof(array[0]); // 这是错误的用法，不要再函数里面对传入的数组求元素个数，
	// 而应该在传入数组的时候就传入元素的个数
	cout<<"the size of array is : "<<size_array<<endl;
	for(int i=0; i<size_array;i++)
	{
		cout<<"each element in the original array is : "<<array[i]<<endl;

		cout<<"the element in the pointer  : "<<*ptr<<endl;
		ptr++; //递增指针
	}

	ptr=array;
	while(ptr<&array[size_array]) // 这里　是比较指针的地址　和数组的最后一个元素的地址
	{	
		cout<<"while iteration"	<<endl;
		cout<<"the element in the pointer  : "<<*ptr<<endl;
		ptr++; //递增指针

	}
}
// 定义和初始化指针
void pointer::define_pointer(int a)
{
  
  int *p = &a;
  cout<<"传进来的指等于：　"<<a<<endl;
  cout<<"指针所指的对象的地址是：　"<<p<<endl;
  cout<<"指针所指的对象的值是：　"<<*p<<endl;
  *p=100;
  cout<<"修改之后，指针所指的对象的值是：　"<<*p<<endl;
  cout<<"修改之后等于：　"<<a<<endl;
}
