#include <iostream>

using namespace std;

class A{
public:
	A(){cout<<'a';};
    virtual void d(){};//可不重写
    virtual void f()=0;//必须重写
};

class C:A
{
private:
	/* data */
public:
	C(/* args */) {cout<<'c';}
    void d(){cout<<'d';}
    void f(){}
	~C() {}
};


class B:public A{
	private:
	C c;
	public:
	B(){cout<<"b";}
    void f(){};
};


int main(int argc, char const *argv[])
{
	B x;
	return 0;
}
