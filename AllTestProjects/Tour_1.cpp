//Creating simple vector class, exception handling(try, catch, out_of_range, ), auto , static_assert, std::abort()
#include<iostream>
using namespace std;

//Vector class
class Vector{
private:
	int sz;
	double * elem;
public:
	Vector(int i) :sz{ i }, elem{ new double[i]}{
	}

	double & operator[](int i){ 
		if (i < 0 || i >= sz){
			throw out_of_range{ "Index out of range" };
		}
		return elem[i];
	}

	int size(){ 
		return sz; 
	}
	
	void printall(){
		if (sz == 0){
			cout << "Vector is empty";
			return;
		}
		cout << "Vector is:\n";
		for (auto a = 0; a < sz; a++){
			cout << elem[a] << "\t";
		}
		cout << "\n";
	}	
};

Vector & create_vector(){
	cout << "Enter # of elements\n";
	int n;
	cin >> n;
	Vector v(n);
	for (auto a = 0; a < v.size(); a++){
		cin >> v[a];
	}
	v.printall();
	return v;
}
void main()
{
	static_assert(1 > 0, "This is surely false");
	Vector v = create_vector();
	try{
		cout << "Accessing nth element:\n" << v[v.size() ] << "\n";
	}
	catch (out_of_range){
		cout << "Caught out_of_range exception. Aborting!\n";
		//std::abort();
	}
	

}