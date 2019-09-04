#if !defined(iostream)
#include<iostream>

#endif // iostream


class Complex
{
private:
    /* data */
    double real;
    double imaginary;
public:
    Complex(double real=0.00,double imaginary=0.00);
    void print(){
        std::cout<<"("<<this->real<<","<<this->imaginary<<")"<<std::endl;
    }

    Complex add(Complex num){
        num.real=num.real+this->real;
        num.imaginary=num.imaginary+this->imaginary;
        return num;
    }

    Complex& operator=(const Complex& right){
        if(this!=&right){
            Complex* num=new Complex(right.real,right.imaginary);
            return *num;
        }
        return *this;
    }
};





