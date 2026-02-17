//obopshtuvanje i ogranichuvanje / chasovnik i dziden
#include <iostream>
using namespace std;
class Chasovnik{
protected:
    bool akt;
    int cenamat;
public:
    Chasovnik (bool akt = false, int cenamat = 3500) {
        this->akt=akt;
        this->cenamat=cenamat;
    }
    int cena(){
        if (akt) return cenamat + 10000;
        return cenamat;
    }
};
class dziden : public Chasovnik{
private:   
    bool pticka;
public: 
    dziden (bool aktd = false , int cenamatd = 3500, bool picka = false ) : Chasovnik (aktd, cenamatd), pticka(picka) {}
    int cena(){
        int oscena = Chasovnik::cena();
        if (pticka) return oscena+1000;  
        return oscena;
    }
    bool imaPticka(){
        return pticka;
    }
};
void pechaticenaref(Chasovnik &rc){
    cout<<rc.cena()<<endl;
}
void pechaticenaobicen(Chasovnik ob){
    cout<<ob.cena()<<endl;
}
void pechaticenadziden(dziden &dz){ //dze;)
    cout<<dz.cena()<<endl;
}
