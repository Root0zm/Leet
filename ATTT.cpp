#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
 
string caesar(string s,int k ){
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            res += char((s[i]+k-97)%26+97);
        }
        else res += s[i];
    }
    return res;
}
string vinegere(string s, string k){
    string res,key;
    for(int i=0;i<s.length();i++){
        key += k[i%k.length()];
        if(s[i]!=' '){
            res += char((s[i]+key[i]-97-97)%26+97);
        }
        else res += s[i];
    }
    return res;
}
string affine(string s, int a, int b){
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            res += char((a*(s[i]-97)+b)%26+97);
        }
        else res = res + s[i];
    }
    return res;
}
long extendEuclid(long a,long b, long &x,long &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    long d,x1,y1;
    d = extendEuclid(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}
long nghichdao(long a, long n){
    long x,y;
    if(extendEuclid(a,n,x,y)==1){
        return (x%n+n)%n;
    }
    else return 1;
}
long luythua(long a, long b, long k){
    long res = 1;
    a=a%k;
    while(b>0){
        if(b%2==1){
            res = (res*a)%k;
        }
        a=(a*a)%k;
        b=b/2;
    }
    return res;
}
int main(){
    long a = 25,n=101;
    cout<<luythua(17,53,29);
}