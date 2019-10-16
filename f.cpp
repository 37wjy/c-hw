#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int a=3;
    int b=4;
    int*r=&b;
    int*p=&a;
    int x[6]={9,2,7};
    p=x+2;
    cout<<*p<<endl;
    int q=*p++;//不会对p影响
    cout<<q<<endl;
    int*s=&q;
    *s=22;
    *p++=11;
    *--p+=3;
    int j=--*p;
    cout<<j<<endl;
    for (int i = 0; i < b; i++)
    {
        cout<<x[i]<<",";
    }
    
    return 0;
}
