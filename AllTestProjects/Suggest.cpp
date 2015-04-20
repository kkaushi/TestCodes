#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<char, vector<char>> m{ { 'h', { 'g', 'h', 'j' } }, { 'i', { 'u', 'i', 'o' } }, { 't', {'t','y','r'} } };

vector<char> getAllLetters(char c){
	return m[c];
}

vector<string> getAllSuggestions(vector<char>letters, int indx){
	vector<string> allWords{""}, suggestWords;
	if (indx > letters.size()-1)
		return allWords;
	allWords = getAllSuggestions(letters, indx + 1);
	vector<char> nearLetters = getAllLetters(letters[indx]);
	for (auto &b : allWords)
		for (auto &a : nearLetters){
			suggestWords.push_back(a+b);
		}
		
	return suggestWords;
}

int main(){
	//Test case 1  - normal input
	//vector<char> letters{ 'h', 'i', 't'};
	
	//Test case - boundary condition
	vector<char> letters{ ' ' };
	vector<string> words = getAllSuggestions(letters, 0);
	for (auto &a : words)
		cout << a << "\n";
}