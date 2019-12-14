#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

class C
{
private:
public:
    int M = 0;
    C() {}
    C(int m) : M(m) {}

    int charge(int m)
    {
        if (M < m)
        {
            throw "not enough";
            return M;
        }
        else
        {
            M -= m;
            return M;
        }
    }
    int save(int m)
    {
        M += m;
        return M;
    }

};

int main(int argc, char const *argv[])
{
    vector<int> v;
    C *d = new C(100);
    try
    {
        v.push_back(d->save(100));
        v.push_back(d->charge(200));
        v.push_back(d->charge(300));
        v.push_back(d->save(100));
        cout << d->M << endl;
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }

    try
    {
        v.push_back(d->charge(300));
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
    v.push_back(d->save(100));
    cout << d->M << endl;
    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}

/*



*/