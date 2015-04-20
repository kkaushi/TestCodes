#include<iostream>
#include<set>
#include<string>
using namespace std;

string alphabets {"abcdefghijklmnopqrstuvwxyz"};

int main(){
    set<char> s;
    string str {"The quick brown fox jumps over the little lazy dog"};
    for(auto &a: str)
        s.insert(a);
    
    
    //check if all alphabets are in string
    for(auto &b: alphabets)
        if(s.count(b)!=0)
            cout<<b<<" is present \n";
            
    return 0;
 }