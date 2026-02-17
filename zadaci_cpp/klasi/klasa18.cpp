//10.2 elektricni uredi
#include <iostream>
#include <cstring>
using namespace std;
class ured{
protected:
    string enklasa;
    int oscena;
public:
    ured (string enklasa="F", int oscena = 0){
        this->enklasa=enklasa;
        this->oscena=oscena;
    }
    virtual void pechati();
    virtual void pmokjnost () = 0;
    virtual float presmetajodnos();
    virtual ~ured () {}
};
void ured :: pechati(){
    cout<<"energetska klasa: "<<enklasa<<endl;
    cout<<"osnovna cena: "<<oscena<<endl;
}
float ured :: presmetajodnos ( ) {
    int odnos, cena, kvalitet;
    cena = oscena; 
    if (enklasa=="F") kvalitet = 5;
    else kvalitet = 100 - (enklasa[0] - 'A') * 20;
    odnos = kvalitet / cena;
    return odnos;
}
int monvng [4] = {200, 200, 1000};
class multisplit : public ured {
private: 
    int monvn[4], mokn, brvn;
public: 
    multisplit(string enklasaa="F", int oscenaa=0, int *monv=NULL, int mokn=0, int brvn=0) : ured(enklasaa, oscenaa){
        this->mokn=mokn;
        this->brvn=brvn;
        for (int i=0; i<brvn; i++){
            monvn[i] = monv[i];
        }
    }
    virtual void pechati();
    virtual float presmetajmokjnost();
    virtual float presmetajodnos();
};
void multisplit :: pechati(){
    cout<<"tip na ured: multisplit"<<endl;
    ured::pechati();
    cout<<"ima "<<brvn<<" edinici so mokjnost: "<<endl;
    for (int i=0; i<brvn; i++){
        cout<<monvn[i]<<endl;
    }
    cout<<"mokjnosta na nadvoreshnata edinica e "<<mokn<<endl;
    cout<<"presmetaj mokjnost: "<<presmetajmokjnost<<endl;
    cout<<"presmetaj odnos: "<<presmetajodnos<<endl;
}
float multisplit :: presmetajmokjnost(){
    float mokjn;
    mokjn= mokn;
    for (int i=0; i<brvn; i++){
        mokjn += monvn[i];
    }
    return mokjn;
}
float multisplit :: presmetajodnos(){
    float odnos, kvalitet, cena;
    if (enklasa=="F") kvalitet=5;
    else kvalitet = 100 - (enklasa[0]-'A') *20;
    cena = oscena + 10 *presmetajmokjnost();
        odnos = kvalitet / cena;
    return odnos;
}
class frizider : public ured{
private: 
    int zafat;
    bool zam;
public: 
    frizider (int zafat=0, bool zam=false, string enklas="F", int oscen=0) : ured(enklas, oscen){
        this->zafat=zafat;
        this->zam=zam;
    }
    virtual void pechati();
    virtual float presmetajmokjnost();
    virtual float presmetajodnos();
};
void frizider :: pechati(){
    cout<<"tip na ured: frizider"<<endl;
    cout<<"zafat: "<<zafat<<endl;
    cout<<(zam? "Zamrzuvac" : "Odrzuvanje")<<endl;
    cout<<"presmetaj mokjnost: "<< presmetajmokjnost() <<endl;
    cout<<"presmetaj odnos: "<< presmetajodnos() <<endl;
}
float frizider :: presmetajmokjnost() {
    float mok;
    mok = zafat * 100;
    if (zam)
        mok = mok *1.5;
    return mok;
}
float frizider :: presmetajodnos(){
    float odnos, cena, kvalitet;
    if (enklasa=="F") kvalitet=5;
    else kvalitet = 100 - (enklasa[0]-'A') *20;
    cena = oscena + 15 * presmetajmokjnost();
    odnos = kvalitet / cena;
    return odnos;
}
void najdobarodnos(ured ** pob, int br){
    ured *iz = pob[0];
    for (int i=1; i<br; i++){
        if (iz->presmetajodnos() < pob[i]->presmetajodnos()) iz=pob[i];
    }
    cout<<"najdobar odnos: "<<iz;
}
