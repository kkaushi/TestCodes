#include<iostream>
using namespace std;

/*
void set_row(int * a, int len)
{
	int i=0;
	for(i=0;i<len;i++)
	{
		a[i]=0;
	}
}


void set_col(int a[4][4], int len, int col)
{
	int i=0;
	for(i=0;i<len*len;i+=len)
	{
		a[i][col]=0;
	}
}
*/


int set_mat(int **a, int r, int c){
	int * a_r = new int[r];
	int * a_c = new int[c];

	int i=0,j=0;
	
	//if array null return error
	if(a==NULL){
		return -1;
	}
	
	//initialize row and col arrays
	for(i=0;i<r;i++){
		a_r[i]=0;
	}
	for(j=0;j<c;j++){
		a_c[j]=0;
	}

	//check the matrix and set row/col array
	for(i=0;i<r;i++){
		if(!a_r[i]){
			for(j=0;j<c;j++){
				if(!a_c[j] && a[i][j]==0){
					a_r[i]=0;
					a_c[j]=0;
				}
			}
		}
	}

	//set the matrix now
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a_r[i]==1 || a_c[i]==1){
				a[i][j]=0;
			}
		}
	}
	return 0;
}


void main()
{
	int a[4][4] = {{1,2,3,0},{4,0,5,6},{7,8,9,10},{11,12,13,14}};
	//int **b = &a;
	int n=4,i=0,j=0;
	int temp;
	temp = set_mat(&a,4,4);
	
	if(temp==-1){
		cout<<"Error exiting!"<<endl;
		exit(0);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<"  ";
		}
		cout<<endl;
	}

}
