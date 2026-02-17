//primer polimorfizam so virtuelna funkcija i apstraktna klasa
#include <iostream>
using namespace std;
class objekt{
private: 
    string ime; 
    int tezina;
public:
    objekt (string ime="", int tezina=0){
        this->ime=ime;
        this->tezina=tezina;
    }
    virtual void pechati(){
        cout<<"ime: "<<ime<<endl;
        cout<<"tezina: "<<tezina<<endl;
    }
    virtual float brzina() = 0;
};
float objekt :: brzina(){
    float brzinap = 30 - 30 * 0.05 * tezina;
    return brzinap;
}
class kajce : public objekt{
private:
    bool penta;
public:
    kajce (string imek = "", int tezinak = 0 , bool pentak = false) : objekt(imek, tezinak), penta(pentak) {}
    virtual void pechati(){
        cout<<"tip na ploven objekt: kajce"<<endl;
        objekt::pechati();
        cout<<"penta: "<<(penta? "ima" : "nema");
        cout<<"brzina: "<<brzina()<<endl;
    }
    virtual float brzina (){
        float brz = objekt::brzina();
        brz += int(penta) *0.4;
        return brz;
    }
    
};