#include <iostream>
#include <cmath>

using namespace std;

class Vec3d{
	double x,y,z;
public:
	Vec3d(double _x=0,double _y=0,double _z=0){x=_x;y=_y;z=_z;};

	friend Vec3d operator+(const Vec3d& rhs,const Vec3d& lhs) {
		Vec3d num(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z);
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
		Vec3d num(rhs.x-x,rhs.y-y,rhs.z-z);
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


int main(int argc, char const *argv[])
{
    const Vec3d a(1.0,2.5,3.2);
    const Vec3d b(2.0,-1.5,0.5);

    Vec3d g;
    Vec3d h();//¿¿¿¿¿¿¿¿¿function¿¿¿¿¿¿¿¿¿¿


    double d=a.dot(b);
    Vec3d c=a+b;
    Vec3d f=a-b;
    Vec3d e=-a;
    std::cout << e << std::endl;
    return 0;
}
