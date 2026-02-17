//polimorfizam
#include <iostream>
using namespace std;
class chasovnik{
protected:
    bool ant; 
    int oscena;
public: 
    chasovnik (bool ant = false, int oscena = 3500){
        this->ant=ant;
        this->oscena=oscena;
    }
    virtual int cena(){
        if (ant) return oscena+10000;
        return oscena;
    }
    virtual ~chasovnik(){}
};
class dziden : public chasovnik{
private: 
    bool pticka;
public: 
    dziden (bool antd = false , int oscenad = 3500, bool ptickad = false ) : chasovnik(antd, oscenad), pticka(ptickad){}
    virtual int cena(){
        int cena = chasovnik::cena();
        if (pticka) return cena+1000;
        return cena;
    }
    virtual int ekstra(int extra){
        int cenaa = cena();
        return cenaa+extra;
    }
    bool imapticka(){
        return pticka;
    }
};
void pechaticenaref(chasovnik &c){
    cout<<c.cena()<<endl;
}
void pechaticenaob(chasovnik c){
    cout<<c.cena()<<endl;
}
void pechaticenadziden(dziden &c){
    cout<<c.cena()<<endl;
}