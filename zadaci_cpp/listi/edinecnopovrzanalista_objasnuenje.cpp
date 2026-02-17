/*1. Да се напишат потребните структури и функции за имплементирање на единечно поврзана
листа и поддршка на функции за креирање на листа со еден елемент, бришење и додавање на
елементи на почеток и крај на листата. Да се напише програма што ќе ги тестира сите фунции. */
#include <iostream>
#include <stdlib.h>
using namespace std;
struct jazol{       //definicija na struktura jazol
    int info;       //ja chuva vrednosta na jazolot
    jazol *link;    //pokazuva kon sledniot element vo listata
};
struct eplista{
    jazol *head;            //adresa na prviot jazol vo listata
    void init () {          //inicijalizacija na listata
        head=NULL;          //head go postavuvame na null shto znaci deka listata e prazna
    }
    void kreirajLista(int el) {             //kreiranje na lista so eden element
        head = new jazol;                   //dinamicki sozdava nov jazol
        head->info = el;                    //go postavuva info na el (vrednost vnesena od korisnikot)
        head->link = NULL;                  //go postavuva link na null bidejkji toa e edinstveniot element vo listata
    }
    void dodadiPrv(int el) {                    //dodavanje elementi na pochetok                        //primer
        jazol *pom = new jazol;                 //kreira nov jazol (pom)                                //Ако листата е 7 → 8 → NULL, 
        pom->info = el;                         //go postavuva info na el                               //повикување dodadiPrv(5) ќе ја направи:
        pom->link = head;                       //noviot jazol pokazuva na stariot head                 //5 → 7 → 8 → NULL.
        head = pom;                             //head sega pokazuva na noviot jazol    
    }
    void dodadiPosleden(int el) {                       //dodavanje elementi na krajot
    jazol *dvizhi = head, *pom = new jazol;             //ako listata e prazna head=pom
    pom->info = el;
    if (head == NULL)
        head = pom;
    else {
        while (dvizhi->link != NULL)                    //ako ima elementi se dvizi do posledniot jazol - dvizhi->link != NULL
            dvizhi = dvizhi->link;
        dvizhi->link = pom;                             //go povrzuva posledniot jazol so prviot
    }
    }
    void brishiPrv() {                                  //brishenje na prviot element
        if (head != NULL) {                             //ako listata e prazna ne pravi nishto
            if (head->link == NULL) {
                delete head;                            //ako ima samo eden element go brishe head i go postavuva na null
                head = NULL;
            } 
            else{
                jazol *pom = head;
                head = head->link;                      //ako ima povekje elementi se pomestuva head na sledniot jazol i se brishe stariot 
                delete pom;
                }
        }
    }
    void brishiPosleden() {                             //go brishe posledniot element
        if (head != NULL) {                             //ako listata e prazna ne pravi nishto
            if (head->link == NULL) {
                delete head;                            //ako ima samo eden element go brishe head
                head = NULL;
            } else {
                jazol *pom = head, *brishi;
                while (pom->link->link != NULL)         //ako ima povekje elementi se dvizi do predposledniot, i go brishe posledniot 
                pom = pom->link;
                brishi = pom->link;
                pom->link = NULL;
                delete brishi;
                    }
            }
    }
    void pechatiLista() {                                           //pechatenje na listata
        cout << "Elementite vo listata se: ";
        for (jazol *pom = head; pom != NULL; pom = pom->link)       //se dvizi niz listata i gi pechati info vrednostite
            cout << pom->info << '\t';
        cout << endl;
    }
    void brishiLista() {                   //ja brishe listata pocnuvajkji od brishiposleden se dodeka head ne stane null
        while (head != NULL)
            brishiPosleden();
    }
    //.
    int list_length(){                     //dolzina na lista
        int n = 0;
        jazol *pom = head;
        while(pom!=NULL){
            pom = pom->link;
            n++;
        }
        return n;
    }
    //vmetnuvanje na jazol posle daden jazol
    void insert_inside(jazol *j, int data)
    {
        jazol *pom= new jazol;
        pom->info = data;
        pom->link = j->link;
        j->link = pom;
    }
    //brishenje na jazol posle daden jazol
    void delete_after(jazol *ja)
    {
        if (ja->link == NULL) return;
        jazol *tmp = ja->link; //tmp е следбеник
        ja->link = tmp->link;
        delete tmp;
    }

};
// spojuvanje na dve identicni listi so rekurzija
void spojuvanje(jazol *a, jazol *b) {
    if ((a!= NULL)&&(b!= NULL))
        {
            if (a->link== NULL)
            a->link = b;
            else spojuvanje(a->link, b);
        }
        else cout<<"Ili prvata ili vtorata niza se NULL";
}
    