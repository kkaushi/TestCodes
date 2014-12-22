#include<iostream>
using namespace std;

class Vec
{
	int x;
	int y;
   public:
	Vec(){}
	Vec(int i,int j):x(i),y(j){}
	Vec operator+(const Vec& b)
	{
		Vec temp;
		temp.x=x+b.x;
		temp.y=y+b.y;
		return temp;
	}
	void getxy()
	{
		cout<<x<<":"<<y<<endl;
	}
};

int main()
{
	Vec v(2,3),w(5,1);
	Vec s=v+w;
	s.getxy();
	return 0;
}
