#include<stdio.h>
//function prototype necessary in c, otherwise compile error or may not be error as compiler assumes return type
//refer here: http://www.geeksforgeeks.org/what-is-the-purpose-of-a-function-prototype/

//arry vs pointer differences. refere here: http://www.geeksforgeeks.org/g-fact-5/

/*
void foo();

int main()
{
	foo();
	getchar();
	return 0;
}
void foo()
{
	printf("foo called");
}
*/

int main()
{
	int a[3] = {1,2,3};
	int *p;
	p = a;
	p++;
	printf("%d\n", *p);
	//a++;//error. array variables cant use arithmetics (allowed for pointer variables)
	return 0;
}


