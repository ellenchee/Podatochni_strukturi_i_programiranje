//muzicko studio
#include <iostream>
#include <cstring>
using namespace std;
class Pejac{
private:
    char imePrezime[40];
    int godini;
    char lokacija[30];
    char zemja[20];
    int cena;
public:
    Pejac(const char* imePrezime = "", int godini = 0, const char* lokacija = "", const char *zemja = "", int cena = 0){
        strncpy (this->imePrezime, imePrezime, 39);
        this->imePrezime[39] = '\0';
        this->godini=godini;
        strncpy (this->lokacija, lokacija, 29);
        this->lokacija[29] = '\0';
        strncpy (this->zemja, zemja, 19);
        this->zemja[19] = '\0';
        this->cena=cena;
    }
    char *getImeP () { return imePrezime; }
    char *getLokacija () { return lokacija; }
    char *getZemja () { return zemja; }
    int getGodini () { return godini; }
    int getCena () { return cena; }
    void setImeP ( char imePrezime[40] ) {
        strncpy (this->imePrezime, imePrezime, 39);
        this->imePrezime[39] = '\0';
    }
    void setLokacija (char lokacija[30]){
        strncpy (this->lokacija, lokacija, 29);
        this->lokacija[29] = '\0';
    }
    void setZemja (char zemja[20]){
        strncpy (this->zemja, zemja, 19);
        this->zemja[19] = '\0';
    }
    void setCena (int cena){
        this->cena=cena;
    }
    void setGodini (int godini){
        this->godini=godini;
    }
    bool proverkaL (const char *lok){
        return strcmp(lok, this->lokacija)==0;
    }
    void postaviCena (const char* lokacija){
        if (proverkaL(lokacija)) 
            this->cena=0;
    }
    ~ Pejac () {};
};
class Koncert {
private:
    string ime;
    string lokacijaK;
    Pejac p[10];
    int n; //broj na pejaci
    int nadomestok[10];
public:
    Koncert (const char* ime = "", const char *lokacijaK = "", Pejac *pe=0, int n=0, int *nadomestok=0){
        this->ime=ime;
        this->lokacijaK=lokacijaK;
        this->n=n;
        for (int i=0; i<n; i++){
            p[i] = pe[i];
            this->nadomestok[i] = nadomestok[i];
        }
    }
    Koncert (const Koncert &k){
        ime = k.ime; 
        this->n = k.n; 
        lokacijaK = k.lokacijaK;
        for (int i=0; i<n; i++){
            this->p[i] = k.p[i];
            this->nadomestok[i] = k.nadomestok[i];
        }
    }
    string getIme() { return this->ime; }
    string getLokacijaK() { return this->lokacijaK; }
    int getN () { return this->n; }
    void setIme( string imee ) {
        ime=imee;
    }
    void proverkaBonus(Pejac *listaP, int m){
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (strcmp(p[j].getImeP(), listaP[i].getImeP()) == 0)
                nadomestok [j] += nadomestok [j] *0.15;
            }
        }
    }
    int getVkupno (char *pe){
        int suma = 0;
        for (int i=0; i<n; i++){
            if (strcmp(pe, p[i].getImeP()) == 0 ){
                return nadomestok[i] + p[i].getCena(); 
            }
        }
        for (int i=0; i<n; i++){
            suma += nadomestok[i];
        }
        return suma;
    }
    ~ Koncert () {}
};
int main() {
Pejac p1("Pej1", 34, "Makedonija", "Makedonija", 1005),
p2("Pej2", 53, "BalkanskiProstori", "Makedonija", 1500);
Pejac p[2];
p[0] = p1;
p[1] = p2;
int s[] = { 1000,1500 };
Koncert k1("Koncert 1", "Skopje", p, 2, s);
cout << "Za Koncert 1, peacot " << p1.getImeP();
cout << " ima vkupen nadomest: " << k1.getVkupno(p1.getImeP());
return 0;
}