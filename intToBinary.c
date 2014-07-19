#include<stdio.h>

void intToBinary(int num)
{
	int bin=0;
	while(num!=0 || num!=1){
		(num%2==0)?((bin<<1)|0):((bin<<1)|1);
		num%=2;
	}
	printf("%d\n",bin);		 
}

void main()
{
	int number = 12;
	intToBinary(number);
}

