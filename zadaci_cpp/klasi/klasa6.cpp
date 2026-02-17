//klasa poema 8.1
#include <iostream>
#include <cstring>
using namespace std;
class Poema{
private: 
    string *stihovi;
    int brStihovi;
public:
    Poema (string *stih=NULL, int br){
        brStihovi=br;
        stihovi = new string [brStihovi];
        for (int i=0; i<brStihovi; i++){
            stihovi[i] = stih[i];
        }
    }
    Poema (const Poema &a){
        stihovi = new string [a.brStihovi];
        brStihovi = a.brStihovi;
        for (int i=0; i<a.brStihovi; i++){
            stihovi[i]=a.stihovi[i];
        }
    }
    ~Poema(){delete[] stihovi;}
    Poema &operator=(const Poema &a){
        if (this==&a) return *this;
        delete [] stihovi;
        brStihovi=a.brStihovi;
        stihovi = new string [brStihovi]; 
        for (int i=0; i<brStihovi; i++){
            stihovi[i]=a.stihovi[i];
        }
        return *this;
    }
    Poema &operator+=(string stih){
        string *nova = new string [brStihovi+1];
        for (int i=0; i<brStihovi; i++){
            nova[i+1]=stihovi[i];
        }
        nova[0]=stih;
        brStihovi++;
        delete [] stihovi;
        stihovi=nova;
        return *this;
    }
    Poema &operator-=(int pozicija){
        if (pozicija>brStihovi || pozicija<0) return *this;
        string *nova = new string [brStihovi-1];
        int j=0;
        for (int i=0; i<brStihovi; i++){
            if (i!=pozicija) {
                 nova[j]=stihovi[i];
                 j++;
                }
        }
        brStihovi--;
        delete[] stihovi;
        stihovi=nova;
        return *this;
    }
    Poema &operator+ (Poema &a){
        Poema nova;
        delete[] nova.stihovi;
        nova.stihovi=new string [brStihovi + a.brStihovi];
        for (int i=0; i<brStihovi; i++){
            nova.stihovi[i] = stihovi[i];
        }
        for (int i=0; i<a.brStihovi; i++) {
            nova.stihovi[i+brStihovi] = stihovi[i]; 
        }
        nova.brStihovi = brStihovi + a.brStihovi;
        return nova;
    }
    bool operator==(const Poema &a){
        if (brStihovi != a.brStihovi) return false;
        for (int i=0; i<brStihovi; i++){
            if (stihovi[i] != a.stihovi[i])
            return false;
        }
        return true;
    }
    Poema &operator--(){
        if (brStihovi==0) return *this;
        string *nova = new string [brStihovi-1];
        for (int i=0; i<brStihovi-1; i++){
            nova[i] = stihovi[i+1];
        }
        brStihovi--;
        delete[] stihovi;
        stihovi=nova;
        return *this;
    }
    Poema operator--(int){
        if (brStihovi==0) return *this;
        Poema nov (*this);
        string *nova = new string [brStihovi-1];
        for (int i=0; i<brStihovi-1; i++){
            nova[i] = stihovi[i+1];
        }
        brStihovi--;
        delete[] stihovi;
        stihovi=nova;
        return nov;
    }
    bool operator<(const Poema &a){
        if ( brStihovi < a.brStihovi ) return true;
        else return false;
    }
    bool operator<(const string &a){
        if (brStihovi < 1) return true;
        else return false;
    }
    /* friend bool operator<(const string &a1, const Poema &a2){
        if ( a1 < a2.brStihovi ) return true;
        else return false;  nz zs baraa sporedba string so int ama nejce
    }*/
    friend bool operator==(Poema &a, Poema &b){
        if (a.brStihovi != b.brStihovi) return false;
        for (int i=0; i<a.brStihovi; i++) {
            if (a.stihovi[i] != b.stihovi[i]) return false;
        }
        return true;
    }
    string &operator[](int i){
        return stihovi[i];
    }
    string &operator[](int i)const {
        return stihovi[i];
    }
    friend ostream &operator<<(ostream &out, const Poema &a){
        for (int i=0; i<a.brStihovi; i++){
            out<<a.stihovi[i]<<endl;
        }
        out<<endl;
        return out;
    } 
    friend istream &operator>>(istream &in, Poema &a){
        cout<<"prvo vnesi go brojot na stihovi pa stihovite nigga"<<endl;
        in>>a.brStihovi;
        string pom;
        int cont=0;
        getline (in, pom);
        if (pom.length()>1){
            cont=1;
        }
        delete[] a.stihovi;
        a.stihovi=new string [a.brStihovi];
        for (int i=0; i<a.brStihovi; i++){
            if (i==0 && cont==1) 
                a.stihovi[0] = pom; 
            else 
                getline(in, a.stihovi[i]);
        }
        cout<<endl;
        return in;
    }
};