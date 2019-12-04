#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{

    for (int i = 10 - 1; i >= -5; i--)
    {
        if (i)
        {
            cout << 'a';
        }
        else
        {
            cout << 'b';
        }
    }

    return 0;
}
