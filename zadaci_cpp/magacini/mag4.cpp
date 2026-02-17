/*Да се напише функција која како аргумент добива магацин во кој се наоѓаат букви (овој
магацин треба да се модифицира во функцијата). Во функцијата треба да се споредат буквите
со буквите кои се наоѓаат на иста позиција во превртен магацин и доколку две букви во ASCII
се разликуваат за 1 во излезниот магацин да се запише помалата буква. Во функцијата може да
се користат помошни магацини (потребни се минимум два помошни магацини), но користење
на низи не е дозволено. Дополнително во програмата да се дефинира структурата магацин
заедно со сите функции кои се потребни за функционирање на магацинот: за иницијализација,
за проверка дали магацинот е полн и дали е празен, за внесување елементи, за изнесување на
елементи, за гледање на елементот кој е најгоре во магацинот и за печатење на елементите без
вадење на истите од магацинот. Излезниот магацин од функцијата се печати во главната
функција
Пример:
Пред промена:
Магацинот е:
|p|
|o|
|s|
|t|
|a|
|q|
Прво внесен елемент во
магацинот е q, а последно внесен
е p.
После промената:
Магацинот ќе биде:
|p|
|s|
|s|
|p|
Превртениот магацин ќе ги има елементите
|q||a||t||s||o||p|, па разлика од 1 има помеѓу
паровите елементи |p| и |q| (од каде се
добива |p|) и |s| и |t| (од каде се довива |s|)
Решение:*/
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define MAX 10
struct magacin {
    char niza[MAX];
    int top;
    void init (){
        top=-1;
    }
    void overflow(){
        cout<<"overflow"<<endl;
        exit (-1);
    }
    void underflow(){
        cout<<"underflow"<<endl;
        exit (-1);
    }
    bool iFul(){
        return top==MAX-1;
    }
    bool iEmp(){
        return top==-1;
    }
    void push(int e){
        if (iFul()) overflow();
        niza[++top]=e;
    }
    int pop(){
        if (iEmp()) underflow();
        return niza[top--];
    }
    int peek(){
        if (iEmp()) underflow();
        return niza[top];
    }
    void print (){
        for (int i=0; i<top; i++)
        {
            cout<<niza[i]<<" ";
            cout<<endl;
        }
    }
};
void pronajdi (magacin *m){
    magacin pom1, pom2;
    pom1.init();
    pom2.init();
    while (!m->iEmp()){
        char c=m->pop();
        pom1.push(c);
        pom2.push(c);
    }
    while (pom2.iEmp()){
        m->push(pom2.pop());
    }
    while (!m->iEmp()){
        char c1=m->pop();
        char c2=pom1.pop();
        if (c1-c2==1){
            pom2.push(c2);
        }
        if (c2-c1==1){
            pom2.push(c1);
        }
    }
    while(!pom2.iEmp()){
        m->push(pom2.pop());
    }
}
int main ()
{
    magacin m;
    m.init();
    m.push('q');
    m.push('a');
    m.push('t');
    m.push('s');
    m.push('o');
    m.push('p');
    pronajdi(&m);
    while(!m.iEmp()){
        cout<<m.pop()<<endl;
    }
    return 0;
}