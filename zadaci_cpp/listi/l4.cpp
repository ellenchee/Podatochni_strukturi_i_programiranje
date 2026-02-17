/*3. Нека се дадени две единечно поврзани листи чии јазли се сортирани во растечки редослед.
Да се напише функција која ќе ги спои двете листи во една листа, која треба да е сортирана во
растечки редослед. Во резултантната листа одново се креираат јазли.
Забелешка: претпоставете дека во листите нема дупликати. Искористете ги структурите и
функциите за работа со единечно поврзани листи од Задача 1.*/
#include <iostream>
#include <stdlib.h>
using namespace std;
struct jazol{
    int info;
    jazol *link;
};
struct EPlista{
    jazol *head;
    void init(){
        head=NULL;
    }
    void kreiraj(int e){
        head = new jazol;
        head -> info = e;
        head -> link = NULL;
    }
    void dodadiPrv(int e){
        jazol *pom = new jazol; 
        pom -> info = e;
        pom -> link = head;
        head = pom;
    }
    void dodadiPosleden(int e){
        jazol *pom = new jazol, *dvizhenje=head;
        pom -> info = e;
        if (head==NULL){
            head=pom; 
            pom -> link = NULL;
        }else{
            while (dvizhenje->link!=NULL)
                dvizhenje=dvizhenje->link;
            dvizhenje -> link = pom;
            pom->link=NULL;
        }
    }
    void brishiPrv(){
        if (head!=NULL){
            if (head->link==NULL){
                delete head; head=NULL;
            } else {
            jazol *pom = head;
            head = head -> link;
            delete pom; 
        }
    }}
    void brishiPosleden(){
        if (head!=NULL){
            if (head->link==NULL){
                delete head;
                head = NULL;
            }else{
            jazol *pom = head, *brishi;
            while (pom->link->link!=NULL)
                pom = pom -> link;
            brishi = pom -> link; pom -> link = NULL;
            delete brishi;
        }
    }
    }
    void brishiLista(){
        while (head!=NULL) brishiPosleden();    
    }
    void pechati(){
        //cout<<"elementite na listata se: ";
        for (jazol *pom = head; pom!=NULL; pom=pom->link)
            cout<<pom->info<<" ";
        cout<<endl;
    }
};
EPlista spoiDveListi(EPlista &L1, EPlista &L2)
{
    EPlista L3;
    L3.init(); 
    jazol *pom1 = L1.head;
    jazol *pom2 = L2.head;
    while (pom1 != NULL && pom2 != NULL) {
        if (pom1->info < pom2->info) {
            L3.dodadiPosleden(pom1->info);
            pom1 = pom1->link;
        } else {
            L3.dodadiPosleden(pom2->info);
            pom2 = pom2->link;
        }
    }
    while (pom1 != NULL) {
        L3.dodadiPosleden(pom1->info);
        pom1 = pom1->link;
    }
    while (pom2 != NULL) {
        L3.dodadiPosleden(pom2->info);
        pom2 = pom2->link;
    }
    return L3;
}
int main() {
    EPlista L1, L2, L3;
     L1.kreiraj(2);
     L1.brishiPosleden();
     L1.dodadiPrv(1);
     L1.dodadiPosleden(7);
     L1.dodadiPosleden(8);
     L2.kreiraj(2); 
     L2.dodadiPosleden(4);
    L2.dodadiPosleden(9);
    L1.pechati();
    L2.pechati();
    L3=spoiDveListi(L1, L2);
    L3.pechati();
    L1.brishiLista();
    L2.brishiLista();
    L3.brishiLista();
    return 0;
}
