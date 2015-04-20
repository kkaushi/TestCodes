#include <iostream>
#include<vector>
#include<string>
using namespace std;

void print_vector(vector<char> v)
{
    for(auto &a: v)
        cout<<a<<",";
     cout<<endl;  
}

int main()
{

    string s {"hello"};
    vector<char> vec;

    //converting string to a vector
    vector<char> v{s.begin(), s.end()};
    print_vector(v);     
    
     //converting string to vector 2
     for(char c: s) 
         vec.push_back(c);
     print_vector(vec);
   
   return 0;
}