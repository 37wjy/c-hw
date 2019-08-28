#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    float sum1=0;
    int n=0;
    float resualt1,resualt2=0,resualt3=0;

    do{
    cout<<"input an positive integer:";
    cin>>n;
    }while (n<=0);

    for(int i=1;i<=n;i++)   sum1+=(float)1/pow(i,2);
    //cout<<sum1;
    resualt1=sqrt(6*sum1);

    for(int16_t i=1;i>0;i++)    resualt2+=(float)1/pow(i,2);
    for(int16_t i=-1;i<0;i--)   resualt3+=(float)1/pow(i,2);
    
    cout<<endl<<setiosflags(ios::fixed)<<setprecision(6)<<"resualt1 = "<<resualt1<<endl<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(6)<<"resualt2 = "<<resualt2<<endl<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(6)<<"resualt3 = "<<resualt3<<endl;
    
    return 0;
}
