#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int gauss_r=100*(1+100)/2;
    int loop_r=0;
    cout<<"Gauss Results: "<<gauss_r<<endl;
    for(int i=1;i<=100;i++)loop_r+=i;
    cout<<"Loop Results: "<<loop_r<<endl;
    cout<<"Both results are "<<((gauss_r==loop_r)?"the same":"not same")<<"."<<endl;
    return 0;
}

