//string library
#include<iostream>
#include<string>
using namespace std;


void main(){
	string str{ "Kuldeep Kaushik" };
	cout<< str<<endl;
	str += " hi there!";
	cout << str << endl;
	str.replace(0, 7, "rajat");
	cout << str << endl;
	str[0] = toupper(str[0]);
	cout << str << endl;

	cout << "Enter string(using cin):";
	cin >> str;
	cout << str << endl;
	cin.clear();
	

	string str2;
	cout << "Enter now (using get line now):";
	getline(cin, str2);
	cout << str2 << endl;
	
	/*
	cout << "Enter char(getchar): ";
	str2[0] = getchar();
	cout << str2 << endl;
	*/


	
}