#include<stdio.h>
int Arr[]={8,7,9,11,13,17,25,6};


int LIS(int prev,int begin)
{
	int max=0,len=0;
	if(begin==7)
		return 0;
	else
	{
		max=LIS(prev,begin+1);
		if(Arr[begin]>prev)
		{
			len=1+LIS(Arr[begin],begin+1);
			if(len>max)
				max=len;
			return max;
		}
	}
}
void main()
{
		int count=LIS(-1,0);
		printf("count:%d\n",count);
}