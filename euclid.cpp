#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;


long extendEuclic(long a, long b, long &x,long &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    long d, x1,y1;
    d=extendEuclic(b,a%b,x1,y1);
    x=y1;
    y=x1 -(a/b)*y1;
    return d;
}
int main(){
    long a = 814, b=187;
    long x,y;
    cout<<extendEuclic(a,b,x,y)<<" "<<x<<" "<< y;
}
