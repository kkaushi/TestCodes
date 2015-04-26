/*
Given a string containing letter, digit, and other characters, write a function to check palindrome for only letter and digit. The implementation need to be in-place, no extra memory is allowed to create another string or array. For example: 

"ABA" is palindrome 
"A!#A" is palindrome 
"A man, a plan, a canal, Panama!" is palindrome

*/

#include<iostream>
#include<string>
using namespace std;

bool inRange(int i){
    return ((i>=97 && i<=(97+25)) || (i>=65 && i<=(65+25))||(i>=48 && i<=(48+9)));
}

bool isPalin(string str){
    //if(str==nullptr) //NOTE THIS ERROR
	if (str.size()==0)
        return true;
    
    auto i = str.begin();
    auto j=str.end()-1;
    
    while(i<j){
		//ERRORS TO NOTE HERE
		//i,j are iterators NOT INDEXES
		//THAT'S WHY THE CODE BELOW CRASHES
		/*
        if(inRange(str[*i])){
            if(inRange(str[*j])){
                if(str[*i]!=str[*j]){
		*/
		if (inRange(*i)){
			if (inRange(*j)){
				if (*i++!=*j--){
                    return false;
                }
            }
            else{
                j--;
            }
        }
        else{
            i++;
        }
    }
    
    if(i>=j){
        return true;
    }
}

int main(){

    //test cases
    string str {""};
    string str2 {"aba"};
    string str3 {"a123,4,5,6,5,4,**3__21a"};
	string str4{ "a123,4,5,6,7,5,4,**3__21a" };
    cout<<"Is Palin:"<<isPalin(str4)<<endl;
    return 0;
}