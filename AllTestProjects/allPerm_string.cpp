#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> all_perm(string str){
    vector<string> ret_str{""}, new_vec;
    
    //if(str==nullptr)
    if(str.size()==0)
        return ret_str;//recursion return case: return when reached end of string; return empty string
        
    ret_str=all_perm(str.subst(0,str.size()-1));
    for(auto & a: ret_str){
        for(int i=0;i<a.size();i++){
            new_vec.push_back(a.substr(0,i)+str[0]+a.substr(i+1,a.size()-i-1);
        }
    }
    return new_vec;
}