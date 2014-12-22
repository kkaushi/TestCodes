#include<stdio.h>
#include<string.h>
#include<math.h>

//Integer to binary representation
void toBinary(int i,int n,char * str)
{
	int j,k,temp,pos=0;
	temp=i;
	pos=n-1;
	while(temp!=0)
	{
		//str[pos--]=(temp%2==1)?49:48;
		if(temp==1)
		{
			str[pos]=49;
			break;
		}
		if(temp%2==0)
			str[pos--]=49;
		else
			str[pos--]=48;
		temp/=2;
	}
}
	
int main()
{
	int i,j, n,num;
	char * str, **all_sets;
	printf("Enter num of chars in string: ");
	scanf("%d",&n);
	scanf("%c",&j);
	num=(int)pow((double)2,(double)n);	
	printf("Enter a string: ");
	str=(char *) malloc(sizeof(char)*(n+1));
	str[n]=0;
	for(i=0;i<n;i++)
	{
		scanf("%c",&str[i]);
	}	
	
	all_sets=(char **) malloc(sizeof(char *) * num);	
	for(i=0;i<num;i++)
	{
		all_sets[i]=(char *) malloc(sizeof(char)*(n+1));
		memset(all_sets[i],48,n);
		all_sets[i][n]=0;
		toBinary(i,n,all_sets[i]);
	}
	for(i=0;i<num;i++)
	{
		//printf("%s\n",all_sets[i]);
		for(j=0;j<n;j++)
		{
			if(all_sets[i][n-j-1]==49)
				printf("%c",str[j]);
		}
		printf("\n");	
	}
	return 0;
}
