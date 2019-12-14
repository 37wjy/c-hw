#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i[5]={0,1,2,3,4};
    int* p=&i[3];
    cout<<(*p++=2)<<endl;
    for (int j = 0; j < 5; j++)
    {
        cout<<i[j];
    }
    
    return 0;
}
