#include <iostream>
#include <cmath>
using namespace std;


bool isPrime(int num){
    if(num<=2)return false;
    for(int i=2;i<=(int)sqrt(num);i++)  if(num%i==0)    return false;
    return true;
}

int main(int argc, char const *argv[])
{
    double i;
        cout<<"enter an positive integer:";cin>>i;
        cout<<"User enters "<<i<<endl;
        if(int(i*10)%1!=0)cout<<"The number "<<i<<" is : "<<"NOT PRIME"<<endl;
        else cout<<"The number "<<i<<" is : "<<(isPrime(i)?"PRIME":"NOT PRIME")<<endl;
    return 0;
}
