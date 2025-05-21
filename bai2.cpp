#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct ic{
    int tt;
    char name[8];
    char alv[2];
};
struct Node{
    ic infor;
    Node* next;
};

typedef Node* Tro;
void create(Tro &L){
    L=NULL;
}
int empty(Tro L){
    return L==NULL;
}
void add(Tro &L, ic a){
    Tro Q = L;
    Tro P = new Node;
    P->infor = a;
    P->next = NULL;
    if(empty(L)) L=P;
    else{
        while(Q->next != NULL)
            Q=Q->next;
        Q->next=P;
    }
}
ic createMe(int tt,const char *ten,const char *st){
    ic A;
    A.tt=tt;
    strcpy(A.name,ten);
    strcpy(A.alv,st);
    return A;
}
void createList(Tro &L){
    add(L,createMe(1,"Ay","Y"));
    add(L,createMe(2,"Be","N"));
    add(L,createMe(3,"Ca","Y"));
    add(L,createMe(4,"An","?"));
}
void display(Tro L){
    cout<< fixed;
    cout<<setw(4)<<left<<L->infor.tt<<" ";
    cout<<setw(7)<<L->infor.name<<" ";
    cout<<setw(3)<<L->infor.alv<<endl;
}
void show(Tro L){
    Tro Q=L;
    cout<< fixed;
    cout<<setw(4)<<left<<"Rank"<<" ";
    cout<<setw(7)<<"Symbol"<<" ";
    cout<<setw(3)<<"Alv?"<<endl;
    while(Q !=NULL){
        display(Q);
        Q=Q->next;
    }
}
void deleteFirst(Tro &L){
    if(empty(L)){
        cout<<"Rong";return;
    }
    Tro Q =L;
    L=L->next;
    delete Q;
}
Tro find(Tro L, int k){
    Tro Q=L, P=new Node;
    int d=1;
    while(Q->next !=NULL && d<k-1){
        d++;Q=Q->next;
    }
    if(d<k-1) return NULL;
    else return Q;
}
void insert(Tro &L,Tro Q, ic a){
    Tro P = new Node;
    P->infor = a;
    P->next=Q->next;
    Q->next=P;
}
void chenViTri3(Tro &L){
    Tro Q=find(L,3);
    if(Q==NULL) {
        cout<<"Khong chen dc";return;
    }
    insert(L,Q,createMe(5,"G","N"));
}
void bubbleSort(Tro &L){
    Tro Q=L;
    bool swap=false;
    do{
        swap = false;
        Tro P=L;
        while(P->next!=NULL){
            if(strcmp(P->infor.name,P->next->infor.name)<0){
                ic tg= P->infor;
                P->infor =P->next->infor;
                P->next->infor=tg;
                swap = true;
            }
            P=P->next;
        }
    } while (swap);
}
void selectionSort(Tro L){
    Tro Q=L;
    while(Q->next!=NULL){
        Tro M=Q,P=Q->next;
        while(P!=NULL){
            if(strcmp(P->infor.name,M->infor.name)>0){
                M=P;
            }
            P=P->next;
        }
        ic tg= Q->infor;
            Q->infor =M->infor;
            M->infor=tg;
        Q=Q->next;
    }
}
void insertionSort(Tro L ){
    
}
int main(){
    Tro L;
    create(L);
    createList(L);
    show(L);
    chenViTri3(L);
    selectionSort(L);
    show(L);
    
}