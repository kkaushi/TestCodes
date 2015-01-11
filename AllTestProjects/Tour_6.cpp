//user defined type strem I/O, manipulators
#include<iostream>
#include<string>
using namespace std;

struct my_type{
	string name;
	int id;
};

ostream & operator<<(ostream & ob, const my_type & t){
	return ob << t.id << " " << t.name;
}

istream& operator>>(istream& is, my_type& e)
// read { "name" , number } pair. Note: formatted with { " " , and }
{
	char c, c2;
	if (is >> c && c == '{' && is >> c2 && c2 == '"') { // start with a { "
		string name; // the default value of a string is the empty string: ""
		while (is.get(c) && c != '"') // anything before a " is part of the name
			name += c;
		if (is >> c && c == ',') {
			int number = 0;
			if (is >> number >> c && c == '}') { // read the number and a }
				e.name = name;
				e.id = number;
				return is;
			}
		}
	}
	is.setstate(ios::failbit);// register the failure in the stream
	return is;
}

void main(){
	my_type a;
	a.name = "kuldeep";
	a.id = 383;
	//output directly user defined type
	my_type b;
	cout << a;
	cout << endl << "lets do cin now. Use format: {\"name\" ,number}" << endl;
	cin >> b;
	cout << b;
	cout << endl;

	//Manipulators here:
	cout<<hex << b.id<<"              s"<<oct<<b.id<<endl;
}