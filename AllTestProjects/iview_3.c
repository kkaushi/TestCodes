//int var = var;
//typedef struct name{} name;

#include <stdio.h>

typedef struct my_struct
{
	int i;
	char c;
	float f;
} my_struct;//names are same

int var = 20;
int main()
{
	/*
	int var = var;
	printf("%d ", var);
	*/

	my_struct ms = { 1, 'a', 3.14 };
	printf("%d, %c, %f\n", ms.i, ms.c, ms.f);

	return 0;
}