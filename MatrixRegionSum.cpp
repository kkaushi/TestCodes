#include<iostream>
using namespace std;

int main()
{
	int m,n;
	int ** mat;
	//top-left, bottom-right variable	
	int t,l,b,r;
	cout<<"Enter m,n";
	cin>>m>>n;
	cout<<"M is:"<<m<<" N is: "<<n<<endl;
	
	//Create matrix 
	//*mat=(int *)malloc(m*sizeof(int));
	//Alloc m pointers 	
	mat=new int* [m];	
	//Alloc memory for individual rows
	for(int i=0;i<m;i++)
	{
		mat[i]=new int [n];
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"Enter element("<<i<<","<<j<<"):";
			cin>>mat[i][j];
		}
	}
	
	//Precalculation step
	int ** sum_matrix=new int* [m];
	for(int i=0;i<m;i++)
	{
		sum_matrix[i]=new int [n];	
	}

	//top row sum
	sum_matrix[0][0]=mat[0][0];
	for(int i=1;i<n;i++)
	{
		sum_matrix[0][i]=sum_matrix[0][i-1]+mat[0][i];
	}
	
	//left col sum
	sum_matrix[0][0]=mat[0][0];
	for(int i=1;i<m;i++)
	{
		sum_matrix[i][0]=sum_matrix[i-1][0]+mat[i][0];
	}

	//other regions
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			sum_matrix[i][j]=mat[i][j]+sum_matrix[i-1][j]+sum_matrix[i][j-1]-sum_matrix[i-1][j-1];
		}
	}


	//printing sum_matrix
		
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<sum_matrix[i][j]<<" ";
		}
	}

	
	//Get the region now :)
	cout<<"Enter the region top,left,bottom,right edge";
	cin>>t>>l>>b>>r;
	int sum = sum_matrix[b][r]+sum_matrix[t][l]-sum_matrix[b][l]-sum_matrix[t][r];
	cout<<"Sum is:"<<sum<<endl;
}
