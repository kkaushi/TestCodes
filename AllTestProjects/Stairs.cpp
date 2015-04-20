#include<iostream>
using namespace std;

int count_ways(int n){
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return count_ways(n - 1) + count_ways(n - 2);
}

int main(){
	int n;
	cout << "Enter number of stairs:";
	cin >> n;
	cout << "Number of ways to climb " << n << " stairs:" << count_ways(n) << endl;
}