//second keyword in pair, functor and lambda function, find_if
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

struct entry{
	string name;
	int value;
};

int ret_second(pair<string,int> e){
	return e.second;//second keyword is in pair
}

struct Greater_than{
	int val;
	Greater_than(int v) :val{ v }{}//constructor
	//functor
	bool operator()(const pair<string, int> & r){
		return r.second > val;
	}
};

void main(){
	map<string, int> m;
	m.insert({ "hello", 24 });
	m.insert({ "there", 4 });
	m.insert({ "happy", 13 });
	m.insert({ "new", 45 });
	m.insert({ "year", 254 });
	
	//iterator
	//output of map is sorted
	for (auto &a : m){
		cout << a.first << "\t" << a.second << endl;
	}

	cout << "Find if:" << endl;
	//find_if any pair with val > 23
	auto a = find_if(m.begin(), m.end(), Greater_than(23));
	cout << a->first << "\t" << a->second << endl;

	//using lambda function
	a = find_if(m.begin(), m.end(), [&](const pair<string, int> & r){return r.second > 23; });
	cout << a->first << "\t" << a->second << endl;
	
}