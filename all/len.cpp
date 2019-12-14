#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

class msSt
{
private:
    char* s;
    uint64_t len;
public:
    msSt(){};
    msSt(char* s){
        len=strlen(s);
        
    };

};


int main(int argc, char const *argv[])
{
    int a[8];

    int* b =new int[9];
    for (int i = 0; i < 8; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < 9; i++)
    {
        b[i]=i;
    }

    for(auto i:a){
        
    }
    for(auto i: b){

    }
    
    cout << sizeof(a) << endl;
    cout << strlen(b);

    return 1;
}