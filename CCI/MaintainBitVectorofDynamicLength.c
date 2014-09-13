//Allocate and assign bit vector of nBits = no of Characters
#include<iostream>
#include<string>
using namespace std;


int main()
{
	int n,nChars,i;
	cout<<"Enter # of chars:";
	cin>>nChars;
	n=(nChars%8==0)?nChars/8:nChars/8+1;
	//char *bit_vector = (char *) malloc(sizeof(char));
	//char *bit_vector = new (sizeof(char));
	char *bit_vector = new char[n];
	cout<<"# of char blocks:"<<n<<"\n";
	cout<<"# of chars "<<nChars<<"\n";
	//Init with all zeros
	for(i=0;i<n;i++)
	{
		bit_vector[i]=0;	
	}

	for(i=0;i<nChars;i++)
	{
		bit_vector[i/8]|=1<<(i%8);			
		//int temp = 1<<(i%8);
		//cout<<"->"<<temp<<"\n";
	}
	for(i=0;i<nChars;i++)
	{
		int val=1<<(i%8);	
		int temp=bit_vector[i/8]&val>0?1:0;
		cout<<temp<<" -- ";	
	}
	cout<<endl;
}
