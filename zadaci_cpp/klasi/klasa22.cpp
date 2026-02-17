//6.3 prodavnica za knigi
#include <iostream>
#include <cstring>
using namespace std;
class ProdavnicaZaKnigi{
private:
    char ime[44];
    string adresa;
    int godina;
    int vkupno;
    int stari;
    float prodazba;
    int nerabotni;
public:
    ProdavnicaZaKnigi(char *im=NULL, string adresa="",int godini=0,
    int vkupno=0, int stari=0, float prodazba=0.0, int nerabotni=0){
        strncpy(ime, im, 43);
        ime[44]='\0';
        this->adresa=adresa;
        this->godina=godini;
        this->vkupno=vkupno;
        this->stari=stari;
        this->prodazba=prodazba;
        this->nerabotni=nerabotni;
    }
    ProdavnicaZaKnigi(ProdavnicaZaKnigi &p){
        strncpy(this->ime, p.ime, 43); ime[44]='\0';
        adresa=p.adresa;
        godina=p.godina;
        vkupno=p.vkupno;
        stari=p.stari;
        prodazba=p.prodazba;
        nerabotni=p.nerabotni;
    }
    ~ ProdavnicaZaKnigi () {}
    char *getIme() {return ime;}
    string getAdress() {return adresa;}
    int getGod() {return godina;}
    int getVkp() {return vkupno;}
    int getStari() {return stari;}
    float getProd() {return prodazba;}
    int getNer() {return nerabotni;}
};
class Lanec{
private:
    string ime;
    string brend;
    string zemja;
    ProdavnicaZaKnigi prod[20];
    
};