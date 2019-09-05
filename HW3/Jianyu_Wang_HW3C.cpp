 //Complete hwBody, creating body objects that will later be used for the solar system simulator.
 
 #include <iostream>
 using namespace std;


 class Body {
    string name;
    double mass;
    double x,y,z;
    double radius;
public:
    Body(string _name,double _mass,double _X,double _Y,double _Z,double _radius){
        name=_name;
        mass=_mass;
        x=_X;
        y=_Y;
        z=_Z;
        radius=_radius;
    }

    friend ostream &operator <<(std::ostream &output, const Body& rhs ){
        output << "name : " << rhs.name << " mass : " << rhs.mass<< " position : ";
        return output;     
    }
};

int main() {
	//         name      mass(kg) x y z  radius (m)
	Body earth("earth", 5.972e24, 0,0,0, 6.371e6);
	Body moon("moon",   7.34767309e22, 384.400e6,0,0,  1.737e6);
	cout << earth << '\n';
	cout << moon << '\n';
    return 0;
}
	
