#include<iostream>
//#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
	vector<int> v{ 1, 2, 3, 4, 5, 6, 8 };
	fstream fs;
	string filename = "kk_2.txt";
	
	//WRITE VECTOR
	fs.open(filename, fstream::out|fstream::binary);
	copy(v.begin(), v.end(), ostreambuf_iterator<char>(fs));
	fs.close();

	//READ VECTOR
	vector<int> new_vec;
	fs.open(filename, fstream::in | fstream::binary);
	//istreambuf_iterator<char>  b (fs),e;
	copy(istreambuf_iterator<char>(fs), istreambuf_iterator<char>(), back_inserter(new_vec));
	
	fs.close();

	for (auto &x : new_vec)
		cout << x << " ";
	cout << endl;
}