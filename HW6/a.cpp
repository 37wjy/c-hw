#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    string a;

    int l,r;
    cin>>l>>r;
    cin>>a;
    int x,y;
    for (int i = 0; i < r; i++)
    {
        cin>>x>>y;
        for (int j = x-1; j < y-1; j++)
        {
            if(a[j]=='0'){
                a[j]='1';
            }else{
                a[j]='0';
            }
        }   
        cout<<a;
    }
    return 0;
}
