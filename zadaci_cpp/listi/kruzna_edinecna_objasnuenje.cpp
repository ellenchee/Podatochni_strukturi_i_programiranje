#include <iostream>
#include <stdlib.h>
using namespace std;
struct jazol{       //definicija na struktura jazol
    int info;       //ja chuva vrednosta na jazolot
    jazol *link;    //pokazuva kon sledniot element vo listata
};  

struct KruznaLista                  //def. kruzna lista (posledniot element ne pokazuva kon null tuku pokazuva kon prviot)
{ jazol *head;                      //покажувач кон првиот јазол
jazol *end;                         //покажувач кон последниот јазол
int brojelementi;
void init() {
    head=end=NULL; 
    brojelementi=0;
};
    void kreirajLista(int nov);
    void dodadiPrv(int prv);
    void dodadiPosleden(int posleden);
    void pechatiLista();
    void brishiPrv();
    void brishiPosleden();
    void brishiLista();
};
void KruznaLista:: kreirajLista(int nov){               //povik vo main:
    jazol *pom = new jazol;                             //KruznaLista L1;
    pom->info = nov;                                    //L1.init();
    pom->link = pom;                                    //L1.kreirajLista(5);
    end = head = pom;
    brojelementi = 1;
}
void KruznaLista::dodadiPrv(int prv)                    //dodavanje na elementi na pochetokot
{
    jazol *pom = new jazol;
    pom->info = prv;
    if (head == NULL)       //ako listata ne sodrzhi elementi
    {
        pom->link = pom;    //jazolot pokazhuva sam kon sebe
        end = head = pom;
    }
    else
    {
        pom->link = head;
        head = pom;
        end->link = head;
    }
    brojelementi++;
}
void KruznaLista::dodadiPosleden (int posleden)             //dodavanje na elementi na krajot
{
    jazol *pom = new jazol;
    pom->info = posleden;
    if (head == NULL)
        //ako listata ne sodrzhi elementi
        {
            pom->link = pom; //jazolot pokazhuva sam kon sebe
            end = head = pom;
        }
    else
        {
            end->link = pom;
            end = pom;
            end->link = head;
        }
    brojelementi++;
}
void KruznaLista::pechatiLista(){                   //pechatenje na kruzhna lista
    jazol *pom = head;
    cout << "Elementite vo listata se: ";
        if (head == NULL) cout <<"Listata e prazna";
            else
            {
                cout << pom->info << '\t';
                pom = pom->link;
                for ( ; pom != head; pom = pom->link)
                cout << pom->info << '\t';
                cout << endl;
            }
}
//brishenje na posleden element na listata
void KruznaLista::brishiPosleden()
{
    if(head->link == head)
        {
        delete head;
        head =end = NULL;
        }
    if(head != NULL)
        {
            jazol *pom = head;
            while (pom->link!= end)            //stop na pretposleden jazol
                pom = pom->link;               //postavi na posleden jazol
                pom->link=head;                //pretposeleden jazol go povrzuvame so prviot
                delete end;                    //osloboduvanje memorija
                end=pom;                       //pretposeleden jazol e end
        }
    brojelementi--;
}
//brishenje na listata
void KruznaLista::brishiLista() {
    while (head != NULL)
    brishiPosleden();
    brojelementi=0;
}
//brishenje na prviot element vo listata
void KruznaLista::brishiPrv()
{
    if(head->link == head)
    {
        delete head;
        head =end= NULL;
    }
    if(head!= NULL)
    {
        end->link = head->link;         //krajot na listata pokazhuva kon vtoriot jazol
        delete head;                    //osloboduvame memorija za prviot jazol
        head = end->link;               //pochetok stanuva vtoriot jazol
    }
    brojelementi--;
}