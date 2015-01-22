//static aggregate object members values without initialization
//static can only be initialized using constant literals.
//volatile, register keyword
#include<stdio.h>

typedef struct s
{
	int i;
	char c;
	float f;
	char * pc;
} s;

static s ob;

int ret_ten()
{
	return 10;
}

int main()
{
	//printf("%d, %c, %f, %p\n", ob.i, ob.c, ob.f, ob.pc);

	/*
	const int val = 10;
	int * pi = (int *)&val;
	*pi = 100;
	printf("*p:%d, val:%d\n", *pi, val);
	*/
	
	
	//static int val = ret_ten();//compile time error: initializer not constant

	register int i = 10;
	int *a = &i;//error here & on register variable
	printf("%d", *a);
	
	return 0;
}