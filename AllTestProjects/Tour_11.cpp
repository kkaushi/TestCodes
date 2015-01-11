//maps, stack, queue
#include<iostream>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int get_number(const string & s, map<string, int>&m){
	return m[s];
}
void main(){
	map<string, int> m{ { "red", 123 }, { "green", 345 }, { "yellow", 567 } };

	//traverse the map
	cout << "green is: " << get_number("green", m) << endl;
	cout << "red is: " << m["red"] << endl;
	cout << "yellow is: " << m["yellow"] << endl;

	cout << "------------ Stack -------------------\n";
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	cout << "Top of stack is: " << s.top() << endl;

	cout << "----------------- Queue ---------------------------\n";
	queue<int> q;
	q.push(10);
	q.push(20);
	cout << "Head of q: " << q.front() << endl;
}