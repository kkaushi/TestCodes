#include<stdio.h>
#include<stdlib.h>

//Reverses a String
void reverse_string (char *str) {
    char temp, *end = &(str[strlen (str) - 1]);
    while (end > str) {
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
}

//Converts Integer to Binary
void intToBinary(int num)
{
	char * bin=malloc(sizeof(char));	
	int nChars=0;
	while(num!=0 && num!=1){
		//(num%2==0)?((bin<<1)|0):((bin<<1)|1);
		//(num%2==0)?printf("0"):printf("1");
		(num%2==0)?(bin[nChars]=48):(bin[nChars]=49);
		num/=2;
		nChars++;
		(void *)realloc(bin,sizeof(char)*(nChars+1));
	}
	bin[nChars]=48+num;
	reverse_string(bin);
	printf("%s\n",bin);
}
void main()
{
	int number = 12;
	intToBinary(number);
}

