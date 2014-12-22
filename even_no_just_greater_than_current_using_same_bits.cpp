#include<iostream>
using namespace std;

int main()
{
	int n=0,temp=0,pos=0,pos_of1=0,pos_of0=0;
	unsigned int all_1;
	bool iseven;
	cout<<"Enter a no:";
	cin>>n;
	//n=20;
	iseven=(n&1==0)?false:true;
	
	if(n==0||n==1)
	{
		cout<<"no new even number can't be created using same bits (all bits are either 0 or 1's)"<<endl;
		return 0;
	}
		
	
	//cout<<"Entered no is even?"<<(bool)iseven<<endl;

	//look for the position of first 1 from right
	pos=1;
	temp=n;
	//cout<<(temp&1);
	while((temp&1)==0)
	{
		temp=temp>>1;
		pos++;
	}
	pos_of1=pos;
	temp=temp>>1;
	pos++;
	pos_of0=pos;
	while(temp&1!=0&&pos_of0<33)
	{
		pos_of0++;
	}
	
	//if no zero exists, new number would be just 1 left shifting of existing number;
	if(pos_of0==33)
	{
		//n=n<<1;
		cout<<"no new even number can't be created using same bits (as there is no bit=0)"<<endl;
	}
	else{

		//cout<<"first 1 and 0(left of 1) position are:"<<pos_of1<<" and "<<pos_of0<<endl;

		temp=1<<(pos_of0-1);
		n=n|temp;

		//setting all_1 to 1
		all_1=~0;
		//cout<<all_1;

		//setting last bit to 0
		all_1=all_1&(all_1-1);

		//rotating left till pos of 0
		//all_1=all_1<<pos_of1;a
		temp=1;
		while(temp<pos_of1)
		{
			all_1=all_1<<1;
			all_1=all_1|1;
			temp++;
		}

		//setting 0 at location of 1
		n=n&all_1;
	cout<<"New even no just greater than n is:"<<n<<endl;
	}

	return 0;
}