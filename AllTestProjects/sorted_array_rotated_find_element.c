#include<stdio.h>

int find_element(int * a, int len, int l, int u,int x){
	int m;
	while(l<=u){
		m=(l+u)/2;
		if(x == a[m]){ printf("Location :%d\n",m);return 0;}
		//low to middle in sorted
		else if(a[l]<=a[m]){
			if(x>a[m])l=m+1;
			else if(x>=a[l])u=m-1;
			else l=m+1;//applies if different segment
		}
		else if(x<a[m]){u=m-1;}
		else if(x<=a[u]){l=m+1;}
		else u=m-1;
	}
	find_element(a,len,l,u,x);
	return -1;
} 

void main()
{
	//int a[]={15,16,18,25,36,37,1,3,6,7};
	int a[]={16,18,25,36,37,1,3,6,7};
	int len=sizeof(a)/sizeof(int);
	find_element(a,len,0,len-1,3);
	return 0;
}

