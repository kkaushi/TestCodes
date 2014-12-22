#include<stdio.h>

int main()
{
	int a,b,i=0;
	//while(scanf("%d",&a))
	//while(scanf("(%d,%d),",&a,&b))
	//while(scanf("(%d,%d),",&a,&b))
	//i=scanf("(");
	//Scanf just reads the first character from stdin
	i=scanf("(%d%d",&a,&b);
	//while(scanf("("))
	while(i)
	{
		printf("(%d,%d),",a,b);
	}
	return 0;
}