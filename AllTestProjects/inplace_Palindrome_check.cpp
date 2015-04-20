#include<iostream>
#include<set>
#include<string>
using namespace std;

string alphabets {"abcdefghijklmnopqrstuvwxyz"};

void inplace_Palindrome_check(string str){
    for(auto a=str.begin(),b=str.end()-1;a<=str.end(),b>=str.begin();a++,b--){
        if(*a!=*b)
            //cout<<"a,b:"<<*a<<*b<<";";
            cout<<"Not a palindrome!\n";            
            return;
    }
    cout<<"Palindrome!\n";
}

int main(){
    set<char> s;
    string str {"Nitin"};
    inplace_Palindrome_check(str);
    return 0;
 }