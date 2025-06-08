#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

string clear(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            s.erase(i,1);
            i--;
        }
    }
    return s;
}
string vigenere(string s,string k){
    string key="";
    for(int i=0;i<s.length();i++){
        key = key + k[i%k.length()];
    }
    string res ="";
    for(int i=0;i<s.length();i++){
        
        res += char((s[i]+key[i]-97-97)%26+97);
    }
    return res;
}
int main(){
    string s= "this crypto system is not secure";
    s=clear(s);

    string k="cipher";
    cout<< vigenere(s,k);
}