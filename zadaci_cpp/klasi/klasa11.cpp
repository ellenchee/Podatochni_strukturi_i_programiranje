//sportisti 9.1
#include <iostream>
using namespace std;
class Sportist{
private:
    string ime;
    float bmi;
    int min;
public:
    Sportist (string ime="", float bmi=0.0, int min=0){
        this->ime=ime;
        this->bmi=bmi;
        this->min=min;
    }
    void pechati(){
        cout<<"ime: "<<ime<<endl;
        cout<<"bmi: "<<bmi<<endl;
        cout<<"min: "<<min<<endl;
    }
    float presmetajkal(){
        float kal = 100 + 1.1 * min + 20 * (bmi-21.7);
        return kal;
    }
    ~ Sportist () {}
};
class Maratonec : public Sportist{
private:
    int brk = 0 ;
public: 
    Maratonec (string imem="", float bmim=0.0, int minm=0, int brk=0) : Sportist(imem, bmim, minm) {
        this->brk=brk;
    }
    float presmetajkal(){
        float kal = Sportist::presmetajkal();
        kal += 30 * brk;
        return kal;
    }
    void pechati(){
        cout<<"tip na sportist: maratonec. "<<endl;
        Sportist::pechati();
        cout<<"broj na istrcani kilometri: "<<brk<<endl;
        cout<<"presmetaj kalorii: "<<presmetajkal()<<endl;
    }
};
class Velosipedist : public Sportist{
private:
    int vis;
    bool sam;
public:
    Velosipedist (string imev="", float bmiv=0.0, int minv=0, int vis=0, bool sam=false) : Sportist (imev, bmiv, minv){
        this->vis=vis;
        this->sam=sam;
    }
    void pechati();
    float presmetajkal();
};
void Velosipedist :: pechati() {
    cout<<"tip na sportist: velosipedist"<<endl; 
    Sportist::pechati();
    cout<<"visinska razlika "<<vis<<endl;
    cout<<(sam ? "vozel sam" : "vozem vo grupa")<<endl;
    cout<<"kalorii: "<<presmetajkal()<<endl;
}
float Velosipedist :: presmetajkal(){
    float kal = Sportist::presmetajkal();
    kal += 40 * vis /500;
    if (!sam){
        kal *= 0.8;
    }
    return kal;
}
