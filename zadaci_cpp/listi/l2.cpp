/*Да се напишат потребните структури и функции за имплементирање на единечно поврзана
листа и поддршка на функции за креирање на листа со еден елемент, бришење и додавање на
елементи на почеток и крај на листата. Да се напише програма што ќе ги тестира сите фунции. */
#include <iostream>
#include <stdlib.h>
using namespace std;
struct jazol{
    int info;
    jazol *link;
};
struct EPlista{
    jazol *head;
    void init () {
        head=NULL;
    }
    void kreiraj(int el){
        head = new jazol;
        head -> info = el;
        head -> link = NULL;
    }
    void dodadiPrv(int el){
        jazol *pom = new jazol;
        pom -> info = el;
        pom -> link = head;
        head = pom;
    }
    void dodadiPosleden(int el){
        jazol *dvizhi = head ,*pom = new jazol;
        pom -> info = el;
        if ( head == NULL ){
            head = pom;
        } else {
            while ( dvizhi -> link != NULL )
                dvizhi = dvizhi -> link;
            dvizhi -> link = pom;
        }
        pom -> link = NULL;
    }
    void brishiPrv(){
        if (head != NULL){
            if (head -> link == NULL){
                delete head;
                head = NULL;
            } else {
                jazol *pom = head;
                head = head -> link;
                delete pom;
            }
        }
    }
    void brishiPosleden(){
        if (head != NULL){
            if ( head -> link == NULL){
                delete head;
                head = NULL;
            } else {
                jazol *pom = head, *brishi;
                while (pom->link->link != NULL)
                    pom = pom -> link; 
                brishi = pom -> link;
                pom -> link = NULL;
                delete brishi;
            }
        }
    }
    void brishiLista(){
        while (head != NULL)
            brishiPosleden();
    }
    void pechati(){
        cout<<"elementite vo listata se:";
        for (jazol *pom=head; pom!=NULL; pom=pom->link){
            cout<<pom->info<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    EPlista l1;
    l1.init();
    l1.dodadiPrv(1);
    l1.dodadiPosleden(7);
    l1.dodadiPosleden(8);
    l1.brishiPrv();
    cout << "Prviot jazol vo listata ima info pole " << l1.head->info << endl;
    l1.pechati();
    EPlista l2;
    l2.kreiraj(2);
    l2.dodadiPosleden(4);
    l2.dodadiPosleden(5);
    l2.brishiPosleden();
    l2.pechati();
    l1.brishiLista();
    l2.brishiLista();
    l1.pechati();
    l2.pechati();
    return 0;
}
