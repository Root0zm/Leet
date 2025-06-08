#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int temp = b;
        b=a%b;
        a=temp;
    }
    return a;
}
string affine(string s, int a, int b){
    if(gcd(a,26)!=1) return "Loi";
    string res = "";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            res += char((a*(s[i]-97)+b)%26)+97;
        }
        else res += s[i];
    }
    return res;
}
int main(){
    string s="abcde";
    int a=5,b=3;
    cout<<affine(s,a,b);
}