// simple regex, getline()
#include<iostream>
#include<regex>

void main(){
	std::smatch matches;
	std::regex pat(R"(\w{2}\s{1}?)");
	std::string line{"hel"};
	//loop will break on hello
	//2 letters + 1 space would be matched
	while (std::getline(std::cin, line) && line != "hello"){
		if (regex_search(line, matches, pat)){
			std::cout << "Matched: "<<matches[0] << "\n";
		}
	}
}