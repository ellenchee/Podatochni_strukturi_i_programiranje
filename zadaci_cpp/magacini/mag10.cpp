/*Задача 2.4: Работа со знаци и букви во магацин
Да се напише функција која како аргументи добива магацин и буква (знак). Функцијата треба да
го промени магацинот така што од магацинот ќе го отфрли првото појавување на буква гледано
од врвот на магацинот (последниот елемент од врвот на магацинот), а сите останати
појавувања ќе се занемарат. Доколку буквата внесена од тастатура не биде пронајдена во
магацинот, магацинот останува непроменет. Дополнително, функцијата треба да го одреди
индексот на кој се наоѓа отфрлениот елемент, гледајќи од дното на магацинот. Ако буквата не е
пронајдена во магацинот - индексот кој треба да се врати е -1.
Да се напише програма за тестирање на функцијата и листата.
Пример:
Пред промената:
Магацинот е:
|а|
|b|
|v|
|g|
|d|
|t|
|s|
|y| и внесена буква t
После промената:
Магацинот ќе биде:
|a|
|b|
|v|
|g|
|d|
|s|
|y*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define max 10
struct stack{
    int top;
    char niza[max];
    void init (){
        top=-1;
    }
    void underflow(){
        cout<<"underflow"<<endl;
        return exit (-1);
    }
    void overflow(){
        cout<<"overflow"<<endl;
        return exit (-1);
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==max-1;
    }
    void push(char c){
        if (isFull()) overflow();
        niza[++top]=c;
    }
    char pop(){
        if (isEmpty()) underflow();
        return niza[top--];
    }
    char peek(){
        if (isEmpty()) underflow();
        return niza[top];
    }
};
int promeni (stack m, char t){
    stack h1;
    int i=1, poz=0;
    bool najden=0;
    h1.init();
    while (!m.isEmpty()){
        h1.push(m.pop());
    }
    while (!h1.isEmpty()){
        if (h1.peek()!=t){
            m.push(h1.pop()); 
            i++;
        }else{
            if (!najden){
            poz=i;
            najden = true;
            h1.pop();            
            }else{
                m.push(h1.pop());
            }
        }
    }
    if(najden) return poz-1;
    else return (-1);
}
int main() {
    stack m1;
    m1.init();
    int pozicija;
    m1.push('y');
    m1.push('s');
    m1.push('t');
    m1.push('d');
    m1.push('g');
    m1.push('v');
    m1.push('b');
    m1.push('a'); //a b v g d t s y t-2
    pozicija = promeni(m1, 't');
    while (!m1.isEmpty()) cout<<m1.pop()<<endl;
    cout << "Pozicijata na koja se najduva bukvata t e " << pozicija << endl;
    return 0;
}