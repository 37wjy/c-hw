#include <iostream>
using namespace std;

int main(int argc, const char** argv) {
    int a = 5 % 2;  
    char c = 'A'+ 1;
    cout<<sizeof(long)<<endl
    <<sizeof(long long)<<endl
    <<sizeof(int)<<endl
    <<sizeof(long double)<<endl
    <<sizeof(bool)<<endl;
    cout<<int(5.0 / 2.0)<<int(5.0) / 2.0<<(int)5.0 / 2.0<< 5 % 2 + 3 % 2<<endl;
    return 0;
}