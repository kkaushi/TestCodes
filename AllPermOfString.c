//To print all possible permutations of string
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


void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int i, int n)
{
	int j;
	if (i == n && a[0]!=0)
		printf("%s\n", a);
	else
	{
		for (j = i; j <= n; j++)
		{
			swap((a + i), (a + j));
			permute(a, i + 1, n);
			swap((a + i), (a + j)); //backtrack
		}
	}
}


/*
int main(){
	char a[] = { "abcd" };
	permute(a, 0, 3);
	getchar();
	return 0;
}
*/

int main()
{
	int i, j, n, num, ctr;
	char * str, **all_sets;
	char * temp_str;// = (char *)malloc(sizeof(char)*n);
	printf("Enter num of chars in string: ");
	scanf("%d",&n);
	scanf("%c", &j);
	num=(int)pow((double)2,(double)n);	
	printf("Enter a string: ");
	str=(char *) malloc(sizeof(char)*(n+1));
	temp_str = (char *)malloc(sizeof(char)*(n+1));
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
		ctr = 0;
		memset(temp_str, 0, n+1);
		//printf("%s\n",all_sets[i]);
		for(j=0;j<n;j++)
		{
			if (all_sets[i][n - j - 1] == 49){				
				temp_str[ctr++] = str[j];
			}
				//printf("%c",str[j]);			
		}
		if (temp_str[0] != 0){
			permute(temp_str, 0, ctr-1);
			//printf("%s\n", temp_str);
		}
	}
	return 0;
}
