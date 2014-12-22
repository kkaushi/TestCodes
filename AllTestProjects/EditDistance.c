#include<stdio.h>

/*char str1[]={"This is Ind"};
char str2[]={"This is USA"};
int Edit[15][15]={0};


int min(int i, int j, int flag)
{
	if(flag==0)
	{
		return(Edit[i-1][j-1]>(Edit[i][j-1]+1)?((Edit[i][j-1]+1)>(Edit[i-1][j]+1)
			? (Edit[i-1][j]+1):(Edit[i][j-1]+1)):(Edit[i-1][j-1]>(Edit[i-1][j]+1)?(Edit[i-1][j]+1):Edit[i-1][j-1]));
	}
	else
	{
		return((Edit[i-1][j-1]+1)>(Edit[i][j-1]+1)?((Edit[i][j-1]+1)>(Edit[i-1][j]+1)
			? (Edit[i-1][j]+1):(Edit[i][j-1]+1)):((Edit[i-1][j-1]+1)>(Edit[i-1][j]+1)?(Edit[i-1][j]+1):(Edit[i-1][j-1]+1)));
	}
}
int EditDist(int len_s1,int len_s2)
{
	int i,j=0;
	for(j=0;j<len_s2;j++)
		Edit[0][j]=j;
	for(i=0;i<len_s1;i++)
	{
		Edit[i][0]=i;
		for(j=1;j<len_s2;j++)
		{
			if(str1[i]==str2[j])
			{
				Edit[i][j]=min(i,j,0);
			}
			else
			{
				Edit[i][j]=min(i,j,1);
			}
		}
	}
	return Edit[len_s1-1][len_s2-1];

}
void main()
{
	printf("Edit Distance:%d\n",EditDist(11,13));
}*/


// Macro testing

//#define Max(a,b) (a>b?a:b)
//or
#define Max(a,b) (_typeof_ (a)_a=(a); _typeof_ (b)_b=(b); _a>_b?_a:_b;)

void main()
{
	int i=4,j=5,mx;
	mx=(int)Max(i,j);
	printf("%d\n",mx);
}