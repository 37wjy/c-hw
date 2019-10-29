#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

/*
	suggestion:
for this assignment:*/

class Shape {
public:
  virtual void draw(ostream& s) = 0;
};

class Rect: public Shape{
    double _x; double _y; double _w; double _h;
public:
    Rect(double x, double y, double w, double h):_x(x),_y(y),_w(w),_h(h){}

    void draw(ostream& s){
        s<<_x<<" "<<_y<<" "<< "moveto"<<endl
        <<_x+_w<<" "<<_y<<" "<<"lineto"<<endl
        <<_x+_w<<" "<<_y+_h<<" "<<"lineto"<<endl
        <<_x<<" "<<_y+_h<<" "<<"lineto"<<endl
        <<"closepath stroke"<<endl;
    }
};

class FilledRect: public Shape{
    double _x; double _y; double _w; double _h;
public:
    FilledRect(double x, double y, double w, double h):_x(x),_y(y),_w(w),_h(h){}
    void draw(ostream& s){
        s<<_x<<" "<<_y<<" "<< "moveto"<<endl
        <<_x+_w<<" "<<_y<<" "<<"lineto"<<endl
        <<_x+_w<<" "<<_y+_h<<" "<<"lineto"<<endl
        <<_x<<" "<<_y+_h<<" "<<"lineto"<<endl
        <<"closepath fill"<<endl;
    }
};

class Circle: public Shape{
    double _x;double _y;double _r;
public:
    Circle(double x,double y,double r):_x(x),_y(y),_r(r){};

    void draw(ostream& s){
        s<<_x<<" "<<_y<<" "<<_r<<" 0 360 arc stroke"<<endl;
    }
}; 

class FilledCircle:public Shape{
    double _x;double _y;double _r;
public:
    FilledCircle(double x,double y,double r):_x(x),_y(y),_r(r){};
    void draw(ostream& s){
        s<<_x<<" "<<_y<<" "<<_r<<" 0 360 arc fill"<<endl;
    }
};

class Polygon2 : public Shape {
    double _x;double _y;double _r;int _n;
public:
    Polygon2(double x,double y,double r,int n) {_x=x;_y=y;_r=r;_n=n;}

    void draw(ostream& s){
        float x=_x,y=_y;
        for(int i=0;i<_n;i++){
            s<<x<<" "<<y<<" "<< (i?"lineto":"moveto")<<endl;
            x+=_r*cos(M_PI*2/_n*i);
            y+=_r*sin(M_PI*2/_n*i);
        }
        s<<"closepath stroke"<<endl;
    }
};

class Polygon: public Shape {
    double _x;double _y;double _r;int _n;double _a;
public:
    Polygon(double x,double y,double r,int n,double a=0) {_x=x;_y=y;_r=r;_n=n;_a=(a/180.0)*M_PI;}

    void draw(ostream& s){
        float x,y;
        for(int i=0;i<_n;i++){
            x=_x+_r*cos(M_PI*2/_n*i+_a);
            y=_y+_r*sin(M_PI*2/_n*i+_a);
            s<<x<<" "<<y<<" "<< (i?"lineto":"moveto")<<endl;
        }
        s<<"closepath stroke"<<endl;
    }
};

class Line : public Shape{
    double _x1;double _y1;double _x2;double _y2;
public:
    Line(double x1,double y1,double x2,double y2){_x1=x1;_y1=y1;_x2=x2;_y2=y2;}

    void draw(ostream& s){
        s<<_x1<<" "<<_y1<<" moveto "<<_x2<<" "<<_y2<<" lineto stroke"<<endl;
    }
};

class Color:public Shape{
    double _r ,_g ,_b;
public:
    Color(double r,double g,double b):_r(r),_g(g),_b(b){};

    void draw(ostream& s){
        s<<_r<<" "<<_g<<" "<<_b<<" setrgbcolor"<<endl;
    }
};

class Drawing {
private:
	ofstream f;
	vector<Shape*> shapes;
public:
	Drawing(string filename) :  shapes() {f.open(filename.c_str(), ios_base::app);}
    ~Drawing(){f.close();}
	void add( Shape* s ) {
    shapes.push_back(s);
	}

	void draw() {
        int numShapes=shapes.size();
        f<<endl;
		for (int i = 0; i < numShapes; i++)
			shapes[i]->draw(f);
	}

    void setrgb(double r,double g,double b){
        shapes.push_back(new Color(r,g,b));
    }

};

int main() {
	//ofstream f();
	Drawing d("test2.ps");
	d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
	d.add(new FilledRect(100.0, 150.0, 200.0, 50)); // x y moveto x y lineto ... fill
	d.add(new Rect(100.0, 150.0, 200.0, 50));       // x y moveto x y lineto ... stroke
	for (int x = 0; x < 600; x += 100)
		d.add(new FilledCircle(x,200,50.0)); // x y r 0 360 arc fill
	d.setrgb(0,1,0); // the rest are green

	d.add(new Circle(0,0, 100)); // 0 0 100 0 360 stroke
	d.add(new Line(400,500, 600,550));
	d.add(new Polygon(200,200, 50, 6));
	d.draw();
}
