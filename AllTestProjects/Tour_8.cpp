//vector, range_for 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Entry{
	string name;
	int id;
};

void main(){
	vector<Entry>data = {{ "kuldeep", 123 }, { "abc", 333 }};
	cout << "Data size is: " << data.size()<<endl<<"Adding one more element to our vector"<<endl;
	data.push_back({ "hello", 3 });
	cout << "lets traverse:\n";
	for (auto &a : data){
		cout << a.name << " " << a.id << "\n";
	}
	cout << "getting node at front using front() "<< data.front().name << " "<<data.front().id<<"\n";
	cout <<"This is name at location 1 using at(1)"<< data.at(1).name << endl;
	cout << "This is data at back using back() "<<data.back().name << endl;
	

	vector<Entry>newData;
	//assign(): http://msdn.microsoft.com/en-us/library/azbhc96f.aspx
	newData.assign(data.begin(), data.end());
	cout << "New data is: \n";
	for (auto &a : newData){
		cout << a.name << " " << a.id << "\n";
	}

	cout << "Data vector capacity using capacity(): " << data.capacity() << endl;
	cout << "Data vector max_size(): " << data.max_size() << endl;
}