#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
/* Max: Compute the largest value in the list.       
     Min: Compute the smallest value in the list.       
     Mean: Compute the average by summing all the elements and dividing by 
           the number of elements.       
     Variance: Compute the sum  (x[i] - Mean)2 / n for all x[i].*/

class AS{
    ifstream file;
    vector<double> s;
    int _size=0;
    double _mean=0;
public:
    AS(string rote="3B.dat"){
        ifstream file(rote);
        for(double i;file>>i;)s.push_back(i);
        _size=s.size();
    };

    int size(){
        return _size;
    }

    double min(){
        if(!_size)return 0;
        double _min=s[0];
        for(auto x:s){
            _min=x>_min?_min:x;
        }
        return _min;
    }

    double max(){
        if(!_size)return 0;
        double _max=s[0];
        for(auto x:s){
            _max=x<_max?_max:x;
        }
        return _max;
    }

    double mean(){
        if(!_size)return 0;
        double _var;
        for(auto x:s)_var+=x/_size;
        _mean=_var;
        return _var;
    }


    double var(){
        if(!_size)return 0;
        if(!_mean)mean();
        double _var;
        for(auto x:s)_var+=pow(x-_mean,2)/_size;
        return _var;
    }
};


int main(int argc, char const *argv[])
{
    AS f("3B.dat");
    cout.setf(ios::fixed,ios::floatfield);
    cout<<"Elements = "<< f.size()<<endl   
    <<"Max = "    <<f.max()<<endl
    <<"Min = "   <<f.min()<<endl
    <<"Mean = " <<f.mean()<<endl
    <<"Var = "<<f.var();
    return 0;
}
