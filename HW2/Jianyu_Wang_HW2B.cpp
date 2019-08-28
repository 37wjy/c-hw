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
    int i;
    while(true){
        cout<<"enter an positive integer:";cin>>i;
        cout<<"User enters "<<i<<endl;
        cout<<"The number "<<i<<" is : "<<(isPrime(i)?"PRIME":"NOT PRIME")<<endl;
    }
    return 0;
}
