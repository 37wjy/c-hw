#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int inp=0;
    do{
        cin>>inp;
    }while(inp<=0);
    cout<<inp<<"    ";
    do{
        inp=inp%2?inp*3+1:inp/2;
        cout<<inp<<"    ";
    }while(inp!=1);
    cout<<endl;
    return 0;
}
