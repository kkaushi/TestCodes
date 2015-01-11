//Microsoft Megan Question - Reverse string keeping words same
//input "Hello world" output "world Hello"
#include<iostream>
#include<string>
using namespace std;


string rev_string(string str){
	string s;
	//Test case 1 handling
	if (str == "")
		return "";
	//end is the end index of current word
	//initial end is equal to the last index of string
	int end = str.size();
	//Test case 2 handling
	if (str.size()==1)
		return str;
	//Random cases 
	for (int i = str.size()-1; i >= 0; i--){
		// i is space
		//i + 1 is where we start to copy till end
		//end - i is the length of newStr
		if ((str[i] == 32 && i+1<str.size()) ||\
			(i==0)){
			string newStr = (i==0)?str.substr(i,end-i):str.substr(i + 1, end-i-1);
			for (auto &a:newStr)
				s.push_back(a);//pushing back current word
			if (i!=0)
				s.push_back(' ');//pushing  back space
			//If space in first position
			if (str[0] == ' ' && i == 0){
				s.push_back(' ');//pushing  back space
			}
			end = i;//moving end index
		}
	}	
	return s;
}

void main(){
	/* Test cases:
	1_ Empty String
	2_ One char in string
	3_ One word in string
	4_ random strings
	*/
	cout << rev_string("") << endl;
	cout << rev_string("h") << endl;
	cout << rev_string("hello ") << endl;
	cout << rev_string("Let's see how this goes?") << endl;
	cout << rev_string("A man walks alone") << endl;
	
}