/*2. Од тастатура се внесуваат N букви. Од внесените букви буквата ‘X’ се појавува точно два пати. Таа
буква го означува почетокот и крајот на секвенцата од букви кои треба да се повторат уште еднаш.
Ваша задача е на екран да ја прикажете конечната секвенца од сите внесени букви, така што делот кој
треба да се повторува (од првото до второто појавување на буквата ‘X’) ќе го прикажете уште еднаш, но
во обратен редослед од оној во кој се јавува во влезната секвенца.
Забелешка: дозволено е користење само на редови и магацини, не смее да се користат низи.
Пример: Влезна секвенца: A K M X V W Q X D P.
 Излезна секвенца: A K M X V W Q X X Q W V X D P */\
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#define MAX 50
struct element {
    char info;
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
        return (rear==(MAX-1));
    }
    void enqueue(element e){
        if (iFul()) overflow();
        niza[++rear]=e;
    }
    element dequeue (){
        if (iEmp()) underflow();
        element pom=niza[front];
        for (int i=front; i<rear; i++)
            niza[i]=niza[i+1];
            rear--;
        return pom;
    }
    element peek(){
        if(iEmp()) underflow();
        return niza[front];
    }
};
struct magacin{
    element niza[MAX];
    int top;
    void init(){
        top=-1;
    }
    void overflow(){
        cout<<"overflow"<<endl; exit (-1);
    }
    void underflow(){
        cout<<"underflow"<<endl; exit (-1);
    }
    bool iFul(){
        return (top==MAX-1);
    }
    bool iEmp(){
        return top==(-1);
    }
    void push (element e){
        if (iFul()) overflow();
        niza[++top]=e;
    }
    element pop(){
        if (iEmp()) underflow();
        return niza[top--];
    }
    element peek(){
        if (iEmp()) underflow();
        return niza[top];
    }
};
int main()
{
    queue red;
    red.init();
    element e;
    char bukva;
    cout<<"vnesuvajte bukvi, za kraj vnesete .";
    while (true){
        cin>>bukva;
        if (bukva == '.') break;
        else continue;
        e.info=bukva;
        red.enqueue(e);
    }
    queue konecen; 
    konecen.init();
    magacin prevrti;
    prevrti.init();
    while (!red.iEmp()){
        element pom=red.dequeue();
        if (pom.info != 'X' )
            konecen.enqueue(pom);
        else {
            konecen.enqueue(pom);
            prevrti.push(pom);
            do {
                pom=red.dequeue();
                konecen.enqueue(pom);
                prevrti.push(pom);
            } while (pom.info!='X');
            while (!prevrti.iEmp()){
                konecen.enqueue(prevrti.pop());
            }
        }
    }
    while (!konecen.iEmp()){
        cout<<konecen.dequeue().info<<", ";
    }
    return 0;
}