/*
You are given a set of unique characters and a string. 

Find the smallest substring of the string containing all the characters in the set. 

ex: 
Set : [a, b, c] 
String : "abbcbcba" 

Result: "cba"
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

string ret_min_substring(string str, set<char> s_given){
	int l = 0, r = 0;//init indexes
	int l_min = 0, r_min = str.size() - 1;//init with whole string
    map<char,int>m;
    set<char>s;
    
	//if set empty, return empty string
	if (s_given.size() == 0)
		return (string{ "" });

	//if emptry string, return it
	if (str.size() == 0)
		return str;

	//do till r<str.size()
	while (r < str.size()){
		//if element is not present in the given set, do nothing
		if (s_given.find(str[r]) == s_given.end()){
			r++;
			if (s_given.find(str[l]) == s_given.end())
				l++;
			continue;
		}

		//if element present in set
		if (m.find(str[r]) == m.end()){//found first time
			m.insert(pair<char, int>(str[r], 1));//insert to map with count 1
			s.insert(str[r]);//inset to new set
		}
		else{//if found more than one times
			int val = m[str[r]];//get its count
			val++;//increase count
			//remove map entry
			m.erase(str[r]);//erase by key
			//or
			//m.erase(m.find(str[r]));//erase by it
			m.insert(pair<char, int>(str[r], val));//insert in map again with increased count value
		}
		
		//if all elements found, increment l value to shrink head pointer
		if (s.size() == s_given.size()){
            while(m[str[l]]>1 && l<=r){
                int val=m[str[l]];
                m.erase(str[l]);
                m.insert(pair<char,int>(str[l],val-1));                    
                l++;
            }
			//get indexes as set is complete [we have a string with all chars in given set]
			if (r - l < r_min - l_min){//only if new min is found
				l_min = l;
				r_min = r;
			}
			if (r_min - l_min + 1 == s_given.size())//if exact size equal to size of set, return because it is the minimum size
				return str.substr(l_min, r_min - l_min + 1);
        }		
		//increment r for main while loop
		r++;
	}//end of while
    
	//init return string
	return str.substr(l_min, r_min - l_min + 1);
}

int main(){
	string str = ret_min_substring("aabbc", set < char > {});
	cout << "min string is:" << str << endl;
	return 0;
}