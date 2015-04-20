//Ques - find if an array has pairs with sum 12
#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> v {1,3,4,5,6,43,431,23,8,12,0};

int main(){
    map<int,int> m;
    for(auto &a: v)
        if(m.find(12-a)!=m.end())
            cout<<"pair:"<<a<<","<<12-a<<endl;
        else 
            m.insert({a,12-a});
    return 0;
}