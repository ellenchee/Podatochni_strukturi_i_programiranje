/*Да се напише функција која како аргумент добива декаден број и променлива од тип магацин.
Функцијата треба да го испечати бинарниот број, но со користење само на магацинот. Да се напишат
сите структури и функции кои се потребни за да с*/
#include <iostream>
using namespace std;
int const MAX=20;

struct element{
    int info;
};

struct magacin{
    element niza[MAX];
    int top;
    void init (){
        top=-1;
    }
    void overflow (){
        cout<<"overflow"<<endl;
        exit (-1);
    }
    void underflow (){
        cout<<"underflow"<<endl;
        exit (-1);
    }
    bool iEmp (){
        return top==-1;
    }
    bool iFull (){
        return top==(MAX-1);
    }
    void push (int n){
        if (top>=(MAX-1)) overflow();
        niza[++top].info=n;
    }
    element pop (){ 
        if (top<0) underflow();
        return niza[top--];
    }
    element peek (){
        if (top<0) underflow();
        return niza[top];
    }
};
void DekVoBin (int dek, magacin &m)
{
    int c=dek;
    m.init();
    while (dek!=0){
        m.push(dek%2);
        dek/=2;
    }
    cout<<"binarniot ekvavilent na brojot "<<c<<" e: ";
    while (!(m.iEmp())){
    c=m.pop().info;
    cout<<c;
    }
    cout<<endl;
}
int main ()
{
    magacin mag;
    int dek;
    cout<<"vnesi dekaden broj: ";
    cin>>dek;
    DekVoBin (dek, mag);
}