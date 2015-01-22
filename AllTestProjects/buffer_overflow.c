#include<stdio.h>

void main(int argc, char * argv[]){
	int flag = 0;
	char passwd[10];

	memset(passwd, 0, sizeof(passwd));
	strcpy(passwd, argv[1]);

	if (0 == strcmp(passwd, "HelloThere"))
	{
		flag = 1;
		
	}
	/*
	else
	{
		flag = 0;
	
	}
	*/
	
	if (flag){
		printf("%s\n", "Cracked");
	}
	else{
		printf("%s\n", "not cracked");
	}
	return;
}