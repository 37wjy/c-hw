#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a[2]={1,2};
    int *p=a+1;
    //cin>>*p;
    *--p+=22;
    cout<<*p<<endl;
    for (int i = 0; i < 2; i++)
    {
        cout<<a[i]<<endl;
        /* code */
    }
    cout<<(int)2.5/3.5;
    
    return 0;
}
