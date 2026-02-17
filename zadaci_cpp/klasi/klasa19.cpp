#include <iostream>
using namespace std;
class zivotni{
protected:
    bool prostorija;
public: 
    zivotni (bool prostorija = false ){ //false mala true golema
        this->prostorija=prostorija;
    }
    virtual ~ zivotni () {}
    virtual int cena(){
        int cena;
        if (prostorija) cena = 40000;
        else cena = 6000;
        return cena;
    }
    bool operator>(zivotni &a){
        if (cena() > a.cena()) return 1;
        return 0;
    }
    friend istream &operator>>(istream &in, zivotni &a){
        cout<<"vnesi prostorija za chuvanje na zivotni: "<<endl;
        in>>a.prostorija;
        return in;
    }
    zivotni &operator++(){
        if (prostorija=false) prostorija=true;
        return *this;
    }
    virtual void pechati(){
        cout<<"tip na soba: "<<(prostorija ? "golema" : "mala")<<endl;
        cout<<"cena: "<<cena()<<endl;
    }
};
class cicach : public zivotni{
protected: 
    int ed;
public:
    cicach (int ed=0, bool prost=false) : zivotni(prost){
        this->ed=ed;
    }
    virtual ~ cicach () {}
    virtual int cena(){
        int oscena = zivotni::cena();
        int pom = ed;
        if (pom > 20)
            pom=20;
        oscena -= 0.05 * (pom-1) * oscena;
        return oscena;
    }
    void pechati(){
        cout<<"cicach koj zivee vo grupa od "<<ed<<" edinki"<<endl;
        zivotni::pechati();
    }
    bool operator>(cicach &a){
        if (cena() > a.cena()) return 1;
        return 0;
    }
    cicach &operator++(){
        if (prostorija) prostorija=true;
        return *this;
    }
    friend istream &operator>>(istream &in, cicach &a){
        cout<<"vnesi kolku edinki ima: "<<endl;
        in>>a.ed;
        cout<<"vensete tip na prostorija za chuvanje: (1 golema, 0 mala)"<<endl;
        in>>a.prostorija;
        return in;
    }
};
class primat : public cicach{
private:
    bool rekviziti;
public:
    primat (int edn=0, bool rekviziti=false) : cicach(edn){
        this->rekviziti=rekviziti;
    }
    virtual int cena(){
        int oscena = cicach::cena();
        if (rekviziti) oscena += 20000;
        return oscena;
    }
    bool operator>(primat &a){
        if (cena() > a.cena()) return 1;
        return 0;
    }
    primat operator++(){
        if (prostorija) prostorija=true;
        return *this;
    }
    friend istream &operator>>(istream &in, primat &a){
        cout<<"dali se potrebni rekviziti: "<<endl;
        in>>a.rekviziti;
        cout<<"so kolku edinki"<<endl;
        in>>a.ed;
        cout<<"vo kakva prostorija e"<<endl;
        in>>a.prostorija;
        return in;
    }
    void pechati(){
        cicach::pechati();
        cout<<"potrebni "<<(rekviziti? "se" : "ne se")<<" rekviziti"<<endl;
    }
};
void najevtino(zivotni **n){
    zivotni *najevtino = n[0];
    for (int i=1; n[i]!=NULL; i++){
        if (najevtino->cena() > n[i]->cena())
            najevtino = n[i];
    }
    najevtino->pechati();
}