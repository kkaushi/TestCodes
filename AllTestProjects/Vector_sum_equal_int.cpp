#include<iostream>
#include<vector>
using namespace std;

bool seq_exists(vector<int> v, int sum){
    int s=0;
    for(auto &a: v)
        s+=a;
        
    if(s==sum)
        return true;
    else
    {
        vector<int> temp_left, temp_right;
        temp_left=v;
        temp_left.pop_back();
        temp_right=v;
        temp_right.erase(temp_right.begin());
		if (temp_left.size() == 0 && temp_right.size() == 0)
			return false;
		else if (temp_left.size() == 0)
			return seq_exists(temp_right, sum);
		else if (temp_right.size() == 0)
			return seq_exists(temp_left, sum);
		else
			return (seq_exists(temp_left,sum)||seq_exists(temp_right,sum));
    }        
}

int main(){
	cout << seq_exists(vector < int > {4, 3, 6, 7, 9, 1}, 2) << endl;
	return 0;
}