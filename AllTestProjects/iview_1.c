#include<stdio.h>

//fn will accept any params in c
void fn(){ printf("fn called\n"); }

//same here
void f(void){ printf("f called \n"); }

//swap without extra memory
void swap_xor(int* a, int *b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

//swap another way without extra memory
void swap_plusminus(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main(void)
{
	//fn(10);	
	///f(20,"Hello", "There");

	//predict output 1: static int, calling main
	/*static int i = 5;
	if (--i){
		printf("%d ", i);
		main(10);
	}
	//output 4 3 2 1
	*/
	

	/*
	//output 2: float comparison
	float x = 0.1;
	float y = 0.5;

	if (x == 0.1)
		printf("IF");
	else if (x == 0.1f)
		printf("ELSE IF");
	else
		printf("ELSE");
	//prints else if as in floating point in binary.1 is not exactly represented as .1 
	//this limitation is because not all numbers in decimal fractions can be converted into binary

	printf("\n");

	if (y == 0.5)
		printf("IF");
	else if (y == 0.5f)
		printf("ELSE IF");
	else
		printf("ELSE");
	//prints if
	//0.5 is 0.1 in binary
	*/

	int a = 5, b = 7;
	a = 4;
	b = 4;
	swap_xor(&a, &b);
	printf("a:%d, b:%d\n", a, b);
	swap_plusminus(&a, &b);
	printf("a:%d, b:%d\n", a, b);
	
	
	
	
	
	
	
	
	
	
	
	printf("\n");
	return 0;
}
