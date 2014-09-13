//Reverse a string in less than O(n)
#include<iostream>
#include<math.h>
using namespace std;

int partition(int start,int a[],int pivot,int size)
{
	int left=start,right=start+size-1,temp,newpivot,pivotvalue;
	static int flag1,flag2;
	//pivotvalue=a[pivot];
	
	//we stop when left==right or left>right
	while(left<right)
	{
		//flag is one if we need to swap ie the current element is at incorrect position relative to the pivot value
		if(a[right]<=a[pivot])
			flag1=1;
		else
		//flag is 0 if the current element is at the correct position 
			flag1=0;		
		
		//same here for the left position
		if(a[left]>=a[pivot])	
			flag2=1;
		else 
			flag2=0;

		//if both right and left are at incorrect positions
		if(flag1==1 && flag2==1)
		{
			//swapping of values at the left and right positions
			temp=a[right];
			a[right]=a[left];
			a[left]=temp;
			
			
			//and the following if and else assigns new value to the pivot index as the 
			//pivot value has been swapped
			if(right==pivot)//as after swapping right value becomes left
				pivot=left;
			else if(left==pivot)//as after swapping left value becomes right
				pivot=right;
			
			
			//if left or right is at pivot position, we donot move the left or right index (the if 
			//condition checks that)
			
			
			//in cases of value at some index(left or right) ==pivot value but index are different(from pivot (ie
			//in the case of array containing multiple values same as pivot value)) we move the indexes  
			//after swapping ie left++ and right--

			if(left!=pivot)
				left++;
			if(right!=pivot)
				right--;
		}	
		
		//if left index value is at correct position and we want to move the left index(there is a difference 
		//in index value and the index itself ie left and right are indexes whereas the values at left and
		//right are compared to the values at pivot index; pivot is also a index)
		if(left<=start+size-1 && flag2==0)
			left++;
		if(right>0 && flag1==0 )
			right--;
	}
	
	if(left>=right)
		return pivot;
}

void quicksort(int start,int stop,void * a)
{
	int size,pivot,centerIndex;
	//pivot is the index of the pivot value
	//case of single element arrays
	if(start>=stop)
		return;
	size=stop-start+1;
	//same some case of single element arrays
	if(size==1 || size==0)
		return;
	
	if(size%2!=0)
		pivot=start+(size-1)/2;
	else
		pivot=start+size/2;
	centerIndex=partition(start,(int *)a,pivot,size);
	quicksort(start,centerIndex-1,a);
	quicksort(centerIndex+1,stop,a);
}
 

void str_reverse(string str)
{
	/*
	int length=str.length();
	int nByte=ceil((float)length/8);
	char *bitVector=new char [nByte];
	for(int i=0;i<length;i++)
	{
		bitVector[i]=0;
	}
	for(int i=0;i<lenght;i++)
	{
		str[i]%
	*/
}

int main()
{
	string str1;	
	cout<<"Enter a string:";
	cin>>str1;
	const int length=str1.length();
	int str[length];
	for(int i=0;i<length;i++)
	{
		str[i]=(int)str1[i];
	}
	
	quicksort(0,length-1,str);

	/*
	for(int i=0;i<length;i++)
	{
		cout<<str[i]<<" "<<(int)str[i]<<"\n";
	}
	*/
	for(int i=0;i<length-2;i++)
	{
		if(str[i]==str[i+1])
		{
			cout<<"Duplicate entry!\n";
			break;
		}
		if(i==length-3)
			cout<<"No Duplicate!\n";
	}
}
