/*5. Да се реализира лото игра со помош на магацин. За зачувување на учесниците се користи
магацин, така што секој од елементите на магацинот го содржи името и презимето на
учесникот во играта, како и низа од 7 броеви кои корисникот ги внел во своето добитно ливче.
Во главната програма се дадени и магацинот учесници и добитното ливче. Да се напише
функција која ќе ги измине сите учесници во лото играта, од нив во посебен магацин ќе ги
издвои оние кои се добитници на лото 7 (сите 7 броеви на корисникот се совпаѓаат со
добитната комбинација) и добиениот магацин од добитници, кој ќе биде проследен во главната
функција за печатење.
Пример:
Учесници:
Петко Петковски 9, 23, 13, 25, 32, 21, 11
Милан Милановски 32, 25, 13, 21, 12, 10, 5
Ангела Ангелковска 9, 25, 13, 11, 32, 21, 23
Стојан Стојановски 23, 11, 17, 9 , 32, 25, 21
Добитна комбинација: 9, 23, 11, 32, 25, 13, 21
Добитници:
Петко Петковски 9, 23, 13, 25, 32, 21, 11
Ангела Ангелковска 9, 25, 13, 11, 32, 21, 23
Решение: */
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define MAX 10
struct element
{
    string imeprezime;
    int livce[7];
};
struct magacin{
    element niza[MAX];
    int top;
    void init(){
        top=-1;
    }
    void overflow(){
        cout<<"overflow"<<endl;
        exit -1;
    }
    void underflow(){
        cout<<"underflow"<<endl;
        exit -1;
    }
    bool iEmp(){
        return (top==-1);
    }
    bool iFul(){
        return (top==MAX-1);
    }
    void push (element e){
        if (iFul()) overflow();
        niza[++top]=e;
    }
    element pop (){
        if (iEmp()) underflow();
        return niza[top--];
    }
    element peek (){
        if (iEmp()) underflow();
        return niza[top];
    }
};
void sedumka(int *dobitna, magacin uchesnici, magacin *dobitnici){
    element uchesnik;
    int countcheck;
    bool elementcheck;
    while (!uchesnici.iEmp())
    {
        countcheck=0;
        uchesnik=uchesnici.pop();
        for (int i=0; i<7; i++)
        {
            elementcheck=false;
            for (int j=0; j<7; j++)
            {
                if (uchesnik.livce[i]==dobitna[j])
                {
                    elementcheck=true;
                }
            }
            if (elementcheck)
            {
                countcheck++;
            }
        }
        if (countcheck==7)
        {
            dobitnici->push(uchesnik);
        }
    }
}
void prezemi (element &e, int niz[])
{
    for (int i=0; i<7; i++){
        e.livce[i]=niz[i];
    }
}
int main ()
{
    magacin uchesnici, dobitnici;
    element e;
    int dobitna[7]={9, 23, 11, 32, 25, 13, 21};
    uchesnici.init();
    dobitnici.init();
    e.imeprezime="Petko P";
        int niza1[7]={ 9, 23, 13, 25, 32, 21, 11};
        prezemi(e, niza1);
        uchesnici.push(e);
    e.imeprezime = "Milan Milanovski";
        int niza2[7] = { 32, 25, 13, 21, 12, 10, 5 }; 
        prezemi(e, niza2);
        uchesnici.push(e);
    e.imeprezime = "Angela Angelkovska";
        int niza3[7] = { 9, 25, 13, 11, 32, 21, 23 };
        prezemi(e, niza3);
        uchesnici.push(e);
    e.imeprezime = "Stojan Stojanovski";
        int niza4[7] = { 23, 11, 17, 9, 32, 25, 21 };
        prezemi(e, niza4);
    sedumka(dobitna, uchesnici, &dobitnici);
    while(!dobitnici.iEmp()){
        cout<<dobitnici.pop().imeprezime<<endl;
    }
    return 0;
}
