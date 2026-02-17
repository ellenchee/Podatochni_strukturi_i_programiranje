#include <iostream>
#include <cstring>
using namespace std;
struct jadenje{
    string ime; 
    int cena;
};
class restoran{
protected:
    int njadenja;
    jadenje *jad;
public:
    restoran (int njadejna=0, jadenje *m=NULL){
        this->njadenja=njadejna;
        jad = new jadenje[njadejna];
        for (int i=0; i<njadejna; i++)
            jad[i]=m[i];
    }
    restoran (const restoran &m){
        njadenja = m.njadenja;
        jad = new jadenje[njadenja];
        for (int i=0; i<njadenja; i++)
            jad[i] = m.jad[i];
    }
    ~ restoran () { delete[] jad;}
    restoran &operator+=(jadenje n){
        jadenje *nova= new jadenje[njadenja+1];
        njadenja++;
        for (int i=0; i<njadenja-1; i++)
            nova[i]=jad[i];
        delete[] jad;
        nova[njadenja-1] = n;
        jad = nova;
        return *this; 
    }
    restoran &operator=(const restoran &m){
        if (this==&m) return *this;
        delete [] jad;
        njadenja = m.njadenja;
        for (int i=0; i<njadenja; i++){
            jad[i]=m.jad[i];
        }
        return *this;
    }
    virtual int zarabotka(){
        int zar=0;
        for (int i=0; i<njadenja; i++)
            zar += jad[i].cena;
        return zar;
    }
    virtual void pechati(){
        cout<<"broj na jadenja: "<<njadenja<<endl;
        for (int i=0; i<njadenja; i++){
            cout<<"ime: "<<jad[i].ime<<". cena: "<<jad[i].cena<<endl;
        }
    }
};
class brzahrana : public restoran {
private:
    bool dostava;
public:
    brzahrana (bool dost=true, int brjad=0, jadenje *j=NULL) : restoran(brjad, j), dostava(dost){}
    ~brzahrana(){}
    virtual int zarabotka(){
        int zar = restoran::zarabotka();
        if (dostava) zar *= 1.5;
        return zar;
    }
    void pechati(){
        cout<<"restoran za brza hrana koj"<<(dostava ? "" : "ne" )<<" vrshi dostava"<<endl;
        restoran::pechati();
        cout<<"zarabotka: "<<zarabotka()<<endl;
    }
};
class elitni : public restoran{
private:
    int denovi;
public:
    elitni (int den=0, int brjad=0, jadenje *j=NULL) : restoran(brjad, j), denovi(den){}
    ~ elitni () {}
    virtual int zarabotka(){
        int zar = restoran::zarabotka();
        zar += (zar*denovi*0.2);
        return zar;
    }
    void pechati(){
        cout<<"eliten restoran koj pravi proslavi "<<denovi<<" dena od nedelata"<<endl;
        restoran::pechati();
        cout<<"ima zarabotka: "<<zarabotka()<<endl;
    }
};
void pomala(restoran *n, restoran *m){
    if (n->zarabotka() > m->zarabotka()) m->pechati();
    else n->pechati();
}