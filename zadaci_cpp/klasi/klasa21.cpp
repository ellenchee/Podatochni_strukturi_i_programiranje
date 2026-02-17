#include <iostream>
using namespace std;
class smetki{
private:
    int id;
    bool tip;
    int kolicina;
public:
    smetki (int id=0, bool tip=false, int kolicina=0){
        this->id=id;
        this->tip=tip;
        this->kolicina=kolicina;
    }
    int getID() {return id;}
    bool getTip() {return tip;}
    int getK() {return kolicina;}
    void setID (int id) {this->id=id;}
    void setTip (bool tip) {this->tip=tip;}
    void setK (int kolicina) {this->kolicina=kolicina;}
};
class korisnici{
protected:
    int bb;
    smetki *s;
public:
    korisnici(int bb=0, smetki *ss=NULL){
        this->bb=bb;
        ss = new smetki[bb];
        for (int i=0; i<bb; i++)
            s[i]=ss[i];
    }
    korisnici (const korisnici &k){
        bb=k.bb;
        s = new smetki[bb];
        for (int i=0; i<bb; i++)
            s[i] = k.s[i];
    }
    ~ korisnici () {delete [] s;}
    int sredstva(){
        int money =0; 
        for (int i=0; i<bb; i++){
            if (s[i].getTip())
                money += s[i].getK();
            else 
                money += (s[i].getK() *51);
        }
        return money;
    }
    void pechati(){
        cout<<"broj na smetki: "<<bb<<endl;
        for (int i=0; i<bb; i++) {
            cout<<"id: "<<s[i].getID()<<endl;
            cout<<"sredstva: "<<s[i].getK()<<endl;
            cout<<"tip "<<(s[i].getTip()? "denari" : "dolari")<<endl;
        }
        cout<<"vkupna suma: "<<sredstva()<<endl;
    }
    korisnici &operator-=(smetki p){
        smetki *nova = new smetki[bb+1];
        bb++;
        for (int i=0; i<bb-1; i++){
            nova[i] = s[i];
        }
        nova[bb-1]=p;
        delete[] s;
        s = nova;
        return *this;
    }
};
class fizickilica : public korisnici{
private: 
    bool dolg;
public:
    fizickilica (int broj=0, smetki *ss=NULL, bool dolg = false) : korisnici(broj, ss){
        this->dolg=dolg;
    }
    int raspSr(){
        int money=korisnici::sredstva();
        if (dolg == false) money += 1000000;
        return money;
    }
    void pechati(){
        korisnici::pechati();
        cout<<"korisnikot "<<(dolg? "ima" : "nema")<<"dolg;"<<endl;
    }
    ~ fizickilica () {};
};
class kompanija : public korisnici{
private:
    int brv;
    bool plata;
public:
    kompanija (int broj=0, smetki *ss=NULL, bool plata=false, int brv=0) : korisnici(broj, ss){
        this->plata=plata;
        this->brv=brv;
    }
    ~ kompanija () {}
    float raspSr(){
        float money = korisnici::sredstva(); float pom=money;
        for (int i=0; i<brv; i++)
            money+=10000;
        if (plata=true) money = pom*0.1;
        return money;
    }
    void pechati(){
        cout<<"kompanijata ima "<<brv<<" vraboteni, koi "<<(plata? "" : "ne")<<" primaat plata od taa smetka"<<endl;
        korisnici::pechati();
    }
};
