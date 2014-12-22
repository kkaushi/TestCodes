//Program to merge 4 sorted arrays
#include<stdio.h>
#include<stdlib.h>

#define max(a,b) a>b?a:b

int * merge(int *a, int la, int*b, int lb, int *c, int lc, int*d, int ld){
	/*
	Varibale naming
		- a,b,c,d - 4 arrays
		- la,lb,lc,ld - length of a,b,c,d
		- pa,pb,pc,pd - pointer(index of) a,b,c,d
		- gc - index of global array
		- np - pointer to new array (ie merged array)
	*/
	int ea=0,eb=0,ec=0,ed=0;
	int pa=0,pb=0,pc=0,pd=0;
	int gc=0;
	int l=la+lb+lc+ld;
	int * np = (int *) malloc (sizeof(int)*l);

	int min=0;
	char minp=0;
	
	while(gc<l){
		min=max(max(max(a[pb],b[pb]),c[pc]),d[pd]);

		if(min>a[pa]&&!ea){min=a[pa]; minp='a';}
		if(min>b[pb]&&!eb){min=b[pb]; minp='b';}
		if(min>c[pc]&&!ec){min=c[pc]; minp='c';}
		if(min>d[pd]&&!ed){min=d[pd]; minp='d';}

		if(minp=='a'&&!ea)pa++;if(pa==la)ea=1;
		if(minp=='b'&&!eb)pb++;if(pb==lb)eb=1;
		if(minp=='c'&&!ec)pc++;if(pc==lc)ec=1;
		if(minp=='d'&&!ed)pd++;if(pd==ld)ed=1;

		np[gc++]=min;
	}
	return np;
}

int main(){
	int a[]={2,4,23,44,55};
	int b[]={7,14,21,46};
	int c[]={6,11,24,66};
	int d[]={1,3,9};
	int i=0;
	int *p=merge(a,sizeof(a)/sizeof(int),b,sizeof(b)/sizeof(int),c,sizeof(c)/sizeof(int),d,sizeof(d)/sizeof(int));
	printf("Sorted array is:\n");
	for(i=0;i<16;i++){
		printf("%d, ",p[i]);
	}
	return 0;
}

