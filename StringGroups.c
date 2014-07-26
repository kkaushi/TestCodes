/*
 * Program to check if a group of strings belong to another group of strings.
 *
 */

#include<stdio.h>
#include<string.h>

void main()
{
	char s1[]="This ";
	char s2[]="is ";
	char s3[]="Amerika ";
	
	char* ptr[3], *strs[2];
	int i,j,indx[2]={0,0};
	
	ptr[0]=s1;
	ptr[1]=s2;
	ptr[2]=s3;
	
	strs[0]=s1;
	strs[1]=s2;
	
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			if(indx[i]!=1)	
			{
				(strcmp(*(strs+i),*(ptr+j))==0)?(indx[i]=1):(indx[i]=0);
			}
		}
	}
	printf("Indx array is:%d, %d\n", indx[0], indx[1]);		
}

