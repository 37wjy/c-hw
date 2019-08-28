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
    int a,b,cnt=0;
    cout<<"input the range of number(use space to saparate):"<<endl;
    cin>>a>>b;
    if(a<b)swap(a,b);
    cout<<"max : "<<a<<endl<<"min : "<<b<<endl;
    for(int i=b;i<=a;i++){
        if(isPrime(i))cnt++;
    }
    cout<<"There are "<<cnt<<" primes in the range ["<<b<<","<<a<<"]"<<endl;
    return 0;
}
