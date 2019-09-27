#include <iostream>
#include <string.h>

using namespace std;



class S{
public:
    string reverse(void){
        string r;
        for(int i=0;i<=a.length();i++){   
            //cout<<a[a.length()-i];
            r+=(a[a.length()-i-1]);
        }
        return r;
    }

    string vowels(void){
        string r;
        for(int i=0;i<=a.length();i++){
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')continue;
            r+=a[i];
        }
        return r;
    }

    bool palindrome(void){
        for(int i=0;i<a.length();i++){
            if(a[i]==a[a.length()-i-1])continue;
            else return false;
        }
        return true;
    }

    S(string _str){
        a=_str;
    }
private:
    string a;
};


int main(int argc, char const *argv[])
{
    cout<<"enter a string :";
    string str;
    getline(cin,str);
    S inp(str);
    cout<<endl<<"THe string backwards is : "<<inp.reverse()<<endl;
    cout<<endl<<"THe string is "<<(inp.palindrome()?"":"Not ")<<"palindrome"<<endl;
    cout<<endl<<"THe string without vowels : "<<inp.vowels()<<endl;
    return 0;
}
