#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<char, vector<char>> m {
		{'2', {'a','b','c'}},
		{'3', { 'd', 'e', 'f'}}
};

vector<char> get_letters(char c){
	return m[c];
}

vector<string> getAllNames(vector<char> phone_no,int indx,vector<string>retNames){
	vector<string> allNames{ "" }, newNames;
	if (phone_no.empty())
		return allNames;
	if (indx + 1 > phone_no.size())
		return retNames;
	vector<char> letters = get_letters(phone_no[indx]);
	for (auto &a : retNames)
		for (auto &b : letters)
			newNames.push_back(a + b);
	return getAllNames(phone_no, indx + 1, newNames);

}

int main(){
	vector<char> phone_no{ '2', '3' };
	vector<string>allNames{ "" };
	allNames= getAllNames(phone_no, 0, allNames);
	for (auto &a : allNames)
		cout << a << '\n';
	return 0;
}