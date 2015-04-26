/*
Input: A string equation that contains numbers, '+' and '*' 
Output: Result as int. 

For example: 
Input: 3*5+8 (as String) 
Output: 23 (as int)

*/

#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;


vector<string> tokenizer(string str, char token){
    vector<string> new_vec;
    int indx=0;
    for(int i=0;i<str.size();i++){
        if(str[i]==token){
            new_vec.push_back(str.substr(indx,i-indx));
            indx=min(i+1,str.size());
        }
    }
    if(indx<str.size()-1)
        new_vec.push_back(str.substr(indx,str.size()-1-indx);
    return new_vec;
}
    
int ret_val(string str){
    if(str.size()==0)
        return 0;
    vector<string>product_list,final_list;
    vector<string> Add_list=tokenizer(str,'+');
    for(auto &a: Add_list){
        product_list=tokenizer(str,'*');
        if(product_list.size()==0)
            final_list.push_back(a);
        else{
            int product =1 ;
            for(auto &c : product_list)
                product*=stoi(c,10);
                final_list.push_back(to_string(product));
        }
    }
    
    int sum=0;
    for(auto &d: final_list)
        sum+=stoi(d,10);
    return sum;
}


int main(){
     
    cout<<val    
    return 0;
}