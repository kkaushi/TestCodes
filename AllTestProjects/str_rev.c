//Reverse a string in c by using xor to swap
//reference : stackoverflow: http://stackoverflow.com/questions/198199/how-do-you-reverse-a-string-in-place-in-c-or-c
#include <stdio.h>

void strrev(char *p)
{
	char *q = p;
	while (q && *q) ++q;
	for (--q; p < q; ++p, --q)
		*p = *p ^ *q,
		*q = *p ^ *q,
		*p = *p ^ *q;
}

int main(int argc, char **argv)
{
	/*
	do {
		printf("%s ", argv[argc - 1]);
		strrev(argv[argc - 1]);
		printf("%s\n", argv[argc - 1]);
	} while (--argc && argc > 1);
	return 0;
	*/


	/*
	char name[] = "Kuldeep";
	printf("%s \n", name);
	strrev(name);
	printf("%s \n", name);
	*/

	char c = 'q', d = 'q';
	d = d ^ c;
	printf("%c\n", d);

}