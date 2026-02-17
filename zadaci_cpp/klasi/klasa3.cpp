// dinamicka alokacija - ucenici i oddelenija
#include <iostream>
#include <cstring>
#include <iomanip> // za sho e ova?
using namespace std;
class Ucenik{
private:
    char *ime;
    char *prezime;
    float prosek; 
    int godina;
public:
    Ucenik () : prosek(0.0), godina(0){ //zs e vake so : a ne standard so site promenlivi vo zagrada? primer Ucenik (int godina = 0, float prosek = 0.0 ...) a dole this->prosek=prosek...
        ime = new char [1]; 
        strcpy (ime, "");
        prezime = new char [1];
        strcpy (prezime, "");
    }
    Ucenik (char *i, char *p, int god, float pro) : prosek(pro), godina(god) { //zs uste eden konstruktor?
        ime = new char [strlen(i)+1];
        strcpy(ime, i);
        prezime = new char [strlen(p)+1];
        strcpy(prezime, p); 
    }   
    Ucenik (const Ucenik &u) : prosek (u.prosek), godina (u.godina) { //zs pak uste eden kostruktor?
        ime = new char [strlen(u.ime)+1];
        strcpy (ime, u.ime);
        prezime = new char [strlen(u.prezime)+1];
        strcpy (prezime, u.prezime);
    }
    ~ Ucenik () { 
        delete[] ime;
        delete[] prezime; //zs se brisha samo ime i prezime?
    }
    void setIme(char *i){
        delete[] ime; //zs e ova?
        ime = new char [strlen(i)+1];
        strcpy (ime, i);
    }
    void setPrezime(char *p){
        delete[] prezime;
        prezime = new char [strlen(p)+1];
        strcpy (prezime, p);
    }
    void setProsek (float prosek) {
        this->prosek=prosek;
    }
    void setGodina(int godina){
        this->godina=godina;
    }
    void pechati(){
        cout<<" "<<ime<<" "<<prezime<<" prosek: "<<prosek<<", godina: "<<godina<<"."<<endl;
    }
    void kopiraj (Ucenik &u){
        setIme(u.ime);
        setPrezime(u.prezime);
        setProsek(u.prosek);
        setGodina(u.godina);
    }
    float getProsek(){
        return prosek;
    }
    int getGodina(){
        return godina;
    }
    char *getIme(){
        return ime;
    }
    char *getPrezime(){
        return prezime;
    }
};
class Oddelenie{
public: //zs e sve u public?
    Ucenik *ucenici;
    int broj; 
    string oddelenie;
    Oddelenie (Ucenik *u = NULL, int broj = 0, string oddelenie = ""){
        this->oddelenie=oddelenie;
        this->broj=broj;
        ucenici = new Ucenik[broj];
        for (int i=0; i<broj; i++){
            ucenici[i].kopiraj(u[i]);
        }
    }
    Oddelenie (const Oddelenie &p){
        oddelenie=p.oddelenie;
        broj=p.broj;
        ucenici = new Ucenik [broj];
        for (int i=0; i<broj; i++){
            ucenici[i].kopiraj(p.ucenici[i]);
        } //zs ima 2 konstrukora?
    }
    ~ Oddelenie () {
        delete [] ucenici; //zs samo uceninci se brisha>
    }
    void dodadiUcenik (Ucenik &u){
        Ucenik *pom;
        pom = new Ucenik[broj+1];
        broj+=1;
        for (int i=0; i<broj-1; i++){
            pom[i].kopiraj(ucenici[i]);
        }
        pom[broj-1].kopiraj(u);
        delete[] ucenici;
        ucenici = pom ; 
    }
    void pecati(){
        cout<<"oddelenieto "<<oddelenie<<" ima "<<broj<<" ucenici:"<<endl;
        for (int i=0; i<broj; i++) ucenici[i].pechati();
    }
    void pechatiNaj(){
        cout<<"ucenici so prosek 5.00 vo oddelenieto "<<oddelenie<<" se:"<<endl;
        for (int i=0; i<broj; i++){
            if (ucenici[i].getProsek() == 5.00)  ucenici[i].pechati();
        }
    }
};
int main() {
Ucenik u[4] = {Ucenik(), Ucenik("Petar","Petrovski",5.0,2015),
Ucenik("Angela","Angelova",4.5,2015), Ucenik("Stojan","Stojanov",5.0,2014)};
u[1].pechati();
u[0].kopiraj(u[2]);
u[0].setIme("Marija");
u[0].setProsek(4.1);
Oddelenie p = Oddelenie(u, 4, "IIa");
p.pecati();
Ucenik nov = Ucenik("Iva","Ivanovska",5.0,2016);
p.dodadiUcenik(nov);
p.pecati();
p.pechatiNaj();
return 0;
}