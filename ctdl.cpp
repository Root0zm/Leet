#include <iostream>
#include <iomanip>
using namespace std;

void insertionSort(long a[],long n){
  
    for(int i=1;i<n;i++){
          long temp = a[i];int j=i-1;
        while(j>=0 && a[j]<temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void bubbleSort(long a[],long n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j-1]<a[j]){
                long temp = a[j-1];
                a[j-1]=a[j];
                a[j]= temp;
            }
        }
    }
}
void selectionSort(long a[],long n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[m]<a[j]) m=j;
        }
        int temp = a[m];
        a[m] =a[i];
        a[i]=temp;
    }
}
struct CuaHang{
    string ten;
    string tenchu;
    long doanhthu;
    long nhanvien;
};
struct Node{
    CuaHang infor;
    Node *next;
};
typedef  Node *Tro;
void create(Tro &L){
    L = NULL;
}
int empty(Tro L){
    return L==NULL;
}
CuaHang taoCH(string a, string b, long c, long d){
    CuaHang ch;
    ch.ten=a;
    ch.tenchu=b;
    ch.doanhthu=c;
    ch.nhanvien=d;
    return ch;
}
void add(Tro &L, CuaHang ch){
    Tro Q=L,P = new Node;
    P-> infor = ch;
    P-> next = NULL;
    if(Q == NULL) L = P;
    else {
        while(Q-> next != NULL){
            Q=Q->next;
        }
        Q->next = P;
        
    }
}
void taods(Tro &L){
    add(L,{"a","A",10,5});
    add(L,{"b","B",5,2});
    add(L,{"c","C",20,2});
    add(L,{"d","D",3,1});
    add(L,{"g","G",4,5});
}
void ht(Tro L){
    Tro Q = L;
    while(Q->next != NULL){
        if(Q->infor.doanhthu > 5){
            cout<<Q->infor.ten<<" "<<endl;
        }
        Q=Q->next;
    }
}
void ht2(Tro L){
    Tro Q = L;
    while(Q != NULL){
        
            cout<<Q->infor.ten<<" "<<endl;
        
        Q=Q->next;
    }
}
void chen(Tro &L){
    Tro Q = L;
    int d=0;
    CuaHang moi=taoCH("e","E",20,6);
    Tro P = new Node;
    P->infor = moi;
    while( Q!=NULL){
        if(d==3){
            P->next = Q->next;
            Q->next =P;
            break;
        }
        Q=Q->next;
        d++;
    }
}
void xoa(Tro &L){
    Tro Q = L;
    if(L->infor.doanhthu<5) {
        Tro temp =L;
        L=L->next;
        delete temp;
        return;
    }
    
    while(Q!=NULL&& Q->next!=NULL){
        if(Q->next->infor.doanhthu < 5){
            Tro temp = Q->next;
            Q->next = temp->next;
            delete temp; 
        }else 
        Q=Q->next;

    }
}
void hienthi(Tro L ){
    Tro Q=L;
    cout<<left<<setw(3)<<"Ten"<<" ";
    cout<<setw(4)<<"Ten chu"<<" ";
    cout<<setw(3)<<"Tien"<<" ";
    cout<<setw(3)<<"NV"<<endl;
    while(Q!=NULL){
    cout<<left<<setw(3)<<Q->infor.ten<<" ";
    cout<<setw(4)<<Q->infor.tenchu<<" ";
    cout<<setw(3)<<Q->infor.doanhthu<<" ";
    cout<<setw(3)<<Q->infor.nhanvien<<endl;
    Q=Q->next;
    }
}
void xoamin(Tro &L){
    Tro Q=L;
    long m = Q->infor.doanhthu;
    Tro P,prev,prevMin;
    while(Q!=NULL&&Q->next!=NULL){
        if(m>Q->infor.doanhthu) {m=Q->infor.doanhthu;P=Q;prevMin = prev;}
        prev = Q;
        Q=Q->next;
    }
    prevMin ->next = P->next;
}

int main(){
    long a[5]={3,2,4,1,5};
   Tro L;
   create(L);
   taods(L);
   chen(L);
   hienthi(L);
xoamin(L);
hienthi(L);
}