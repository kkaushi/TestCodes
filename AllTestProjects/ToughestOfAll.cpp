/*
If a=1, b=2, c=3,....z=26. Given a string, find all possible codes that string can generate. Give a count as well as print the strings.

For example:
Input: "1123". You need to general all valid alphabet codes from this string.

Output List
aabc //a = 1, a = 1, b = 2, c = 3
kbc // since k is 11, b = 2, c= 3
alc // a = 1, l = 12, c = 3
aaw // a= 1, a =1, w= 23
kw // k = 11, w = 23

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> addCharToList(vector<string>lst, char c){
	vector<string> new_vec;
	for (auto &a : lst)
		new_vec.push_back(a + c);//check this out: string+cha
	return new_vec;
}

vector<string> ret_strings(string s){
    vector<string> ret{""}, preRet{""};
    if(s.size()==0)
        return ret;
    
    for(int i=0;i<s.size();i++){
        vector<string>temp1, temp2;
        if(i>=1){
			int val = stoi(s.substr(i - 1, 2), nullptr, 10);
            if(val>=10 && val<=26){
                char c = 96+val;
                temp1=addCharToList(preRet,c);
            }
        }
        int val = stoi(s.substr(i,1),nullptr,10);
        if(val!=0){
            char c = 96+val;
            temp2=addCharToList(ret,c);            
        }
        temp1.insert(temp1.end(),temp2.begin(),temp2.end());//CHECK THIS OUT, APPENDING TWO VECTORS
        preRet=ret;
        ret=temp1;
    }
    return ret;
}

int main(){
    string str {"111"};
    vector<string> v=ret_strings(str);
    for(auto &a: v)
        cout<<a<<endl;
    return 0;
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        