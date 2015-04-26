/*
Write a program that answers YES/NO search queries containing * placeholders. Example: if the data you have is (hazem, ahmed, moustafa, fizo), then you should answer as follows for: 

ahmed: YES 

m**stafa: YES 

fizoo: NO 

fizd: NO 

*****: YES 

****: YES
 
**: NO 

Your program should be able to answer each search query in O(1).
*/

#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<string,int> m;

vector<string> insert_string(string a,int indx){
    vector<string> ret_vec{""},new_vec;
       
    if(indx==a.size())
        return ret_vec;
        
    ret_vec=insert_string(a,indx+1);
    for(auto & b: ret_vec){
        new_vec.push_back(a[indx]+b);
        new_vec.push_back("*"+b);
    }
    return new_vec;    
}

void populate_data(vector<string> v){
    vector<string> vec;
    if(v.size()==0)
        return;
    
    for(auto &a:v){
		vector<string> temp=insert_string(a, 0);
		vec.insert(vec.end(),temp.begin(),temp.end());
    }
    
    for(auto &a: vec){
        m.insert(pair<string,int>(a,1));
    }
}

int main(){
    //vector<string> vec_string{"hazem", "ahmed", "moustafa", "fizo"};
	vector<string> vec_string{ "abc"};
    populate_data(vec_string);
    char c='y';
    string name;

	while(c=='y'||c=='Y'){
        cout<<"Enter the name:";
        cin>>name;
        if(m.find(name)!=m.end())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        cout<<"Do you want to continue?";
        cin>>c;
        //cout<<endl;
    }
    return 0;
}