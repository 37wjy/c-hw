#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream file;
    float angle,dist;
    float x=0,y=0;
    file.open("hw2e.dat");
    while((file>>angle)&&(file>>dist)){
        cout<<angle<<"  "<<dist<<endl;
        if(angle==-1||dist==-1){
            cout<<"program terminates"<<endl;
            break;
        }
        x+=sin((angle/180)*M_PI)*dist;
        y+=cos((angle/180)*M_PI)*dist;
        y = ( (float)( (int)( (y + 0.000005) * 100000 ) ) ) / 100000;        //precision(5)
        x = ( (float)( (int)( (x + 0.000005) * 100000 ) ) ) / 100000;
        cout<<"Location: x = "<<x<<", y = "<<y<<endl<<endl;
    }

    return 0;
}
