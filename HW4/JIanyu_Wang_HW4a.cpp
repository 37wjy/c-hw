#include <iostream>
#include <cmath>

#ifndef std
	using namespace std;
#endif // !std


class Vec3d{
	double x,y,z;
public:
	Vec3d(double _x=0,double _y=0,double _z=0){x=_x;y=_y;z=_z;};

	Vec3d operator+(const Vec3d& rhs) const{
		Vec3d num(this->x+rhs.x,this->y+rhs.y,this->z+rhs.z);
		return num;
	};

	double dot(const Vec3d& rhs ) const{
		double num=x*rhs.x+y*rhs.y+z*rhs.z;
		return num;
	};

	double mag() const{
		double num=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
		return num;
	};

	double magSq() const{
		double num=pow(x,2)+pow(y,2)+pow(z,2);
		return num;
	};

	double dist(const Vec3d& rhs) const{
		double num=sqrt(pow(rhs.x-x,2)+pow(rhs.y-y,2)+pow(rhs.z-z,2));
		return num;
	};

	Vec3d operator-(const Vec3d& rhs) const{   //lhs
		Vec3d num(x-rhs.x,y-rhs.y,z-rhs.z);
		return num;
	};

	Vec3d operator-() const{
		Vec3d num(-x,-y,-z);
		return num;
	}

	friend ostream & operator << (ostream& output,const Vec3d& rhs){
		output<<"("<<rhs.x<<","<<rhs.y<<","<<rhs.z<<")";
		return output;
	}
};

double dot(const Vec3d& lhs, const Vec3d& rhs ){
		Vec3d v=lhs;
		double num=v.dot(rhs);
		return num;
}


int main() {
	// Main() Section 1
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d d;              //(0,0,0)

	// Main() Section 2
	const Vec3d e = a + d;
	const Vec3d f = c - b;
	const Vec3d g = -e;
	
	// Main() Section 3	
	double r = dot(e, f); // regular function  e.x*f.x + e.y*f.y + e.z*f.z
	double s = e.dot(f); // method

	// Main() Section 4	
	double x = e.mag(); // square root of sum of square
	double y = e.magSq(); // sum of square
	double z = e.dist(f); // sqrt or sum of square of diff

	// Main() Section 5	
	cout << "a: " << a << '\n';
	cout << "b: " << b << '\n';
	cout << "c: " << c << '\n';
	cout << "d: " << d << '\n';
	cout << "e: " << e << '\n';
	cout << "f: " << f << '\n';
	cout << "g: " << g << '\n';
	cout << "r: " << r << '\n';
	cout << "s: " << s << '\n';
	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
	cout << "z: " << z << '\n';

	return 0;
}	

