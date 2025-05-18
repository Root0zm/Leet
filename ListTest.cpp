#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define MAX 8
struct Sv{
    int msv;
    char ten[10];
    double diem;
};
struct List{
    int count;
    Sv e[MAX];
};
void create(List &l){
    l.count=-1;
}
int empty(List l){
    return l.count ==-1;
}
int full(List l){
    return l.count ==MAX -1;
}
int add(List &L, Sv a){
    if(full(L)) return 0;
    else{
        L.count++;
        L.e[L.count]=a;
        return 1;
    }
}
Sv taosv(int a,const char* b, double c){
    Sv f;
    f.msv = a;
    strcpy(f.ten,b);
    f.diem=c;
    return f;
}
void input (List &L){
    add(L,taosv(1,"A",10.2));
    add(L,taosv(2,"B",9.5));
    add(L,taosv(3,"C",8.5)); 
}
void display(Sv sv){
    cout<<fixed;
    cout<<setw(5)<<left<<sv.msv<<" ";
    cout<<setw(12)<<sv.ten<<" ";
    cout<<setw(4)<<setprecision(2)<<sv.diem<<endl; 
}
void htsv(List L){
    cout<<fixed;
    cout<<setw(5)<<left<<"MaSV"<<" ";
    cout<<setw(12)<<"TenSV"<<" ";
    cout<<setw(4)<<setprecision(2)<<"Diem"<<endl; 
    for(int i=0;i<=L.count;i++)
        display(L.e[i]);
}
void xoaPtDau(List &L){
    if(empty(L)){
        cout<<"Danh Sach Rong";
        return;
    }
    for(int i=1;i<=L.count;i++)
        L.e[i-1]=L.e[i];
    L.count--;
}
void chenPhanTu(List &L){
    if(full(L)) return;
    Sv sv=taosv(5,"G",6.5);
    for(int i=L.count;i>=2;i++){
        L.e[i+1]=L.e[i];
    }
    L.e[2]=sv;
    L.count ++;

}
void selectionSort(List &L){
    Sv tg;
    int m;
    for(int i=0;i<L.count;i++){
        for(int j=j;j<=L.count;j++){
            if(strcmp(L.e[j].ten,L.e[i].ten)>0){
                m=j;
            }
        }
        tg= L.e[m];
        L.e[m]=L.e[i];
        L.e[i]=tg;
    }
}
int main(){
    List o;
    create(o);
    input(o);
    htsv(o);
    xoaPtDau(o);
    htsv(o);
    chenPhanTu(o);
    htsv(o);
    selectionSort(o);
    htsv(o);
}