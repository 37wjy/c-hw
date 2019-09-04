/*
	Make the following main work by writing a class Complex.
	Replace this comment with your author information and cite as necessary.

	Notice that since objects are const, you will have to promise not to change them
 */
#include <iostream>

class Complex
{
private:
    /* data */
    double real;
    double imaginary;
public:
    Complex(double real=0.00,double imaginary=0.00);
    void print() const{
        std::cout<<"("<<this->real<<","<<this->imaginary<<")"<<std::endl;
    };

    double getReal() const{
        return real;
    }

    double getIm() const{
        return imaginary;
    }

    Complex& operator +=(const Complex& rhs){
        Complex *num=new Complex(rhs.real+this->real,rhs.imaginary+this->imaginary);
        return *num;
    }

    Complex& add(const Complex& num) const{
        Complex rnum=num;
        rnum+=*this;
        return rnum;
    };

    const Complex& operator = (const Complex& right){
        if(this!=&right){
            Complex* num=new Complex(right.real,right.imaginary);
            return *num;
        }
        return *this;
    }

    const Complex& operator +(const Complex& rhs){
        return rhs;
    }

    friend Complex& operator -(const Complex& rhs){
        Complex num(-rhs.getReal(),-rhs.getIm());
        return num;
    }

    

    friend Complex& operator + (const Complex& lhs,const Complex& rhs){
        Complex num=lhs;
        num+=rhs;
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
}
