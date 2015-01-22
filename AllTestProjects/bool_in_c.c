//bool in c
//unsigned int and signed int comparison
#include<stdio.h>
#include<stdbool.h>

int main()
{
	/*
	bool a = true;
	printf("%s\n", a ? "true" : "false");
	fputs(a ? "true" : "false", stdout);
	printf("\n");
	printf("\n");
	printf("\n");
	*/
	
	char z = '\012';//check out this octal number - z = 10

	char c = 125;
	c = c + 10;
	printf("%d", c);
	//result is -121 as bit pattern of 135 makes leftmost bit 1 (so -ve number)

	/*
	unsigned int x = -1;
	int y = ~0;
	
	if (x == y)
		printf("same");
	else
		printf("no");
	printf("\n");
	*/
	
	printf("\n");
	return 0;
}