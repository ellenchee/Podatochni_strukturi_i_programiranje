/*3. Да се напише функција која како аргументи добива два реда и треба да излез да врати нов
ред кој ги комбинира влезните редови. Функцијата е наменета да ги распредели студентите кои
истовремено полагаат втор колоквиум по ПСП и БиП во еден ред (влезните редови се
наменети за секој од предметите ПСП и БиП). За секој студент се знае презиме, број на индекс
(без година), испит кој го полага и број на освоени поени на прв колоквиум. Притоа во
излезниот ред треба прво да ги постават студентите кои освоиле над 40 поени на првиот
колоквиум по ПСП, па студентите кои освоиле над 50 поени на првиот колоквиум по БИП, по
што треба да се постават останатите студенти по ПСП (кои имаат под 40 поени) и на крај
останатите студенти по БиП (кои имаат под 50 поени). Доколку некој студент има под 30
поени да не се запишува во излезниот ред. Во функцијата може да се користат помошни
редови, но користење на низи не е дозволено. По завршувањето на функцијата двата влезни
реда треба да бидат празни. Дополнително во програмата да се дефинира структурата ред
заедно со сите функции кои се потребни за функционирање на редот: за иницијализација, за
проверка дали редот е полн и дали е празен, за внесување елементи, за изнесување на
елементи, за гледање на елементот кој е напред во редот и за печатење на елементите без
вадење на истите од редот.
Пример:
На влез:
ПСП ред: БиП ред:
|Naumoska 134 PSP 90| |Koloski 12 BiP 60|
|Stamatovski 14 PSP 80| |Spaseski 236 BiP 40|
|Bogoeska 146 PSP 39| |Skrceski 150 BiP 80|
|Vanevski 76 PSP 20|
Во редот за ПСП прв внесен елемент е
|Vanevski 76 PSP 20|
На излез:
Мешан ред:
|Spaseski 236 BiP 40|
|Bogoeska 146 PSP 39|
|Koloski 12 BiP 60|
|Skrceski 150 BiP 80|
|Naumoska 134 PSP 90|
|Stamatovski 14 PSP 80|
Решение: */
#include <iostream>
#include <stdlib.h>
using namespace std; 
#define MAX 10
struct element{
    string prezime;
    int indeks;
    string ispit;
    int poeni;
};
struct queue{
    element niza[MAX];
    int rear, front;
    void init(){
        front=0; rear=-1;
    }
    void overflow (){
        cout<<"overflow"<<endl; exit (-1);
    }
    void underflow (){
        cout<<"underflow"<<endl; exit (-1);
    }
    bool isFull(){
        return (rear==MAX-1);
    }
    bool isEmpty(){
        return (rear==-1);
    }
    void enqueue(element e){
        if (isFull()) overflow();
        niza[++rear]=e;
    }
    element dequeue(){
        if (isEmpty()) underflow();
        element pom=niza[front];
        for (int i=front ;i<rear; i++)
            niza[i]=niza[i+1];
            rear--;
        return pom;
    }
    element peek(){
        if (isEmpty()) underflow();
        return niza[front];
    }
    void print (){
        for (int i=0; i<=rear; i++)
        cout<<niza[i].prezime<<" "<<niza[i].indeks<<" "<<niza[i].ispit<<" "<<niza[i].poeni<<endl;
    }
};
queue preuredi(queue &r1, queue &r2){
    queue h1, h2;
    queue izlez;
    h1.init();
    h2.init();
    izlez.init();
    element e1, e2;
    while (!r1.isEmpty()){
        e1=r1.dequeue();
        if (e1.poeni>=40)
            izlez.enqueue(e1);
        else 
            h1.enqueue(e1);
    }
    while (!r2.isEmpty()){
        e2=r2.dequeue();
        if (e2.poeni>=50)
            izlez.enqueue(e2);
        else 
            h2.enqueue(e2);
    }
    while (!h2.isEmpty()){
        e1=h1.dequeue();
        if (e1.poeni>=30)
            izlez.enqueue(e1);
    }
    while (!h2.isEmpty()){
        e2=h2.dequeue();
        if (e2.poeni>=30)
            izlez.enqueue(e2);
    }
    return izlez;
};
int main() 
{
    queue r1, r2, r;
    r1.init();
    r2.init();
    r1.enqueue({"Vanevski", 76, "PSP", 20});
    r1.enqueue({"Bogoeska", 146, "PSP", 39});
    r1.enqueue({"Stamatovski", 14, "PSP", 80});
    r1.enqueue({"Naumoska", 134, "PSP", 90});
    r2.enqueue({"Skrceski", 150, "BiP", 80});
    r2.enqueue({"Spaseski", 236, "BiP", 40});
    r2.enqueue({"Koloski", 12, "BiP", 60});
    r = preuredi(r1, r2);
        r.print();
    return 0;
} 