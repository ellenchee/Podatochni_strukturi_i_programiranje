//10.1 mediumi
#include <iostream>
#include <cstring>
using namespace std;
class medium{
private:
    string ime;
    int brv, lazv;
public:
    medium (string imem = "", int brvm = 0, int lazvm = 0 ) : ime(imem), brv(brvm), lazv(lazvm) {}
    virtual void pechati();
    virtual float indeks();
    virtual ~ medium(){}
};
void medium :: pechati(){
    cout<<"ime: "<<ime<<endl;
    cout<<"broj na vraboteni: "<<brv<<endl;
    cout<<"broj na lazni vesti: "<<lazv<<endl;
}
float medium :: indeks(){
    float inx = brv * 5 - lazv;
    return inx;
}
class tv : public medium {
private:
    bool prof; 
public: 
    tv (string imetv="", int brvtv=0, int lazvtv=0, bool prof = false ) : medium(imetv, brvtv, lazvtv) {
        this->prof = prof;
    }
    virtual void pechati();
    virtual float indeks();
    virtual ~tv (){}
};
float tv :: indeks(){
    float inx = medium::indeks();
    if (prof) return inx+=20;
    return inx;
}
void tv :: pechati(){
    cout<<"tip na medium: televizija."<<endl;
    medium:pechati();
    cout<<(prof? "Ima" : "Nema")<<" profil"<<endl;
    cout<<"indeks: "<<indeks()<<endl;
}
class portal : public medium{
private:
    int brpost;
public: 
    portal (string imep="", int brvp=0, int lazvp=0, int brpost=0) : medium (imep, brvp, lazvp) {
        this->brpost = brpost;
    }
    virtual void pechati();
    virtual float indeks();
    virtual ~ portal () {}
};
void portal :: pechati (){
    cout<<"tip na medium: portal"<<endl;
    medium::pechati();
    cout<<"broj na postovi: "<<brpost<<endl;
    cout<<"idenks: "<<indeks()<<endl;
}
float portal :: indeks () { 
    float inx = medium::indeks();
    inx = inx + (1 + 0.05 * brpost / 20);
    return inx; 
}
bool pomalIndex(medium* a, medium* b){
    if (a->indeks() < b->indeks()) return true;
    else return false;
}
int najmalindex(medium **a, int br){
    medium *iz = a[0];
    int ind = 0; 
    for (int i=1; i<br; i++){
        if (pomalIndex(a[i], iz)){
            iz = a[i];
            ind = i; 
        }
    }
    return ind;
}