//exception,out of range, vector
#include<iostream>
#include<vector>

void main(){
	try{
		std::vector<int> v= {1, 2, 3, 4};
		std::cout << v.size() << "\n";
		v.at(v.size()) = 5;//will throw exception out_of_range
		v[v.size()] = 5;//will not throw exception
	}

	catch (std::out_of_range& oor){
		std::cerr << "out of range exception. Desription: "<<oor.what()<<"\n";
	}

	catch (...){
		std::cerr << "unknown exception...\n";
	}
}