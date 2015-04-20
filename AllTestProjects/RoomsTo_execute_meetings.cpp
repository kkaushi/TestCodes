//Ques - no of rooms required to execute meetings
#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct meeting{
	int start; 
	int end;
}one{ 1, 2 }, two{ 1, 4 }, three{ 3, 5 }, four{ 5, 7 }, five{ 2, 8 };

//imp this is an error. You can't have a statement in global scope
//one.start = 1, one.start = 2, two.start = 1, two.end = 4, three.start = 3, three.end = 5;

vector<meeting> v {one, two, three, four, five};

map<int,int> mp;

int nRooms(vector<meeting> v_meetings){
	int max = 0;//keeps count of max rooms
	for(auto &a: v_meetings)
        for(auto b=a.start;b<=a.end;b++)
            if(mp.find(b)!=mp.end()){//to check if key exists
                auto c = mp.find(b)->second;//second gives second element in pair
				mp.erase(mp.find(b));//remove the entry, otherwise inser will not work(as map doesnot allow duplicate keys)
				mp.insert({ b, c + 1 });
				max=(max < c + 1) ? (c + 1) : max;
				//OR mp.insert(std::pair<int,int>(b,c+1s));
			} else{
				 mp.insert({ b, 1 });
			}
	return max;
}


int main(){
	
	cout<<"No of rooms:"<<nRooms(v)<<endl;
	return 0;
}