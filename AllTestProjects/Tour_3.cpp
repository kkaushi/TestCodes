//same as Tour_2.cpp with static class member (inside template)
//check out it's intiailization outside of the class
#include<iostream>

template<typename T>
class complex{
private:
	T real, imag;
	static int n;
public:
	//constructors
	//default
	complex(){}
	//parameterized
	explicit complex(T val1, T val2) :real{ val1 }, imag{ val2 }{}
	//copy 
	complex(complex& ob) :real{ ob.real }, imag{ ob.imag }{ n++; }
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

	//get n
	int getn(){ return n; }

	//destructor
	~complex(){}
};

template <typename X>
int complex<X>::n = 0;

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
	complex<int> e(4, 5);
	c = std::move(e); 
	c = return_complex(e);
	
	std::cout << d.getn()<<"\t"<<c.getn() << "\n";
}