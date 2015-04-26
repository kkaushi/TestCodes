/*
Push all the zero's of a given array to the end of the array. In place only. Ex 1,2,0,4,0,0,8 becomes 1,2,4,8,0,0,0
*/


/*Test cases
1. Simple 
arr[]={1,2,0,0,5,7,0};
2. Boundary (inclusive)
arr[]={1};
arr[]={0};
arr[]={0,1,1,1,1,0};
3. Boundary (exclusive)
arr[]={};
4. Average
arr[]={1,0,2,0,0,8};
*/


#include<iostream>
using namespace std;



void push_zero_back(int *a, int sz){
    if(sz==0)
        return ;
    int l=0,r=0;//left and right index
    while(r<sz && l<sz){
        while(a[r]!=0 && r<sz)
            r++;
        while(a[r]==0 && r<sz)
            r++;
		if (r == sz)//r condition as r may reach end of array 
			return;
        while(a[l]!=0 && l<sz && r<sz)
            l++;
		if(a[l]==0 && a[r]!=0){
            a[l]=a[r];
            a[r]=0;
        }
    }
    return ;
}

int main(){
    //int a[]={1,2,0,0,5,7,0,9};
    //Test cases
    //int a[]={1,2,0,0,5,7,0};
    //int a[]={1};
    //int a[]={0};
    //int a[]={0,1,1,1,1,0};
    //int a[]={};NOTE IT'S A COMPILATION ERROR
    int a[]={1,0,2,0,0,8};
    for(auto & i:a)
        cout<<i<<",";
    cout<<endl;    
    int size=sizeof(a)/sizeof(int);
    push_zero_back(a,size);
    cout<<"Size is:"<<size<<endl;
    for(auto & i:a)
        cout<<i<<",";
    cout<<endl;    
}