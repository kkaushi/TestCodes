//Vectors and List Algorithms
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;

void print_vector(vector<int> &v){
	for (auto &a : v){
		cout << a << "\t";
	}
	cout << endl;
}

void print_list(list<int> l){
	for (auto &a : l){
		cout << a << "\t";
	}
	cout << endl;
}

void main(){
	vector<int> v;
	v.push_back(34);
	v.push_back(45);
	v.push_back(12);
	v.push_back(9);
	print_vector(v);	
	
	cout << "After sorting:" << endl;
	sort(v.begin(), v.end());
	print_vector(v);
		
	cout << "Creating list from vector(copy)" << endl;
	list<int> l;
	copy(v.begin(), v.end(), back_inserter(l));
	print_list(l);

}