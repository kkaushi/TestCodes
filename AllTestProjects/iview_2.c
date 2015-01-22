//macros
#include<stdio.h>
#define NPRINT(i,n) while(i<n)\
					{\
						printf("%d\t",i);\
						i++;\
					}

#define PRINT_NAME(name) #name

//avoid macros with params as they might give unexpected results sometimes
#define SQUARE(x) x*x
//use inline functions instead. They are type safe
__inline int square_x(int x)
{ 
	return x*x; 
}

int main()
{
	
	int i = 1;
	//output 1 2 3
	NPRINT(i, 4);
	printf("\n");
	printf("%s\n", PRINT_NAME(KULdeep));//string literal here

	int v = 36 / SQUARE(6);
	printf("Result of 36/(Square of 6) using macro:%d\n",v);
	v = 36 / square_x(6);
	printf("Result of 36/(Square of 6) using inline function:%d\n", v);
	printf("\n");

	//some standard defined macros in C
	printf("Current File :%s\n", __FILE__);
	printf("Current Date :%s\n", __DATE__);
	printf("Current Time :%s\n", __TIME__);
	printf("Line Number :%d\n", __LINE__);

	return 0;
}