#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

long long luyThua(long long x, long long k, long long n){
    long long res = 1;
    x=x%n;
    while(k>0){
        if(k%2 !=0){
            res = (res *x)%n;
        }
        x=(x*x)%n;
        k=k/2;
    }
    return res;
}
int main(){
    long long x=17, k = 53, n=29;
    cout<<luyThua(x,k,n);
}