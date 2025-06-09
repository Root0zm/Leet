#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

long extendEuclid(long a, long b, long &x, long &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    long x1,y1,d;
    d= extendEuclid(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}
long nghichdao(long a,long n){
    long x,y;
    if(extendEuclid(a,n,x,y) !=1)
        return -1;
    return (x%n+n)%n;
}
int main(){
    long a=25,n=101;
    cout<< nghichdao(a,n);
}