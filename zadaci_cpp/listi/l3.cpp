/*Да се напише функција која како аргумент добива веќе пополнета единечно поврзана листа
чии јазли содржат цели броеви, а треба да формира две нови единечно поврзани листи. Во
првата листа ќе се сместат јазлите кои носат информација за непарни броеви, додека во
втората листа ќе се сместат јазлите кои носат информација за парните броеви.
Забелешка: Во двете резултантни листи да се врши одново алоцирање на меморија за новите
јазли. Искористете ги структурите и функциите за работа со единечно поврзани листи од
претходната задача.*/
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
        jazol *pom = new jazol, *dvizhi = head ;
        pom -> info = el;
        if (head==NULL){
            head = pom;
        } else {
            while (dvizhi -> link != NULL)
                dvizhi = dvizhi -> link;
            dvizhi -> link = pom;
        }
        pom -> link = NULL;
    }
    void brishiPrv(){
        if (head!=NULL){
            if (head -> link == NULL) {
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
        if (head!=NULL){
            if ( head -> link == NULL){
                delete head;
                head = NULL;
            }else{
                jazol *pom = head, *brishi;
                while (pom->link->link!=NULL)
                    pom = pom -> link;
                brishi = pom -> link;
                pom -> link = NULL;
                delete brishi;
            }
        }
    }
    void brishiLista(){
        while (head!=NULL)
            brishiPosleden();
    }
    void pechatiLista(){
        cout<<"elementite vo listata se: ";
        for ( jazol *pom=head; pom!=NULL; pom=pom->link)
            cout<<pom->info<<" ";
        cout<<endl;
    }
};
void podeliSporedParnost (EPlista &l){
    EPlista a, b; 
    a.init();
    b.init();
    for (jazol *pom = l.head; pom!=NULL; pom=pom->link){
        if (pom->info%2==0) a.dodadiPosleden(pom->info);
        else b.dodadiPosleden(pom->info);
    } 
    cout<<"parni:";
    a.pechatiLista();
    cout<<"neparni: ";
    b.pechatiLista();
}
int main() {
    EPlista Lista;
     Lista.kreiraj(1);
    for (int i = 2; i < 7; i++)
        Lista.dodadiPosleden(i);
    Lista.pechatiLista();
    podeliSporedParnost(Lista);
    Lista.brishiLista();
return 0;
} 
