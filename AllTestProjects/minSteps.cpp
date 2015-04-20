#include<iostream>
#include<algorithm>
using namespace std;

int imax = 2000, jmax = 2000;

int countSteps(int i, int j, int m, int n, int steps){
	if (i == m && j == n)
		return steps;
	if (i + j>imax || i + j>jmax || steps > 100)
		return -1;
	int right = countSteps(i + j, j, m, n, steps + 1);
	int down = countSteps(i, i + j, m, n, steps + 1);
	if (right > -1 && down > -1)
		return min(right, down);
	else if (right > -1)
		return right;
	else
		return down;
}

int minSteps(int m, int n){
	return countSteps(1, 1, m, n, 0);
}

int main(){
	int m = 14, n = 5;
	cout << "Min steps:" << minSteps(m, n) << endl;
}