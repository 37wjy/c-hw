#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a[3]={1,2,3};
    const int *p=a+2;
    *--p+=22;
    cout<<*p;
    for (int i = 0; i < 3; i++)
    {
        cout<<a[i]<<endl;
        /* code */
    }
    
    return 0;
}
