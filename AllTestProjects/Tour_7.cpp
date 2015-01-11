//Stringstream, template with default args
#include<iostream>
#include<exception>
#include<string>
#include<sstream>//required for stringstream
using namespace std;

template<typename Target=string, typename Source=string>
Target to(Source src){
	Target tar;
	stringstream sstr;
	if (!(sstr << src)//getting from source into stringstream
		|| !(sstr >> tar)//getting target string from stringstream into target
		|| !(sstr >> std::ws).eof())//if anything else left in stream
		//std::ws Extracts as many whitespace characters as possible from the current position in the input sequence. So, 
		//the above statement reads whitespaces till an eof if found. If anything else is found throw exception.
		throw runtime_error{" to<>()failed"};
	return tar;
}
void main(){
		string s = "hello";
		auto t = to<string,string>(s);
		cout << t << "\n";

		auto n = to(1.4);
		cout << n << "\n";
}
