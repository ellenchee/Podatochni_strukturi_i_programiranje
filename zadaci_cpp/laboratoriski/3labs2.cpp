/******************************************************************************
Да се напишат потребните структури и функции за работа со двојно поврзана нул 
терминирана скалеста листа. Скалеста листа е двојно поврзана листа чии јазли најпрвин се 
зголемуваат, па се намалуваат. Да се направи глобална функција sortiraj која што ќе ги сортира 
јазлите на скалестата листа. 
Како дел од програмата да се напишат структурата за имплементација на листата заедно со 
функции за креирање на листа, додавање и бришење на елемент од листата, печатење на листата, 
бришење на листата, додавање после јазол (два влезни аргументи: вредноста која се става во 
новиот јазолот и покажувач кон јазол после кој треба да се изврши додавањето). Дополнително 
да се напише главна програма за да се тестираат листата и функциите. 
Пример: 
Влез:  2 <->5<->7<->12<->10<->6<->4<->1 
Излез: 1<->2<->4<->5<->6<->7<->10<->12 
Влез: 20<->17<->14<->8<->3 
Излез: 3<->8<->14<->17<->20
*******************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;
struct jazol{
    int info; 
    jazol *prev;
    jazol *next;
};
struct lista{
    jazol *head;
    jazol *tail;
    void init (){
        head = tail = NULL;
    }
    void kreiraj (int e) {
        head = new jazol;
        head -> info = e;
        head -> prev = NULL;
        head -> next = NULL;    
        tail = head;
    }
    void dodadiPrv(int prv){
        jazol *p = new jazol;
        p -> info = prv;
        p -> prev = NULL; 
        p -> next = head;
        if ( head != NULL) {
            head -> prev = p;
        } else {
            tail = p;
        }
        head=p;
    }
    void dodadiPosleden (int posleden){
        jazol *p = new jazol;
        p -> info = posleden;
        p -> next = NULL;
        p -> prev = tail;
        if ( tail != NULL ){
            tail -> next = p;
        }
        else {
            head=p; 
        }
        tail=p;
    }
    void brishiPrv(){
        if (head==NULL) return;
        jazol *p = head;
        head = head -> next;
        if (head != NULL) {
            head -> prev = NULL;
        } else {
            tail = NULL;
        }
        delete p; 
    }
    void brishiPosleden(){
        if (tail==NULL) return;
        jazol *p = tail; 
        tail = tail -> prev;
        if ( tail != NULL){
            tail -> next == NULL;
        } else {
            head = NULL;
        }
        delete p;
    }
    void brishiJazol(jazol *j){
        if (j==NULL) return;
        if (j==head){
            brishiPrv();
            return;
        }
        if (j==tail){
            brishiPosleden();
            return;
        }
        j->prev->next = j->next;
        j->next->prev = j->prev;
        delete j;
    }
    void brishiLista(){
        while (head!=NULL) brishiPrv();
    }
    void dodadiPosle(jazol *j, int vrednost){
        if ( j==NULL ) return;
        jazol *p = new jazol;
        p -> info = vrednost;
        p -> prev = j;
        p->next = j->next;
        if (j->next != NULL){
            j->next->prev = p;
        } else {
            tail = p;
        }
        j -> next = p; 
    }
    void pechati(){
        jazol *j = head; 
        while ( j!=NULL){
            cout<<j->info;
            if (j->next != NULL){
                cout<<" <-> ";
            }
            j = j -> next;
        }
        cout<<endl;
    }
};
void sortiraj(lista &L){
    if (L.head == NULL || L.head->next == NULL) return;
    for (jazol *i = L.head; i != NULL; i = i->next) {
        jazol *min = i;
        for (jazol *j = i->next; j != NULL; j = j->next) {
            if (j->info < min->info) {
                min = j;
            }
        }
        swap(i->info, min->info);
    }
}
int main ()
{
    lista L;
    L.init();
    int n, element;
    cout<<"vnesi go brojot na elementi vo listata: ";
    cin>>n;
    cout<<"vnesi gi elementite od listata: ";
    for (int i=0; i<n; i++){
        cin>>element;
        if (i==0){
            L.kreiraj(element);
        } else {
            L.dodadiPosleden(element);
        }
    }
    cout<<"lista pred sortiranje: ";
    L.pechati();
    sortiraj(L);
    cout<<"lista posle sortiranje: ";
    L.pechati();
    L.brishiLista();
    return 0;
}