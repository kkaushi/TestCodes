#include<iostream>
#include<cstring>
using namespace std;

int print_par(int l, int r, int c, char* str)
{
	//if(l<0 || r < l || c>str.length())
	if(l<0 || r < l)
		return -1;
	if(l==0 && r==0)
	{	
		cout<<str<<"\n";
	}
	else
	{
		if(l>0)
		{
			str[c++]='(';
			print_par(--l,r,c,str);
		}
		if(r>l)
		{
			str[c++]=')';
			print_par(l,--r,c,str);
		}
	}
	return 1;
}

int main()
{
	int l=1,r=1,c=0,temp;
	char *str;
	cout<<"Enter the #:";
	cin>>l;
	r=l;
	//string str="      ";
	//str=(char *) malloc(sizeof(char)*(2*l+1));
	str=new char[2*l+1];
	memset(str,0,2*l+1);
	temp=print_par(l,r,c,str);	
	if(temp==-1)
		cout<<"It's error!";
	delete []str;
}
