//avio kompanija
#include <iostream>
#include <cstring>
using namespace std;

class Patnik {
private:
    char imePrezime[30];
    int brpasosh;
    char destinacija[20];
    char zemja[20];
    int cena;
    int godina;
public:
    Patnik ( const char *ime = "", int pasp=0, const char *dest = "", const char *zemj = "", int c = 0, int god = 0){ //zs e char so const i pointer a drugite ne?
        strncpy(this->imePrezime, ime, 29); //zs se koristi strncpy a ne strcpy?
        imePrezime[29]=NULL; 
        brpasosh = pasp;
        strncpy(this->destinacija, dest, 19);
        destinacija[19]=NULL;
        strncpy(this->zemja, zemj, 19);
        zemja[19]=NULL;
        cena = c; 
        godina = god;
    }
    bool proverka (char *dest){ //proveruva dali patnikot ide na istata destinacija so vnesenata
        return strcmp(this->destinacija, dest)==0;
    }   
    void postavi (int brpas = 0 ){
        brpasosh = brpas;
        cena = 0;
    }
    char* getImeP() { return imePrezime; }
    int getCena() {return cena; }           //pak zs char e so pointer a int ne ?
    int getPasosh() {return brpasosh; }
    void setCena(int cena) {
        this->cena=cena;
    } 
    ~ Patnik () {}; 
};
class AvioLet {
private:
    string ime; //zs pogore char a ovde ime? zs take se baralo ok
    char lokP[15];
    char lokT[15];
    Patnik p[100];
    int n; //broj na patnici
    int sedishta[100];
public:
    AvioLet (const char* ime = "", const char* lokP="", const char* lokT="", Patnik *pa=0, int n=0, int* sedi=0){
        this->ime=ime;
        strncpy(this->lokP, lokP, 14); 
        this->lokP[14] = '\0'; // dali raboti programata vake so ova this ili mora pri inicijalizacija da se smeni lokP vo lokP1? 
        strncpy(this->lokT, lokT, 14);
        this->lokT[14] = '\0';  //zs ne moze da se napishe samo NULL tuku mora \0? 
        this->n=n;
        for (int i=0; i<n; i++){ //dali kje raboti samo so n bez this
            p[i] = pa[i];
            sedishta[i] = sedi[i];
        }
    }
    AvioLet (const AvioLet &a) { //dinamicka lokacija za da moze da se menuvaat vrednostite?
        ime=a.ime;
        strcpy (this->lokP, a.lokP); //razlika megju strncpy i strcpy e sho vo strncpy ja pishuesh dolzinata na char nizata? 
        strcpy (this->lokT, a.lokT); 
        this->n=a.n;
        for (int i=0; i<n; i++){
            this->p[i] = a.p[i];
            this->sedishta[i] = a.sedishta[i];
        }
    } //ova e prviot let pod ime a?
    string getIme(){ return ime; }
    void setIme (string str) { ime = str; }
    Patnik* proverka ( int *Listaz, int m){
        Patnik temp[100];
        int k=0; 
        for (int i=0; i<m; i++){
            for (int j=0; j<n; i++){
                if (p[j].getPasosh() == Listaz[i]) {
                    temp[k] = p[j];
                    k++; 
                }
            }
        }
        cout<<"ima "<<k<<" takvi patnici"<<endl;
        return temp; //zs se prae return temp?
    }
    float getPopust(int brp=0) {
        float suma = 0.0; 
        if ( brp == 0 ) {
            for (int i=0; i<n; i++){
                suma+= p[i].getCena() *0.1;
                p[i].setCena(p[i].getCena()*0.1);
            }
        }else{
            for (int i=0; i<n; i++){
                if (p[i].getPasosh()==brp){
                    suma = p[i].getCena() *0.15;
                    p[i].setCena(p[i].getCena()*0.15);
                }
            }
        }
        return suma;
    }
    void najmalaCena(){
        int index=0;
        int min = p[0].getCena();
        for (int i=0; i<n; i++){
            if (min > p[i].getCena()) {
                min=p[i].getCena();
                index = i;
            }
        }
        cout<<p[index].getImeP()<<" ima najmala cena na biletot."<<endl;
        cout<<"cenata iznesuva: "<<min<<endl;
    }
    ~ AvioLet () {};
};
int main()
{
    Patnik p1("Patnik1", 1234, "London", "Anglija", 455, 1985),
    p2("Patnik2", 1133, "Skopje", "Makedonija", 500, 1999);
    Patnik p[2];
    p[0] = p1;
    p[1] = p2;
    int s[] = { 0,1 };
    AvioLet ap("PalerMKD", "Rim", "Skopje", p, 2, s);
    ap.najmalaCena();
    return 0;
}