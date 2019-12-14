#include <iostream>

using namespace std;

class C
{
private:
public:
    int M = 0;
    C() {}
    C(int m) : M(m) {}
    void charge(int m)
    {
        if (M < m)
            throw "not enough";
        else
            M -= m;
    }
    void save(int m)
    {
        M += m;
    }
};

int main(int argc, char const *argv[])
{
    C c;
    int a = 0;
    while (1)
    {
        cin >> a;
        try
        {
            if (a)
            {
                cin.clear();
                int i;
                cin >> i;
                c.save(i);
            }
            else
            {
                cin.clear();
                int i;
                cin >> i;
                c.charge(i);
            }
        }
        catch (const char* msg)
        {
            std::cerr << msg << '\n';
        }

        cout << c.M << endl;
    }
    return 0;
}
