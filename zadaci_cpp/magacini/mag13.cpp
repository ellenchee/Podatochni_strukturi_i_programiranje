/*
 Преуредување елементи во магацин
Да се напише програма во која ќе се работи со магацини. Еден магацин се состои од повеќе
елементи. Во елементите основен податочен тип е цел број. Да се претпостави дека во
влезниот магацин секогаш има две 10ки и помеѓу нив секогаш има елементи.
Магацинот треба да се промени на следниов начин: во магацинот прво треба да се постават
елементите меѓу двете 10ки во обратна насока (вклучувајќи ги и броевите 10), потоа треба да
се додадат сите членови кои преостануваат во оригиналниот редослед, и на крај да се додадат
членовите меѓу двете 10ки во оригиналниот редослед (вклучувајќи ги и 10ките).
Да се напише програма за тестирање на функцијата и магацинот.
Пример:
Во магацинот се чуваат следните податоци:
3
8
5
10
13
4
7
6
10
11
3
По промената магацинот изгледа вака:
10
13
4
7
6
10
3
8
5
11
3
10
6
7
4
13
10
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define max 30
struct stack{
    int top;
    int niza[max];
    void init (){
        top=-1;
    }
    void underflow (){
        cout<<"underflow";
        return exit(-1);
    }
    void overflow (){
        cout<<"overflow";
        return exit(-1);
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==max-1;
    }
    void push(int e){
        if(isFull()) overflow();
        niza[++top]=e;
    }
    int pop(){
        if(isEmpty()) underflow();
        return niza[top--];
    }
    int peek(){
        if(isEmpty()) underflow();
        return niza[top];
    }
    void print(){
        for(int i=0; i<top; i++) cout<<niza[i]<<endl;
    }
};
void promeni (stack m){
    stack h1, h2, h3, h4;
    h1.init();
    h2.init();
    h3.init();
    h4.init();
    while (!m.isEmpty()){
        int el = m.pop(); int i=1;
        if ( el == 10 ){
            h1.push(el); //obratno - kje gi vrakja pravilno
            while (i){
                h1.push(m.pop()); //obratno
                if (h1.peek()==10) i=0;
            }
        }else{
            h3.push(el); //drugite 
        }
    }
    while (!h1.isEmpty()){
        int h =  h1.pop();
        h2.push(h); //h2 - pravilno
        h4.push(h);
    }
    while (!h4.isEmpty()){
        h1.push(h4.pop()); //h1 - obratno
    }
    while (!h3.isEmpty()){
        h4.push(h3.pop()); //h4 sredina
    }
    while (!h2.isEmpty()){
        m.push(h2.pop());
    }
    while (!h4.isEmpty()){
        m.push(h4.pop());
    }
    while (!h1.isEmpty()){
        m.push(h1.pop());
    } m.push(10);
        m.print();
    }

int main() {
    stack m1;
    m1.init();
    m1.push(3);
    m1.push(11);
    m1.push(10);
    m1.push(6);
    m1.push(7);
    m1.push(4);
    m1.push(13);
    m1.push(10);
    m1.push(5);
    m1.push(8);
    m1.push(3);
    promeni(m1);
    return 0;
}