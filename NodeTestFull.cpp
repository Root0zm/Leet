#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

struct toi{
    int tt;
    char ten[10];
    float stat;
};
struct Node{
    toi infor;
    Node *next;
};
typedef Node* Tro;
void create(Tro &L){
    L =NULL;
}
int empty(Tro L){
    return L==NULL;
}
toi createMe(int a,const char *b,float c){
    toi ratt;
    ratt.tt = a;
    strcpy(ratt.ten,b);
    ratt.stat= c;
    return ratt;
}
void add(Tro &L, toi t){
    Tro Q =L, P = new Node;
    P->infor = t;
    P->next = NULL;
    if(empty(L)) L=P;
    else{
        while(Q-> next != NULL)
            Q=Q->next;
        Q->next = P;
    }
}
void input(Tro &L){
    add(L,createMe(1,"Root",5.6));
    add(L,createMe(2,"Icey",6.5));
    add(L,createMe(3,"Hokma",8.8));
    add(L,createMe(4,"Ozm",33));
}
void display(toi me){
    cout<<fixed;
    cout<<setw(4)<<left<<me.tt<<" ";
    cout<<setw(8)<<me.ten<<" ";
    cout<<setw(3)<<setprecision(2)<<me.stat<<endl;
}
void ME(Tro L){
    Tro Q=L;
    cout<<fixed;
    cout<<setw(4)<<left<<"A?"<<" ";
    cout<<setw(8)<<"B?"<<" ";
    cout<<setw(3)<<setprecision(2)<<"C? "<<endl;
    while(Q!= NULL){
        display(Q->infor);
        Q=Q->next;
    }
    cout<<"------------------------------------"<<endl;
}
void xoaPtDau(Tro &L){
    if(empty(L)){
        cout<<"Danh sach rong";
        return;
    }
    Tro Q = L;
    L= L-> next;
    delete Q;
}
Tro search(Tro L,int k){
    int d=1;
    Tro Q= L;
    while(d<k-1 && Q->next !=NULL){
        d++;
        Q=Q->next;
    }
    if(d<k-1) return NULL;
    else return Q;
}
void insert(Tro &L,Tro Q,toi ic){
    Tro P = new Node;
    P-> infor = ic;
    P->next=Q->next;
    Q->next=P;
}
void chen_vi_tri_3(Tro &L){
    Tro Q = search(L,3);
    if(Q==NULL) { cout<<"Khong chen dc"; return;}
    insert(L,Q,createMe(7,"zz",200));
}
void selectionSort(Tro &L){
    Tro Q = L,M;
    Tro P = new Node;
    while(Q->next != NULL){
        M=Q;
        P = Q->next;
        while(P!= NULL){
            if(strcmp(Q->infor.ten,P->infor.ten))
                M=P;
            P=P->next;
        }
        toi tg = Q->infor;
        Q->infor= M->infor;
        M->infor=tg;
        Q=Q->next;
    }
}
int main(){
    Tro L;
    create(L);
    input(L);
    ME(L);
    xoaPtDau(L);
    ME(L);
    chen_vi_tri_3(L);
    ME(L);
    selectionSort(L);
    ME(L);
}