#include<iostream>
using namespace std;

int main()
{
	int m,n;
	int ** mat;
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
	cout<<"It's done!"<<endl;
}
