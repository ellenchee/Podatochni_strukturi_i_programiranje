//studenti i predmeti
#include <iostream>
#include <cstring>
using namespace std;
class Predmet{
private:
    char *ime;
    int ocena;
    int krediti;
public:
    Predmet (char *ime = (char*) "", int ocenas=1.0, int kreditis=1 ) : ocena(ocenas), krediti(kreditis){
        this->ime = new char [strlen(ime)+1];
        strcpy(this->ime, ime);
    }
    ~Predmet(){ delete[] ime; }
    Predmet &operator=(const Predmet &a){
        if (this==&a) return *this;
        delete[] ime;
        ime = new char [strlen(a.ime)+1];
        strcpy(ime, a.ime);
        ocena=a.ocena;
        krediti=a.krediti;
        return *this;
    }
    Predmet &operator++(){
        krediti++;
        return *this;
    }
    Predmet &operator--(int){
        Predmet pomoshen (ime, ocena, krediti);
        krediti--;
        return pomoshen;
    }
    char &operator[](int n){
        return ime[n];
    }
    friend ostream &operator<<(ostream &out, Predmet &a){
        out<<"ime: "<<a.ime<<". ocena: "<<a.ocena<<". krediti: "<<a.krediti<<"."<<endl;
        return out;
    }
    int getOcena(){
        return ocena;
    }
    int getKrediti(){
        return krediti;
    }
};
class Student{
private:
    string ime;
    string prezime;
    int br;
    Predmet *polozeni;
public:
    Student (string ime = "", string prezime = "" , int br=0, Predmet *p=NULL){
        this->ime=ime;
        this->prezime=prezime;
        this->br=br;
        polozeni = new Predmet [br];
        for (int i=0; i<br; i++){
            polozeni[i] = p[i];
        }
    }
    ~Student () {delete[] polozeni;}
    Student &operator=(const Student& s){
        if (this==&s){
            return *this;
        }
        ime=s.ime; 
        prezime=s.prezime;
        br=s.br;
        polozeni = new Predmet [br];
        for (int i=0; i<br; i++){
            polozeni[i]=s.polozeni[i];
        }
        return *this;
    }
    Student &operator++(){
        for (int i=0; i<br; i++)
            ++polozeni[i];
        return *this;
    }
    Student operator--(int){
        Student p(ime, prezime, br, polozeni);
        for (int i=0; i<br; i++)
            polozeni[i]--;
        return p;
    }
    Student &operator+=(Predmet &u){
        Predmet *nov = new Predmet[br+1];
        for (int i=0; i<br; i++){
            nov[i]=polozeni[i];
        }
        nov[br]=u;
        br++;
        delete[] polozeni;
        polozeni=nov;
        return *this;
    }
    friend ostream& operator<<(ostream &out, Student &p){
        out<<"studentot blabla"<<p.ime<<p.prezime<<"ima blabla"<<p.polozeni<<"so blabla"<<p.krediti()<<endl;
        for (int i=0; i<p.br; i++) 
            out<<p.polozeni[i]<<endl;
        return out;
    }
    int krediti(){
        int b=0;
        for (int i=0; i<br; i++)
            b+=polozeni[i].getKrediti();
        return b;
    }
    float prosek(){
        if (br==0) return 0;
        float sum=0;
        for (int i=0; i<br; i++){
            sum+=polozeni[i].getOcena();
        }
        return sum/=br;
    }
};