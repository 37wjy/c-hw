#include <iostream>

using namespace std;

class A{
public:
	A(){cout<<'a';};
    virtual void d(){}//可不重写
};

class C:A
{
private:
	/* data */
public:
	C(/* args */) {cout<<'c';}
    void d(){cout<<'d';}
	~C() {}
};

class B:public A{
	private:
	C c;
	public:
	B(){cout<<"b";}
};


int main(int argc, char const *argv[])
{
	B x;
	return 0;
}
