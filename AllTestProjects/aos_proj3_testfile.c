#include<stdio.h>
#include<stdlib.h>

void print_buf(char * buffer)
{
	printf("one:%d\n",buffer[0]);
	printf("two:%d\n",(buffer[1]<0)?buffer[1]+256:buffer[1]);
}

void dummy()
{
	char * buf=(char *) malloc(sizeof(char)*256);
	memset(buf,0,256);
	buf[0]=1;
	buf[1]=0xC0;
	buf[2]='1923';
	print_buf(buf);	
}
void main()
{
	dummy();
	
	/*int i=0,val=0;
	for(;i<8;i++){
		val=val+1<<i;
		printf("%d\n",1<<i);
	}*/
}