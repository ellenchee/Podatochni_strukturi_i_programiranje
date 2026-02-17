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
        head = NULL;
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
        jazol *pom = new jazol, *dvizhi = head; 
        pom -> info = e;
        if (head==NULL){
            head = pom;
        } else {
            while (dvizhi->link!=NULL)
                dvizhi=dvizhi->link;
            dvizhi -> link = pom;
        }
        pom -> link = NULL;
    }
    void brishiPrv(){
        if (head!=NULL){
            if(head->link=NULL){
                delete head;
                head = NULL;
            }else {
                jazol *pom = head;
                head = head -> link;
                delete pom;
            }
        }
    }
    void brishiPosleden(){
        if (head!=NULL){
            if (head->link==NULL){
                delete head;
                head = NULL;
            } else {
                jazol *brishi, *pom = head;
                while (pom->link->link!=NULL)
                    pom = pom -> link; 
                brishi = pom -> link;
                pom -> link = NULL;
                delete brishi;
            }
        }
    }
    void brishiLista(){
        while (head!=NULL) brishiPosleden();
    }
    void pechati(){
        cout<<"elementite na listata se: ";
        for (jazol *pom=head; pom!=NULL; pom=pom->link)
            cout<<pom->info<<" ";
        cout<<endl;
    }
};