
/*main 函数所需要的头文件都在headfile.h　里面*/
#include <headfile.h>
int main(int argc, char** argv)
{
	Matrix4d T = Matrix4d::Identity(4, 4);
	cout<<"/************************************************************/\n"<<endl;
    cout<<"类的用法"<<endl;
	/* 类的用法  */
	sale_data_struct sale_data1;
	sale_data1.bookNo="numerical optimization from struct";
	cout<<sale_data1.isbn()<<endl;

	sale_data_class sale_data2;
	sale_data2.set_bookid("numerical optimization from class");
	cout<<sale_data2.isbn()<<endl;
	cout<<"/************************************************************/\n"<<endl;
	cout<<"the usage of pointer "<<endl;
	/*　指针的用法	*/
	pointer Pointer;
	Pointer.define_pointer(10);
	// define an array
	int arr[] = {10,100,200};
	cout<<"size of array: "<<sizeof(arr)/sizeof(arr[0])<<endl;
	Pointer.pointer_operation(arr,3);
	Pointer.array_pointer();
	int sum =Pointer.transfer_pointer2function(arr,3);
	cout<<"the average sum is equal to :"<<sum<<endl;


	int *ran;
	ran = Pointer.from_fun_return_pointer();
	cout<<"the number generated is as below:　\n";
	for(int i=0;i<10;i++)
	{

		cout<<*(ran+i)<<endl;
	}

// 返回引用函数类型  这种函数调用可以用来改变函数内部变量的值
	Pointer.from_fun_return_yinyong(arr) = 100; //change the value that passed into the function
	cout<<"after change the value, the fist element of array called arr is equal to "<<arr[0]<<endl;
	int p = 10000;
	
	cout<<"/************************************************************/\n"<<endl;
    string_learn people;
    people.initialise();
    people.print_initialise();
    people.input();
    // people.print_initialise();
    cout<<"/************************************************************/\n"<<endl;
   
	testfunc test;
	test.outputworld();
	func_test();
	cout<<"T:"<<T*T.inverse()<<endl;


	return 0;

}
