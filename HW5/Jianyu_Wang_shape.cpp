#include <iostream>
#include <cmath>
using namespace std;

class Rect{
private:
    int _x,_y;
    int _w,_h;
    int _a;

public:
    Rect(int x,int y,int w,int h){_x=x;_y=y;_w=w;_h=h;_a=w*h;}
    int area(){return _a;}
};

class Circle{
private:
    int _x,_y;
    double _r;
    double _a;

public:
    Circle(int x,int y,double r){_x=x;_y=y;_r=r;_a=pow(r,2)*M_PI;}
    double area(){return _a;}
};

class Line{
private:
    int _x,_y,_x1,_y1;
public:
    Line(int x,int y,int w,int h){_x=x;_y=y;_x1=w;_y1=h;}
    int area(){return 0;}
};

int main() {
	Rect r1(100, 50, 20, 40);	// Rect(x,y, width, height)
	cout << r1.area() << '\n';
    Circle c1(400, 300, 50); // Circle(x,y,radius)
    cout << c1.area() << '\n'; // area should be pi * radius squared
    Line L1(0,0, 300, 400);
    cout << L1.area() << '\n'; // area should be 0
}



	
