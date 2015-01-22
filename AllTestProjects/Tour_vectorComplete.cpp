#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

template<typename T>
void iterate_vector(vector<T> &v){
	if (v.size() == 0){
		cout << "Vector is empty!";
		return;
	}		
	for (auto &a : v){
		cout << a << "\t";
	}
	cout << "\n";
}
void main(){
	//int vector
	vector<int> v;
	v.push_back(33);
	v.push_back(4);
	v.push_back(3);
	v.push_back(12);
	iterate_vector(v);

	//sort vector
	sort(v.begin(), v.end());
	iterate_vector(v);

	//char vector
	vector<char> cv;
	cv.insert(cv.begin(), 'd');
	cv.insert(cv.end(), 'b');
	iterate_vector(cv);
	
	sort(cv.begin(), cv.end());
	iterate_vector(cv);

	//copy vector<char>
	vector<char> cv2;
	copy(cv.begin(), cv.end(), back_inserter(cv2));
	cv2.push_back('t');
	cv2.push_back('f');	
	iterate_vector(cv2);

	//vector.capacity()
	//capacity gives the size of allocated memory 
	cout << "cv2.capacity(): " << cv2.capacity() << endl;

	//vector.at(pos)
	cout << "cv2.at(2): " << cv2.at(2) << endl;

	//vector.clear()
	//only clears the vector, size would be zero, capacity would be still 4
	cout << "Calling cv2.clear() and then iterate_vector(cv2):" << endl;
	cv2.clear();
	iterate_vector(cv2);
	cout << "cv2.capacity(): " << cv2.capacity() << endl;

	//data returns a pointer to 
	char * pcv = cv.data();
	cout << "value at pcv[0]:" << pcv[0] << endl;
	cout << "value at pcv[1]:" << pcv[1] << endl;
	
	
	//vector intiailize
	vector<int> iv(3, 100);
	iterate_vector(iv);

	//check out other list of vectors here: http://www.cplusplus.com/reference/vector/vector/insert/


	
}