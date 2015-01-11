//File handling, stream iterators
//Not working
#include<iostream>//cin, cout
#include<iterator>//iterator
#include<string>//string operations
#include<set>// set of strings to avoid duplicate
#include<algorithm>//copy operation
#include<fstream>//file stream
using namespace std;


int main(){
	string from, to;
	//cin >> from >> to;
	from = "a.txt";
	to = "b.txt";
	ifstream is{ from };
	ofstream os{ to };

	set<string> b{ istream_iterator < string > {is}, istream_iterator < string > {} };//read input
	copy(b.begin(), b.end(), ostream_iterator < string > {os, "\n"});

	return !is.eof() || !os;
}