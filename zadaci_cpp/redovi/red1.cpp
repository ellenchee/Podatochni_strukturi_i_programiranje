/*1. На шалтерот на МВР се чека за вадење на лични карти, пасоши и возачки дозволи. Секој човек, за кој
се знае името, презимето и информација на кои шалтери треба да чека, застанува во редицата за
исправата која ја вади. Ако треба да вади повеќе исправи прво вади лична карта, па пасош, па возачка
дозвола (откако ќе биде услужен во приоритетната редица, застанува во друга редица). Кога се отвора
шалтерот, најпрво се опслужуваат луѓето кои вадат лични карти, па пасоши, па возачки дозволи. Да се
напише програма која го симулира гореопишаното дејство.*/
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define MAX1 50
#define MAX2 1000
struct chovek{
    string ime, prezime;
    bool lk, p, vd;
};
struct element{
    chovek info;
};
struct queue{
    element niza[MAX1];
    int front, rear;
    void init(){
        front=0; 
        rear=-1;
    }
    void overflow(){
        cout<<"overflow"<<endl;
        exit (-1);
    }
    void underflow(){
        cout<<"underflow"<<endl;
        exit (-1);
    }
    bool isFull(){
        return (rear==MAX1-1);
    }
    bool isEmpty(){
        return (rear==-1);
    }
    void enqueue(element e){
        if(isFull()) overflow();
        niza[++rear]=e;
    }
    element dequeue(){
        if(isEmpty()) underflow();
        element pom=niza[front];
        for (int i=front; i<rear; i++)
            niza[i]=niza[i+1];
            rear--;
        return pom;
    }
    element peek(){
        if(isEmpty()) underflow();
        return niza[front];
    }
};
void opslozuvanje(queue &r1, queue &r2, queue &r3){
    element e; 
    while (!r1.isEmpty()){
        e=r1.dequeue();
        e.info.lk=0;
        cout<<"vo redot za licni karti opsluzen e: "<<e.info.ime<<" "<<e.info.prezime<<"."<<endl;
    if (e.info.p==1)
        r2.enqueue(e);
    else if (e.info.vd == 1 )
        r3.enqueue(e);
    }
    while (!r2.isEmpty()){
        e=r2.dequeue();
        e.info.p=0;
        cout<<"vo redot za pasosh opsluzen e: "<<e.info.ime<<" "<<e.info.prezime<<"."<<endl;
        if (e.info.vd == 1)
            r3.enqueue(e);
    }
    while (!r3.isEmpty()){
        e=r3.dequeue();
        e.info.vd=0;
        cout<<"vo redot za vozacki dozvoli opsluzen e: "<<e.info.ime<<" "<<e.info.prezime<<"."<<endl;
    }
}
int main()
{
    queue rlk, rp, rvd;
    rlk.init();
    rp.init();
    rvd.init();
    chovek chovek;
    char znak;
    for (int i=0; ; i++){
        cout<<"vnesete ime: ";
        cin>>chovek.ime;
        cout<<"vnesete prezime: ";
        cin>>chovek.prezime;
        cout<<"dali kje chekate vo redot za licni karti? (da=1, ne=0)";
        cin>>chovek.lk;
        cout<<"dali kje chekate vo redot za pasosh? (da=1, ne=0)";
        cin>>chovek.p;
        cout<<"dali kje chekate vo redot za vozacki dozvoli? (da=1, ne=0)";
        cin>>chovek.vd;
        element e;
        e.info=chovek;
        if (chovek.lk) rlk.enqueue(e);
        else if (chovek.p) rp.enqueue(e);
        else if (chovek.vd) rvd.enqueue(e);
        cout<<"ako nema povekje lugje pritisni . ";
        cin>>znak;
        if (znak=='.') break;
        else continue;
    }
    opslozuvanje (rlk, rp, rvd);
    return 0;
}