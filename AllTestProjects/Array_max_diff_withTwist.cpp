/*
Completely blew it on this question today. 

1.) Given an array, find the maximum difference between two array elements given the second element comes after the first. 

For example. 

array = [1,2,3,4,5,6,7] 

We can take the difference between 2 and 1 (2-1), but not the different between 1 and 2 (1-2). 

This question is super easy, I solved it within minutes of getting of the phone. I came up with an O(n^2) solution over the phone. My improved solution was O(n).

*/


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define ERROR INT_MAX

int ret_diff(vector<int> v){
    if(v.size()==0||v.size()==1)
        return ERROR;
	int min=v[0], max_diff=INT_MIN;
    for(auto &a: v){
        if(a-min>max_diff)
            max_diff=a-min;
        if(a<min)
            min=a;
    }
	return max_diff;
}

int main(){
	/*Test cases
	1. Simple case : cout << ret_diff(vector < int > {14, 8, 3, 9, 13, 2, 11}) << endl;
	2. Boundary conditions:
		a) Inclusive: 
			cout << ret_diff(vector < int > {14}) << endl;
			cout << ret_diff(vector < int > {1, 8, 3, 9, 13, 2, 14}) << endl;
			cout << ret_diff(vector < int > {14,1}) << endl;
		b) Exclusive
			cout << ret_diff(vector < int > {}) << endl;
			cout << ret_diff(vector < int > {1}) << endl;
	3. Average cases;
	cout << ret_diff(vector < int > {3, 9, 13, 2, 11}) << endl;
	cout << ret_diff(vector < int > {14, 8, 3, 9, 13, 2, 11,14, 8, 3, 9, 13, 2, 11}) << endl;
	cout << ret_diff(vector < int > {14, 8, 3, 9, 133}) << endl;
	*/
	
	cout << ret_diff(vector < int > {14, 8, 3, 9, 13, 2, 11}) << endl;
	cout << ret_diff(vector < int > {14,14}) << endl;
	cout << ret_diff(vector < int > {1, 8, 3, 9, 13, 2, 14}) << endl;
	cout << ret_diff(vector < int > {14,1}) << endl;//0 because a[0]-a[0]
	cout << ret_diff(vector < int > {}) << endl;
	cout << ret_diff(vector < int > {1}) << endl;
	cout << ret_diff(vector < int > {3, 9, 13, 2, 11}) << endl;
	cout << ret_diff(vector < int > {14, 8, 3, 9, 13, 2, 11, 14, 8, 3, 9, 13, 2, 11}) << endl;
	cout << ret_diff(vector < int > {14, 8, 3, 9, 133}) << endl;
	
	
}