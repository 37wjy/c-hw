/*
	Make the following main work by writing a class Complex.
	Replace this comment with your author information and cite as necessary.

	Notice that since objects are const, you will have to promise not to change them
 */
#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;
public:

    Complex(void):real(0),imaginary(0){};
    Complex(double r=0.0,double i=0.0):real(r),imaginary(i){};
    //~Complex(){delete(this);}
    
    void print() const{
        cout<<"("<<this->real<<","<<this->imaginary<<")"<<endl;
    };

    Complex add(const Complex& num) const{   //only read
        return num+*this;                    //no error
    };

    friend Complex operator+(const Complex& lhs, const Complex& rhs){
        Complex num(lhs.real+rhs.real,lhs.imaginary+rhs.imaginary);
        return num;
    };

    Complex operator- () const{
        Complex num(-real,-imaginary);
        return num;
    };

};

int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using a friend function
	c.print(); // should print the following to cout: (1.5,2.0)
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
	e.print();
    return 0;
}





