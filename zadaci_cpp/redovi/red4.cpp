/*4. Да се напише програма во која ќе се работи со редови. Еден ред се состои од повеќе елементи.
Во елементите основен податочен тип е цел број. Во првиот ред се чуваат разместени елементи.
Во вториот ред се чуваат позициите на елементите во кои треба да биде првиот ред. Во излезниот
ред, елементите од првиот ред треба да се наредат според редоследот даден во вториот ред. Во
програмата е дозволена употреба на дополнителни редови. Да се дефинира структурата на еден
ред со основни елементи во кој има цели броеви. Да се дефинираат и функциите потребни за
правилна работа на редот- додавање вредност, повлекување вредност, читање на првата вредност
во редот. Употребата на низи или магацини не е дозволена.
Влезни редови
Прв ред
1 2 3 4 5 6 <- позиции во редот
5 8 3 1 4 9 <- вредности на елементите во редот
Втор ред (новите позиции на првиот ред)
1 6 2 4 3 5
Излезен ред - после аплицирање на позициите од вториот ред
5 9 8 1 3 4
Решение: */
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#define MAX 50
struct element {
    int info;
};
struct queue{
    element niza[MAX];
    int front, rear;
    void init(){
        front=0; rear=-1;
    }
    void overflow(){
        cout<<"overflow"<<endl; exit (-1);
    }
    void underflow(){
        cout<<"underflow"<<endl; exit (-1);
    }
    bool iEmp(){
        return (rear==-1);
    }
    bool iFul(){
        return (rear==MAX-1);
    }
    void enqueue(element e){
        if (iFul()) overflow();
        niza[++rear]=e;
    }
    element dequeue(){
        if (iEmp()) underflow();
        element pom=niza[front];
        for (int i=front; i<front; i++)
            niza[i]=niza[i+1];
            rear--;
        return pom;
    }
    element peek(){
        if (iEmp()) underflow();
        return niza[front];
    }
};
element pozicija(queue red, int poz){
    while (--poz) {
        red.dequeue();
    }
    return red.peek();
}
void proveri (queue& red1, queue& red2){
    queue nov;
    nov.init();
    while (!red2.iEmp()){
        nov.enqueue(pozicija(red1, red2.dequeue().info));
    }
    while (!nov.iEmp()){
        cout<<nov.dequeue().info<<" ";
    }
    cout<<endl;
}
int main()
{
    queue red1, red2;
    red1.init();
    red2.init();
    int a[6]= { 5,8,3,1,4,9 };
    for (int i=0; i<6; i++) {
        element e;
        e.info=a[i];
        red1.enqueue(e);
    }
    while (!red1.iEmp()){
        cout<<red1.dequeue().info<<" ";
    }
    for (int i=0; i<6; i++){
        element e; 
        e.info=a[i];
        red1.enqueue(e);
    }
    cout<<endl;
    int b[6] = { 1,6,2,4,3,5 };
    for (int i=0; i<6; i++){
        element e;
        e.info=b[i];
        red2.enqueue(e);
    }
    proveri (red1, red2);
}