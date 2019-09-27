#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int inp=1000001;
    double r=1;
    //cin>>inp;
    for(int n=3;n<inp;n++){
        r=(r/cos(M_PI/n));
        if(n==10||n==100||n==1000||n==10000||n==100000||n==1000000)
            cout<<"n = "<<left<<setw(10)<<n<<"Radius = "<<r<<endl;
    }
    return 0;
}
