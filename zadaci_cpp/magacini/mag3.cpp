/*Да се напише функција која како аргументи добива магацин со веќе внесени елементи и еден
цел број. Во магацинот да се најде последното појавување на елементот кој има вредност
еднаква со вториот аргумент. Ако постои елемент со таква вредност, истиот да се отстрани од
магацинот и да се врати позицијата на која е најден (броејки од горе надолу). Доколку не се
најде елемент со таква вредност, функцијата да врати вредност нула. Да се напише главна
програма во која ќе се внесат вредностите на еден магацин и број за пребарување и ќе се
повика функцијата.
Забелешка: Како дополнителна структура може да се користи само еден магацин. Да се
користат операциите за додавање и отстранување на елементи од магацин.
Пример:
Пред промена:
Магацинот е:
|10|
|2|
|10|
|7|
|10|
|10|
|9| број = 10
После промената:
Магацинот ќе биде:
|10|
|2|
|10|
|7|
|10|
|9|
Позиција е 6
Решение:*/
#include <iostream>
#include <string>
using namespace std;
int const MAX=10;
struct magacin{
    int niza[MAX];
    int top;
    void init(){
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
    bool iEmp(){
        return top==-1;
    }
    bool iFull(){
        return top==(MAX-1);
    }
    void push(int e){
        if(iFull()) overflow();
        niza[++top]=e;
    }
    int pop(){
        if(iEmp()) underflow();
        return niza[top--];
    }
    int peek(){
        if(iEmp()) underflow();
        return niza[top];
    }
};
int funkcija(magacin &m, int n){
    magacin pom; int poz=0;
    pom.init();
    while (!m.iEmp()){
        pom.push(m.pop());
    }
    while (!pom.iEmp()){
        int element=pom.peek();
        if (element==n && poz==0 ){
            poz=pom.top+1;
        }
        else {
            m.push(element);
        }
        pom.pop();
    }
    return poz;
}
int main()
{
    magacin m1;
    int broj=10;
    m1.init();
    m1.push(9);
    m1.push(10);
    m1.push(10);
    m1.push(7);
    m1.push(10);
    m1.push(2);
    m1.push(10);
    int p=funkcija(m1, broj);
    if (p==0){
        cout<<"elementot ne e pronajden."<<endl;
    }
    else {
        cout<<"elementot e na pozicija "<<p<<endl;
    }
    while (!m1.iEmp()){
        cout<<m1.pop()<<endl;
    }
    return 0;
}
