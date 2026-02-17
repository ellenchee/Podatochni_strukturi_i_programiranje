/*Да се напише програма во која ќе се работи со магацини. Еден магацин се состои од повеќе
елементи. Во елементите основен податочен тип е цел број. Треба да се направи промена на
насоката на броевите во магацинот помеѓу два елементи со вредност нула. Да се претпостави
дека во влезниот магацин секогаш има две нули и помеѓу нив секогаш има елементи. Во
програмата е дозволена употреба на дополнителни магацини. Да се дефинира структурата на
еден магацин со основен елемент во кој има цел број. Да се дефинираат потребните функции за
правилна работа на магацинот- иницијализација, додавање нова вредност во магацинот,
повлекување постоечка вредност од магацинот, читање на првата вредност во магацинот,
проверка дали магацинот е полн и проверка дали магацинот е празен. Употребата на низи или
редови не е дозволена.
Пример:
Во магацинот се чуваат следните
податоци:
1
3
5
0
3
4
5
6
0
1
3
По промената магацинот изгледа
вака:
1
3
5
0
6
5
4
3
0
1
3*/
#include <iostream>
using namespace std;
#define MAX 20
struct element{
    int info;
};
struct magacin{
    element niza[MAX];
    int top;
    void init(){
        top=-1;
    }
    void underflow(){
        cout<<"underflow"<<endl;
        exit -1;
    }
    void overflow(){
        cout<<"overflow"<<endl;
        exit -1;
    }
    bool iEmp(){
        return top==-1;
    }
    bool iFul(){
        return top==(MAX-1);
    }
    void push(int e){
        if (iFul()) overflow();
        niza[++top].info=e;
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
void proveri(magacin& mag)
{
    magacin pom1, pom2, pom3;
    pom1.init();
    pom2.init();
    pom3.init();
    int izvadena_vrednost = 1;
    while (izvadena_vrednost!=0)
    {
        izvadena_vrednost=mag.pop().info;
        pom1.push(izvadena_vrednost);    
        if (izvadena_vrednost==0)
        pom1.pop();
    }
    izvadena_vrednost=1;
    while (izvadena_vrednost!=0){
        izvadena_vrednost=mag.pop().info;
        pom2.push(izvadena_vrednost);
        if (izvadena_vrednost==0)
        pom2.pop();
    }
    while (!pom2.iEmp()){
        izvadena_vrednost=pom2.pop().info;
        pom3.push(izvadena_vrednost);
    }
    mag.push(0);
    while (!pom3.iEmp()){
        izvadena_vrednost=pom3.pop().info;
        mag.push(izvadena_vrednost);
    }
    mag.push(0);
    while (!pom1.iEmp()){
        izvadena_vrednost=pom1.pop().info;
        mag.push(izvadena_vrednost);
    }
    while (!mag.iEmp()){
        cout<<mag.pop().info<<endl;
    }
}
int main()
{
    magacin mag;
    mag.init();
    int  a[11] = { 1,3,5,0,3,4,5,6,0,1,3 };
    for (int i=0; i<11; i++){
        mag.push(a[i]);
    }
    while (!mag.iEmp()){
        cout<<mag.pop().info<<endl;
    }
    for (int i=0; i<11; i++){
        mag.push(a[i]);
    }
    cout<<endl;
    proveri (mag);
    return 0;
}