#include<iostream>
#include<list>
using namespace std;

void main()
{
	list<int> l = { 1, 2, 3 };
	//traverse list
	auto &a = l.begin();
	for (;a!=l.end();a++){
		cout << *a << "\t";
	}
	cout << "\n";

	//insert in list
	l.insert(a, 4);

	//traverse again
	a = l.begin();
	for (; a != l.end(); a++){
		cout << *a << "\t";
	}
	cout << "\n";


	//remove from first
	a = l.begin();
	l.erase(a);
	
	//traverse again
	a = l.begin();
	for (; a != l.end(); a++){
		cout << *a << "\t";
	}
	cout << "\n";

	//traverse using range for loop
	for (auto &i : l){
		cout << i << "\t";
	}
	cout << endl;

	//travers using iterator
	for (list<int>::iterator i = l.begin(); i != l.end();i++){
		cout << *i << "\t";
	}
	cout << endl;

	l.push_back(5);
	l.insert(l.end(), 6);
	l.insert(l.begin(), 0);

	//traverse using range for loop
	for (auto &i : l){
		cout << i << "\t";
	}
	cout << endl;

}