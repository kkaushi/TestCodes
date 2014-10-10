#include<iostream>
using namespace std;


void rem_c(char *s, int len)
{
	s[len-1]=0;//terminating condition 
	char *b, *e;
	b=s;
	e=s;
	while(*e!=0)
	{
		if(*e==',')
		{
			if(b==s)
				b=e;
			while(*e==',' && *e != 0)
			{
				e++;
			}
			if(*e==0)
			{
				*b=0;
				return;
			}
			else
			{
				*b=*e;
				b++;
			}
		}
		else if(b!=s)
		{
			*b=*e;
			b++;
		}
		e++;
	}
	*b=0;
}

int main()
{
	char str[]="ab,,c,,def,gh,,X";
	rem_c(str,16);	
	cout<<str<<endl;
}
