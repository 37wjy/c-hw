#include <iostream>

using namespace std;

class A{
public:
	A(){cout<<"a";}
};

class B:A{
	public:
	B():A(){cout<<"b";}
};


int main(int argc, char const *argv[])
{
	B x;
	return 0;
}
