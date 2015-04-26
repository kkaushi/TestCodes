#include<iostream>
#include<string>
using namespace std;

string remove_comma(string str){
	int i = 0;
	for (auto &a : str){
		if (a != ',' && str[i] == ','){
			str[i] = a;
			a = ',';
		}
		if (str[i] != ',')
			i++;		
	}
	for (int j = i; j < str.size();j++)
		str[j] = 0;
	return str;
}

int main(){
	//string str{ "a,b,,c," };
	//string str{ "a" };
	//string str{ "," };
	//string str{ ",,ab,," };
	string str{};
	cout << remove_comma(str) << endl;
}