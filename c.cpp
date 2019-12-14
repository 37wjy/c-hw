#include <iostream>

using namespace std;

class A{
public:
	A(){cout<<"a";}
};

class C
{
private:
	/* data */
public:
	C(/* args */) {cout<<'c';}
	~C() {}
};

class B:public A{
	private:
	C c;
	public:
	B():A(){cout<<"b";}
};


int main(int argc, char const *argv[])
{
	B x;
	return 0;
}
