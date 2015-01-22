#include<stdio.h>
//return value of getchar(), fgetc(), getc() is integer
//puts vs printf
//my_strcmp, my_strcat
//const vs macro

void my_strcat(char *dest, char *src)
{
	(*dest) ? my_strcat(++dest, src) : (*dest++ = *src++) ? my_strcat(dest, src) : 0;
}

int my_strcmp(char *dest, char* src)
{
	(*dest==*src && *dest == '\0')?0:(*dest == *src) ? my_strcmp(dest++, src++) : 1;
}

int main()
{
	/*
	int i;
	while ((i = getchar()) != EOF)
	{
		//putchar(i);
		//printf("%d", i); - this prints i + 10, 10 due to getchar()
		printf("%c", i);
	}
	*/

	//fputs write to stdout
	//fputs("Geeksfor", stdout);
	//fputs("Geeks", stdout);

	
	/*
	//fgets receives from stdin
	char str[5];
	fgets(str, 5, stdin);
	fputs(str, stdout);
	*/

	//avoid printf in case of formatting chars in string like %
	/*printf("%sGeek\n");
	puts("%sGeek\n");
	*/

	//print % using printf
	/*
	printf("%c", '%');
	printf("\n");
	*/

	//%ns - read max of n chars from console
	/*
	char str[5];
	scanf("%4s", str);
	puts(str);
	*/

	//difference in size of string with "" and ''
	/*
	char ch[] = "hello";
	printf("%d", sizeof(ch));//6
	char ch1[] = { 'h', 'e', 'l', 'l', 'o' };
	printf("%d", sizeof(ch1));//5
	*/

	/*
	char s[100] = "alright";
	char t[100] = "there";
	my_strcat(s, t);
	printf("%s\n", s);
	*/

	//const vs macro
	#define SZ 10
	const int size = 10;
	//int arr[size];//error as size is not a constant but a constant variable
	int arr[SZ];// not an error

	return 0;


}