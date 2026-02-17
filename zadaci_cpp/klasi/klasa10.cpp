//nasleduvanje predmet i zadolzitelen predmet
#include <iostream>
using namespace std;
class Predmet {
private: 
    string ime;
protected:
    int min;
public:
    Predmet(string ime="", int min=0){
        this->ime=ime;
        this->min=min;
    }
    void pechati(){
        cout<<"ime na student: "<<ime<<". Minimum za polozuvanje: "<<min<<"."<<endl;
    }
    bool operator==(Predmet &A){
        return ime==A.ime;
    }
    string getimeS(){
        return ime;
    }
    int presmetaj(){
        return 0;
    }
    ~Predmet () {}
};
int brkg[2] = {0, 0};
class Zadolzitelen : public Predmet{
private:
    int brk[2];
    int lab;
public:
    Zadolzitelen (string ime="", int min=0, int lab=0, int brkv[2]=brkg) : Predmet (ime, min){
        this->lab=lab;
        brk[0] = brkv[0]; brk[1] = brkv[1];
        }
    void pechati(){
        cout<<"Tip na predemet: zadolzitelen. "<<endl;
        Predmet::pechati();
        cout<<"osvoeni poeni na kolokviumite: "<<brk[0]<<" i "<<brk[1]<<endl;
        cout<<"osvoeni poeni od lab vezbi: "<<lab<<endl;
        cout<<"vkupno poeni: "<<presmetaj()<<"shto se "<<(min>=presmetaj()? "dovolno" : "nedovolno")<<" za polozuvanje"<<endl; 
    }
    int presmetaj(){
        return brk[0] + brk[1] + lab;
    }
    ~ Zadolzitelen () {}
};
