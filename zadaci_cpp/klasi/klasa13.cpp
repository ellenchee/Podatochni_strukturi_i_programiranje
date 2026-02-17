//rastenija 9.3
#include <iostream>
using namespace std;
class rastenie{
protected:
    bool tipsaksija;
public:
    rastenie (bool tip=false) : tipsaksija(tip) {};
    int cena();
    void pechati();
    bool operator!=(rastenie &r);
    friend istream& operator>>(istream &in, rastenie& r);
    ~rastenie(){}
};
int rastenie::cena() {
    if (tipsaksija)
        return 200;
    else 
        return 400;
}
void rastenie::pechati(){
    cout<<"rastenieto e vo saksija: "<<(tipsaksija ? "golema" : "mala")<<endl;
}
bool rastenie::operator!=(rastenie &r){
    if (cena() == r.cena()) return 1;
    else return 0;
}
istream &operator>>(istream &in, rastenie &r){
    cout<<"vnesi go tipot na saksija (0=golema, 1=mala): "<<endl;
    in>>r.tipsaksija;
    return in;
}
class cvekje : public rastenie{
protected:
    int brojdenovi;
public:
    cvekje (int brojdenovi, bool tip) : rastenie(tip){
        this->brojdenovi=brojdenovi;
    }
    int cena();
    void pechati();
    bool operator!=(cvekje &c);
    friend istream &operator>>(istream &in, cvekje &c);
    ~cvekje(){}
};
int cvekje :: cena(){
    int oscena = rastenie::cena();
    oscena = 10 * brojdenovi;
    return oscena;
}
void cvekje :: pechati(){
    cout<<"cvekjeto koe e rascutano "<<brojdenovi<<endl;
    rastenie::pechati();
}
bool cvekje :: operator!=(cvekje &c){
    if (cena() != c.cena()) return 1;
    return 0;
}
istream &operator>>(istream &in, cvekje &c){
    cout<<"vnesite tip na saksija (0=golema, 1=mala) i broj na denovi vo koi cvekjeto e rascutano:"<<endl;
    in>>c.tipsaksija>>c.brojdenovi;
    return in;
}
class krin : public cvekje{
protected: 
    bool ktip;
public:
    krin (bool kktip = true, bool tipsaksija = false, int brdenovi=10) : cvekje(brdenovi, tipsaksija), ktip(kktip){};
    int cena();
    void pechati();
    bool operator!=(krin &k);
    friend istream &operator>>(istream &in, krin &k);
    ~krin () {}
};
int krin :: cena(){
    int oscena = cvekje::cena();
    if (ktip) oscena+=100;
    return oscena;
}
void krin :: pechati(){
    cout<<"krin koj "<<(ktip? "e " : "ne e ")<<"krlaski."<<endl;
    cvekje::pechati();
}
bool krin :: operator!=(krin &k){
    if (cena() != k.cena()) return 1;
    return 0;
}
istream &operator>>(istream &in, krin &k){
    cout<<"tip na saksija (0=golema, 1=mala), denovi vo koi cuti, dali e kralski ili ne (1=da, 0=ne)? ";
    in>>k.tipsaksija>>k.brojdenovi>>k.ktip;
    return in;
}
