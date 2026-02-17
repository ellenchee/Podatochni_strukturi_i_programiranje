//rabota so operatori
#include <iostream>
using namespace std;
class Dniza{
private:    
    int *p; //dinamicki alocirana niza
    int d; //dolzina na nizata
public:
    Dniza (int *pt = NULL, int d=0){
        p=new int[d];
        this->d=d;
        for (int i=0; i<d; i++){
            p[i] = pt[i];
        }
    }
    explicit Dniza (int dv){ //objansi sho e ovoa explicit 
        d=1;
        p=new int[d];
        p[0]=dv;
    }   
    ~Dniza(){delete[] p;}
    Dniza& operator=(const Dniza &a){
        if (this==&a) 
            return *this;
        delete []p;
        d=a.d;
        p = new int [d];
        for (int i=0; i<d; i++){
            p[i]=a.p[i];
        }
            return *this;
    }
    Dniza& operator+=(int j){
        int *nova = new int [d+1];
        for (int i=0; i<d; i++){
            nova[i] = p[i];
        }
        nova[d]=j;
        d++;
        delete [] p;
        p = nova;
        return *this;
    }
    Dniza& operator+(Dniza &a){
        Dniza nova;
        delete []nova.p;
        nova.p = new int [d+a.d];
        for (int i=0; i<d; i++){
            nova.p[i]=p[i];
        }
        for (int i=0; i<d; i++){
            nova.p[i+d]=a.p[i];
        }
        nova.d=d+a.d;
        return nova;
    }
    Dniza& operator--(){
        if (d==0) return *this;
        int* nova = new int [d-1];
        for (int i=0; i<d-1; i++){
            nova[i]=p[i];
        }
        d--;
        delete [] p;
        p=nova;
        return *this;
    }
    Dniza operator--(int){
        if (d==0) return *this;
        Dniza nov(p, d);
        int *nova= new int[d-1];
        for (int i=0; i<d-1; i++){
            nova[i] = p[i];
        }
        d--;
        delete[] p;
        p=nova;
        return nova;
    }
    friend bool operator>(const Dniza &a, const Dniza &b){
        if (a.d>b.d) return true;
        else return false;
    }
    bool operator<(Dniza &a){
        if (d<a.d) return true;
        else return false;
    }
    int & operator[](int a){
        return p[a];
    }
    int operator[](int a)const{
        return p[a];
    }
    friend ostream& operator<<(ostream &out, const Dniza &a){
        out<<"nizata ima "<<a.d<<" elementi:"<<endl;
        for (int i=0; i<a.d; i++){
            out<<a.p[i]<<" ";
        }
        out<<endl;
        return out;
    }
    friend istream& operator>>(istream &in, Dniza &a){
        cout<<"vnesete go brojot na elementi vo nizata a potoa vnesite gi chlenovite: "<<endl;
        in>>a.d;
        delete[] a.p;
        for (int i=0; i<a.d; i++){
            in>>a.p[i];
        }
        return in;
    }
    operator int (){
        if (d==0) return 0;
        else return p[0];
    }
};
