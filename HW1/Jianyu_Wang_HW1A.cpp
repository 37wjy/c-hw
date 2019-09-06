#include <iostream>
#include <stdio.h>
#include <stdint.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int64_t inp=0;
    do{
        cout<<"input an integer : ";
        cin>>inp;
    }while(inp<=0||inp>(INT64_MAX-1)/3);
    cout<<inp<<"    ";
    do{
        inp=inp%2?inp*3+1:inp/2;
        cout<<inp<<"    ";
    }while(inp!=1);
    cout<<endl;
    return 0;
}