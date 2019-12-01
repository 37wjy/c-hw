#include <iostream>
#include <math.h>


using namespace std;


int main(int argc, char const *argv[])
{
	cout<<"uint64_t mov[64]={"<<endl;
	for (uint64_t i = 0; i <= 63; i++)
	{
		cout<<"0x";
		cout<<hex<<~(((uint64_t)0x1)<<(i));
		if(i!=63)
		{cout<<" ,"<<endl;}
	}
	cout<<"};"<<endl;
	
	return 0;
}
