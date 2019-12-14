#include <iostream>
#include <math.h>

using namespace std;

class PrimeSolver {
private:
	typedef uint64_t O0Oo0o0O;typedef uint8_t O0oO0Oo0;
	#define o0O0o0O0 delete[] 
	#define O0o00O0 for 
	O0Oo0o0O oOoOoo[64]={
	0xfffffffffffffffe ,
	0xfffffffffffffffd ,	0xfffffffffffffffb ,
	0xfffffffffffffff7 ,	0xffffffffffffffef ,	0xffffffffffffffdf ,
	0xffffffffffffffbf ,	0xffffffffffffff7f ,	0xfffffffffffffeff ,	0xfffffffffffffdff ,
	0xfffffffffffffbff ,	0xfffffffffffff7ff ,	0xffffffffffffefff ,	0xffffffffffffdfff ,	0xffffffffffffbfff ,
	0xffffffffffff7fff ,	0xfffffffffffeffff ,	0xfffffffffffdffff ,	0xfffffffffffbffff ,	0xfffffffffff7ffff ,	0xffffffffffefffff ,
	0xffffffffffdfffff ,
	0xffffffffffbfffff ,	0xffffffffff7fffff ,
	0xfffffffffeffffff ,	0xfffffffffdffffff ,	0xfffffffffbffffff ,
	0xfffffffff7ffffff ,	0xffffffffefffffff ,	0xffffffffdfffffff ,	0xffffffffbfffffff ,
	0xffffffff7fffffff ,	0xfffffffeffffffff ,	0xfffffffdffffffff ,	0xfffffffbffffffff ,	0xfffffff7ffffffff ,
	0xffffffefffffffff ,	0xffffffdfffffffff ,	0xffffffbfffffffff ,	0xffffff7fffffffff ,	0xfffffeffffffffff ,	0xfffffdffffffffff ,
	0xfffffbffffffffff ,
	0xfffff7ffffffffff ,	0xffffefffffffffff ,	
	0xffffdfffffffffff ,	0xffffbfffffffffff ,	0xffff7fffffffffff ,
	0xfffeffffffffffff ,	0xfffdffffffffffff ,	0xfffbffffffffffff ,	0xfff7ffffffffffff ,
	0xffefffffffffffff ,	0xffdfffffffffffff ,	0xffbfffffffffffff ,	0xff7fffffffffffff ,	0xfeffffffffffffff ,
	0xfdffffffffffffff ,	0xfbffffffffffffff ,	0xf7ffffffffffffff ,	0xefffffffffffffff ,	0xdfffffffffffffff ,	0xbfffffffffffffff ,
	0x7fffffffffffffff};
	#define O0o0OO0 if 
	#define O0o00o0 new
	O0oO0Oo0 o0O0o0oO=2;O0Oo0o0O O0Oo0oo0;
	//copy constructor, operator = not required
public:
	PrimeSolver(O0Oo0o0O o0oOo00o){O0Oo0o0O* O0o0O0o0=O0o00o0 O0Oo0o0O[(o0oOo00o+63)/64];
	O0o00O0(O0Oo0o0O oo0O0o0o = 0;oo0O0o0o<(o0oOo00o+63)/64;oo0O0o0o++){O0o0O0o0[oo0O0o0o]
	=0xAAAAAAAAAAAAAAAA;}O0o0O0o0[0]=0xAAAAAAAAAAAAAAAB;O0o00O0 (O0Oo0o0O oo0O0o0o=o0O0o0oO
	+1;oo0O0o0o<=sqrt(o0oOo00o)+1;oo0O0o0o++){O0o00O0 (O0Oo0o0O o0o0OO00=oo0O0o0o*oo0O0o0o;
	o0o0OO00<o0oOo00o;o0o0OO00+=oo0O0o0o){O0o0O0o0[(o0o0OO00-o0O0o0oO)/64]&=~(((O0Oo0o0O)0x1
	)<<((o0o0OO00-o0O0o0oO)%64));}}O0Oo0o0O O0o0ooO0=0;O0o00O0(O0Oo0o0O oo0O0o0o=0;oo0O0o0o<=
	o0oOo00o-o0O0o0oO;oo0O0o0o++){O0o0OO0((O0o0O0o0[(oo0O0o0o)/64]&(((O0Oo0o0O)0x1)<<((oo0O0o0o)
	%64)))){O0o0ooO0++;}}O0Oo0oo0=O0o0ooO0;o0O0o0O0 O0o0O0o0;}PrimeSolver(const PrimeSolver& 
	o0oOo00o){o0O0o0oO=o0oOo00o.o0O0o0oO;O0Oo0oo0=o0oOo00o.O0Oo0oo0;}O0Oo0o0O countPrimes(){return 
	O0Oo0oo0;}PrimeSolver operator= (const PrimeSolver& o0oOo00o)const{return PrimeSolver(o0oOo00o);}
};



int main() {
  PrimeSolver p(100); // allocate the right number of 64-bit words   50847534
#if 0
	//You do not have to support copy constructor, but you should at least delete it
	PrimeSolver p2 = p; // this would give an error
	// same for operator =
	p2 = p; // just delete both copy constructor and operator = to show that you know how
#endif
	cout << p.countPrimes();
}