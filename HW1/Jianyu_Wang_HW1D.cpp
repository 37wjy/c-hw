#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    float sum1F=0.000,sum2F=0.000;
    double sum1D=0.000,sum2D=0.000;

    for(int16_t i=1;i<=100;i++){
        sum1F+=(float)1/i;
        sum1D+=(double)1/i;
        //cout<<"f "<<sum1F<<endl<<"d "<<sum1D<<endl;
        sum2F+=(float)1/(101-i);
        sum2D+=(double)1/(101-i);
    }
    
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<"sum1F = "<<sum1F<<", sum2F = "<<sum2F<<endl
                                                  <<"sum1D = "<<sum1D<<", sum2D = "<<sum2D<<endl
                                                  <<"sum1F - sum2F = "<<sum1F-sum2F<<endl
                                                  <<"sum1D - sum2D = "<<sum1D-sum2D<<endl;
    return 0;
}
