#include <iostream>
#include <cmath>
using namespace std;

int WindChill(int T,int V){
    return (int)(35.74+0.6215*T-35.75*pow(V,0.16)+0.4275*T*pow(V,0.16));
}

//- TEMPERATURE | V

int main(int argc, char const *argv[])
{
    int temperature[18];
    int speed[12];
    int temp=0;
    cout<<"                                                 Temperature(F)"<<endl;
    cout<<"                      ";
    for(int i=0;i<18;i++){temperature[i]=40-5*i;
        if (temperature[i]>=10||(temperature[i]<0&&temperature[i]>-10))cout<<" ";
        else if(temperature[i]>=0)cout<<"  ";
        cout<<temperature[i]<<"  ";
    }cout<<endl<<endl;

    for(int i=1;i<=12;i++){
        speed[i-1]=5*i;
        i==5?cout<<"wind speed(mph):  ":cout<<"                  ";
        cout<<(i==1?" ":"")<<speed[i-1]<<"  ";
        for(int j=0;j<18;j++){
            temp=WindChill(temperature[j],speed[i-1]);
            if (temp>=10||(temp<0&&temp>-10))cout<<" ";
            else if(temp>=0)cout<<"  ";
            cout<<temp<<"  ";
        }
        cout<<endl<<endl;
    }
    
    return 0;
}
