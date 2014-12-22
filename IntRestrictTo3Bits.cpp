#include<iostream>
#include<sstream>
using namespace std;


int main()
{
	int type;
	float temp,num;
	ostringstream convert;
	cout<<"Enter the number:";
	cin>>num;
	temp=num;
	
	if(num>1000000000)
	{
		temp=num/1000000000;	
		type=4;
	}else if(num<=1000000000 && num > 1000000)
	{
		temp=num/1000000;	
		type=1;
	}else if(num <= 1000000 && num > 1000)
	{
		temp=num/1000;
		type=2;
	}else if(num < 1000)
	{
		temp=num;
		type=3;
	}
	
	//supress to 3
	string str;
	convert << temp;
	str=convert.str();
	char * s=new char[6];
	str.copy(s,4,0);	
	if(type==3)
		s[4]==' ';
	else if(type==2)
		s[4]='K';
	else if(type==1)
		s[4]='M';
	else if(type==4)
		s[4]='G';
	s[5]=0;
	cout<<"Number now is:"<<s<<"\n";
}
