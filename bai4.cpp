#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#define MAX 8
using namespace std;
struct SinhVien{
    char hoDem[30];
    char ten[10];
    float diemTk;
};
struct List{
    int count;
    SinhVien e[MAX];
};
void create(List &L){
    L.count =-1;
}
int empty(List L){
    return L.count==-1;
}
int full(List L){
    return L.count==MAX-1;
}
void add(List &L,SinhVien sv){
   if(full(L)) return;
   else{
    L.count++;
    L.e[L.count]=sv;
   }
}
SinhVien taoSv(const char *i,const char*b, float c){
    SinhVien a;
    strcpy(a.hoDem,i);
    strcpy(a.ten,b);
    a.diemTk=c;
    return a;
}
void taoDanhSach(List &L){
    add(L,taoSv("A","AA",9.6));
    add(L,taoSv("BB","B",8.3));
    add(L,taoSv("Cc","C",7.2));
    add(L,taoSv("Dd","D",10));
}
void display(SinhVien a){
    cout<<fixed;
    cout<<setw(6)<<left<<a.hoDem<<" ";
    cout<<setw(5)<<a.ten<<" ";
    cout<<setw(6)<<setprecision(2)<<a.diemTk<<endl;
}
void show(List L){
    cout<<fixed;
    cout<<setw(6)<<left<<"Ho Dem"<<" ";
    cout<<setw(5)<<"Ten"<<" ";
    cout<<setw(6)<<setprecision(2)<<"Diem Tong Ket"<<endl;
    int d=0;
    while(d<=L.count){
        display(L.e[d]);
        d++;
    }
}
void search(List L,const char* k){
    int d=0,dem=0;
    cout<<"Ket Qua Tim Kiem La"<<endl;
    while(d<=L.count){
        if(strcmp(L.e[d].ten,k)==0){
            display(L.e[d]);dem++;
        }
        d++;
    }
    if(dem==0) cout<<"Khong Tim Thay"<<endl;
}
void xoa(List &L,const char* k){
    int d=0,dem=0;
    while(d<=L.count){
        if(strcmp(L.e[d].ten,k)==0){
            int i=d+1;
            while(i<=L.count){
                L.e[i-1]=L.e[i];
                i++;
            }
            dem++;
            L.count--;d--;
        }
        d++;
    }
    if(dem==0) cout<<"Khong Tim Thay Du lieu De Xoa: Danh sach la"<<endl;
    if(dem!=0) cout<<"Danh Sach Sau Khi Xoa la"<<endl;
}
void insert(List &L,int k,SinhVien sv){
    int d=L.count;
    k--;
    if(full(L)) return;
    if(k<0 ||k>L.count) return;
    while(k-1<d){
        L.e[d+1]=L.e[d];
        d--;
    }
    L.e[k]=sv;L.count++;
}
int main(){
    List L;
    create(L);
    empty(L);
    taoDanhSach(L);
    show(L);
    //cout<<"Nhap Ten SV  ";
    //char sv[10];
    //cin>>sv;
    //search(L,sv);
    //xoa(L,sv);
   // show(L);
    insert(L,3,taoSv("EE","E",5));
    show(L);
}