//cnt nzeros after 1's in array
//input eg - 1,1,0,0,0 op - 3
//input eg - 1,0,0 op - 2
#include<stdio.h>

void cnt_zero(int *a, int len, int l,int r){
	int mid;
	
	if(a==NULL){printf("No array\n");return;}
	if(len==0){printf("len is zero\n");return;}
	if(l>r){printf("no zeros\n");return;}
	if(a[0]==0){printf("%d\n",len);return;}

	mid=(l+r)/2;

	if(a[mid]==1 && a[mid+1]==0){printf("%d\n",r-mid);return;}
	if(a[mid-1]==1 && a[mid]==0){printf("%d\n",r-mid-1);return;}

	if(a[mid]==1){cnt_zero(a,len,mid+1,r);return;}
	else{cnt_zero(a,len,l,mid-1);return;}
}


void main()
{
	int a[]={1,1,1,1,1,0,0,0,0};
	int b[]={1,1,0,0,0,0,0,0,0};
	int c[]={0,0,0};
	int d[3];
	int e[]={1,1,1,1,1,1};
	cnt_zero(a,9,0,8);
	cnt_zero(b,9,0,8);
	cnt_zero(c,3,0,2);
	cnt_zero(d,0,0,0);
	cnt_zero(e,6,0,5);
}
