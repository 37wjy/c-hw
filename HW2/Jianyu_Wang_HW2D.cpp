#include <iostream>
#include <string>

using namespace std;


string reverse(string a){
    string r;
    for(int i=0;i<=a.length();i++){   
        //cout<<a[a.length()-i];
        r+=(a[a.length()-i-1]);
    }
    return r;
}

string vowels(string a){
    string r;
    for(int i=0;i<=a.length();i++){
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')continue;
        r+=a[i];
    }
    return r;
}

bool palindrome(string a){
    for(int i=0;i<a.length();i++){
        if(a[i]==a[a.length()-i-1])continue;
        else return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string inp;
    cout<<"enter a string :";
    cin>>inp;
    cout<<endl<<"THe string backwards is : "<<reverse(inp)<<endl;
    cout<<endl<<"THe string is "<<(palindrome(inp)?"":"Not ")<<"palindrome"<<endl;
    cout<<endl<<"THe string without vowels : "<<vowels(inp)<<endl;
    return 0;
}
