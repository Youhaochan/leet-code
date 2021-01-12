#include <headfile.h>

void string_learn::initialise(){
	this->name = "youhaochan";
	this->age = "18";
	this->country = "China";
	this->gender = "male";
	this->job = "still persuing his master degree";


}

void string_learn::print_initialise(){

cout<<"name is: "<<this->name<<endl;
cout<<"age is: "<<this->age<<endl;
cout<<"gender is: "<<this->gender<<endl;
cout<<"country is: "<<this->country<<endl;
cout<<"job is: "<<this->job<<endl;
}

void string_learn::input(){

cout<<"please input your name:";
string &new_name = this->name;
cin>>new_name;
vector<string> vec;
string a;
for(auto &i: new_name)
{
	a = toupper(i);
	i = toupper(i);
	cout<<a;
	vec.push_back(a);

// if(isspace(i))
// 	cout<<"\n";

}
cout<<"name is: "<<this->name<<endl;
string_learn::print_vector(vec);


}

void string_learn::print_vector(vector<string> vec )
{
	for(auto i : vec)
		cout<<i;

}