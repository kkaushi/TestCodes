// class complex with all construct/destruct
// debug and see each getting called when their repective criteria of calling is matched
#include<iostream>

template<typename T>
class complex{
private:
	T real, imag;
public:
	//constructors
	//default
	complex(){}
	//parameterized
	explicit complex(T val1, T val2) :real{ val1 }, imag{ val2 }{}
	//copy 
	complex(complex& ob) :real{ ob.real }, imag{ ob.imag }{}
	//move 
	complex(complex&& ob) :real{ ob.real }, imag{ ob.imag }{}

	//assignment
	//copy
	complex& operator=(complex& ob){
		real = ob.real;
		imag = ob.imag;
		return *this;
	}

	//move
	complex&  operator=(complex && ob){
		real = ob.real;
		imag = ob.imag;
		return *this;
	}
	
	//destructor
	~complex(){}
};

//normal function
template<typename X>
complex<X> & return_complex(complex<X> &ob){
	return ob;
}

void main()
{
	//calling parameterized constructor
	complex<int> c(1, 2);

	//calling copy constructor
	complex<int> d = c;

	//calling copy assignment
	c = d;

	//calling move assignment
	complex<int> e(4,5);
	c = std::move(e);
	
}