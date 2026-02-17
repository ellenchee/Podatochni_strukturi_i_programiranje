// laboratorii 9.2
#include <iostream>
using namespace std;
class laboratorija{
protected:
    string ime;
    string institut;
    int brm;
public:
    laboratorija (string ime="", string institut="", int brm=0) {
        this->ime=ime;
        this->institut=institut;
        this->brm=brm;
    }
    void pechati();
    float vrednost();
};
float laboratorija :: vrednost() {
    float cen = 120000;
    cen = cen * (1+0.05*brm);
    return cen;
}
void laboratorija :: pechati(){
    cout<<"ime: "<<ime<<endl;
    cout<<"institut: "<<institut<<endl;
    cout<<"brm: "<<brm<<endl;
}
class slab : public laboratorija{
private:
    int brs;
    int tips[15];
    string naslov[15];
public:
    slab (int brs=0, int *tipss=NULL, string *nasl=NULL, string imes="", string insts="", int brms=0 ) : laboratorija(imes, insts, brms){
        this->brs=brs;
        for (int i=0; i<brs; i++){
            naslov[i] = nasl [i];
            tips [i] = tipss[i];
        }
    }
    void pechati();
    float vrednost();
};
void slab :: pechati(){
    cout<<"tip na laboratorija: softverska laboratorija";
    laboratorija::pechati();
    cout<<"broj na softveri: "<<brs<<endl;
    cout<<"naslov na softverite i tip na licenca: "<<endl;
    for (int i=0; i<brs; i++){
        cout<<naslov[i]<<", "<<(tips[i] ? "licenciran" : "nelicenciran")<<"softver"<<endl;
    }
}
float slab :: vrednost(){
    float cenap = laboratorija::vrednost();
    for (int i=0; i<brs; i++){
        if (tips[i])
            cenap += 5000 * brm;
        else 
            cenap += 5*brm;
    }
    return cenap;
}
class hlab : public laboratorija {
private:
    int tipl;
    int brp;
    int cena[35];
public:
    hlab (int tipl=0, int brp=0, int *cena=0, string imeh="", string insth="", int brsh=0) : laboratorija (imeh, insth, brsh){
        this->tipl=tipl;
        this->brp=brp;
        for (int i=0; i<brp; i++){
            this->cena[i] = cena[i];
        }
    }
    void pechati();
    float vrednost();
};
void hlab :: pechati(){
    cout<<"tip na laboratorija: hardverska laboratorija"<<endl;
    laboratorija::pechati();
    cout<<"tip na hardverska lab: "<<(tipl ? "niskostrujna" : "visokostrujna")<<endl;
    cout<<"broj na parcinja na hardver: "<<brp<<endl; cout<<"nivna cena: "<<endl;
    for (int i=0; i<brp; i++){
        cout<<i+1<<". "<<cena[i]<<endl;
    }
}
float hlab :: vrednost (){
    float cenap = laboratorija::vrednost();
    if (tipl == 0){
        cenap += 100000;
    }else {
        cenap += 2000;
    }
    for (int i=0; i<brp; i++){
        cenap += cena[i];
    }
    return cenap;
}