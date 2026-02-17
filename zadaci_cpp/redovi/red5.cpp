#include <iostream>
#include <stdlib.h>
using namespace std;
#define max1 50
#define max2 1000
struct chovek{
    string ime, prezime;
    bool lk, p, vd;
};
struct element{
    chovek info;
};
struct queue{
    element niza[max1];
    int front, rear;
    void init(){
        front=-1;
        rear=0;
    }
    bool isFull(){
        return rear=(max1-1);
    }
    bool isEmpty(){
        return front = -1;
    }
    void underflow(){
        cout<<"underflow"<<endl;
        return exit (-1);
    }
    void overflow(){
        cout<<"overflow"<<endl;
        return exit (-1);
    }
    void enqueue(element e){
        if (isFull()) overflow();
        niza[++rear]=e;
    }
    element dequeue(){
        if (isEmpty()) underflow();
        element pom = niza[front];
        for (int i=front; i<rear; i++)
            niza[i]=niza[i+1];
        rear--;
        return pom;
    }
    element peek(){
        if (isEmpty()) underflow();
        return niza[front];
    }
};