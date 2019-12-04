#include <iostream>

using namespace std;


class c
{
private:
    /* data */
public:
    c(char* s) {
        int i=0;
        while (1)
        {
            if(s[i]=='\0'||s[i]=='\n')
                break;
            std:cout<<s[i];
            i++;
        }
    }
    ~c() {}
};

int main(int argc, char const *argv[])
{
    c("qwewqewq");
    return 0;
}
