#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>

using namespace std;

struct SinhVien{
    char hoDem[30];
    char ten[10];
    float diemTk;
};
struct Node{
    SinhVien infor;
    Node* next;
};
typedef Node* Tro;
void create(Tro &L){
    L = NULL;
}
int empty(Tro L){
    return L==NULL;
}
SinhVien taoSv(const char *i,const char*b, float c){
    SinhVien a;
    strcpy(a.hoDem,i);
    strcpy(a.ten,b);
    a.diemTk=c;
    return a;
}
void add(Tro &L,SinhVien a){
    Tro Q=L;
    Tro P = new Node;
    P->infor=a;
    P->next=NULL;
    if(empty(L)) L=P;
    else{
        while(Q->next !=NULL){
            Q=Q->next;
        }
        Q->next = P;
    }
}
void taoDanhSach(Tro &L){
    add(L,taoSv("A","AA",9.6));
    add(L,taoSv("BB","B",8.3));
    add(L,taoSv("Cc","C",7.2));
    add(L,taoSv("Dd","D",10));
}
void display(Tro L){
    cout<<fixed;
    cout<<setw(6)<<left<<L->infor.hoDem<<" ";
    cout<<setw(5)<<L->infor.ten<<" ";
    cout<<setw(6)<<setprecision(2)<<L->infor.diemTk<<endl;
}
void show(Tro L){
    cout<<fixed;
    cout<<setw(6)<<left<<"Ho Dem"<<" ";
    cout<<setw(5)<<"Ten"<<" ";
    cout<<setw(6)<<setprecision(2)<<"Diem Tong Ket"<<endl;
    Tro Q=L;
    while(Q !=NULL)
        {display(Q);Q=Q->next;}
}
void search(Tro L, const char* name){
    Tro Q=L;
    int d=0;
    cout<<"Ket qua tim kiem la"<<endl;
            cout<<fixed;
            cout<<setw(6)<<left<<"Ho Dem"<<" ";
            cout<<setw(5)<<"Ten"<<" ";
            cout<<setw(6)<<setprecision(2)<<"Diem Tong Ket"<<endl;
    while(Q!=NULL){
        if(strcmp(name,Q->infor.ten)==0)
        {
            display(Q);
            d++;
        }
        Q=Q->next;
    }
    if(d==0)
    cout<<"Khong Tim Thay Sinh Vien";
}
void xoa(Tro &L, const char* name){
    Tro Q=L,prev=NULL;
    int d=0;
     while(Q!=NULL){
        if(strcmp(name,Q->infor.ten)==0)
        {
            Tro tam = Q;
            if(prev ==NULL)
                {L=Q->next;Q=L;}
            else {prev->next=Q->next;Q=Q->next;}
            delete tam;d++;
        }else 
            {prev=Q;
        Q=Q->next;}
        
    }
    if(d!=0) cout<<"Danh sach Sinh Vien Moi La"<<endl;
    if(d==0) cout<<"Khong Tim Thay Sinh Vien    De Xoa: Danh sach sinh vien la"<<endl;
}
void insert(Tro &L,int k,SinhVien chen){
    int d=1;
    Tro Q = L;
    while(Q->next!=NULL && d<k-1){
        Q=Q->next;d++;
    }
    if(d<k-1){
        cout<<"Khong chen duoc"<<endl;return;
    }
    Tro P = new Node;
    P->infor = chen;
    P->next = Q->next;
    Q->next = P;

}
int main(){
    Tro L;
    create(L);
    taoDanhSach(L);
    show(L);
    cout<<"Nhap Ten SV  ";
    char sv[10];
    cin>>sv;
    search(L,sv);
    xoa(L,sv);
    show(L);
    insert(L,3,taoSv("EE","E",5));
    show(L);
}