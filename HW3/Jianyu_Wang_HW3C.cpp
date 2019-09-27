#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


class C3{
    int** _mx;
    int row,col;
public:
    C3(){
        ifstream f("3C.dat");
        f>>row>>col;
        int** mx=(int**)malloc(sizeof(int*)*row);
        for(int i=0;i<row;i++){
            mx[i]=(int*)malloc(sizeof(int)*col);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                f>>mx[i][j];
                ;}
        }
        _mx=mx;
        f.close();
    };


    void print(){
        int s=0;
        int s1=0;
        for(int i=0;i<row;i++){
            s=0;
            for(int j=0;j<col;j++){
                cout<<std::left<<setw(6)<<_mx[i][j];
                s+=_mx[i][j];
            }cout<<std::left<<setw(12)<<"rowsum ="<<s<<endl;
        }
        cout<<"---------------------------------"<<endl;
        for(int i=0;i<col;i++){
            s=0;
            for(int j=0;j<row;j++){
                s+=_mx[j][i];
            }
            cout<<std::left<<setw(6)<<s;
            s1+=s;
        }
        cout<< "totalsum =   "<<s1<<endl;
    }
};

int main(int argc, char const *argv[])
{
    C3 c;
    c.print();
    return 0;
}

