//vektori i vektorski operacii 7.1
#include <iostream>
using namespace std;
class Vektor{
public:
    double *elementi;
    int dolzina;
    Vektor (double *e = NULL, int dolz = 0) : dolzina(dolz) {
        elementi = new double [dolzina];
        for (int i=0; i<dolzina; i++){
            elementi[i]=e[i];
        }
    }
    Vektor (const Vektor &v){
        dolzina=v.dolzina;
        elementi = new double [dolzina];
        for (int i=0; i<dolzina; i++){
            elementi [i] = v.elementi[i];
        }
    }
    ~Vektor () {
        delete[] elementi;
    }
    void dodadiElement(double e){
        double *pom;
        dolzina++;
        pom = new double [dolzina];
        for (int i=0; i<dolzina; i++)
            pom [i] = elementi [i];
        pom [dolzina-1] = e;
        delete[] elementi;
        elementi = pom; 
    }
    void izvadiElement(){
        double *pom;
        pom = new double [dolzina-1];
        for (int i=1; i<dolzina; i++)
            pom [i-1] = elementi[i];
        dolzina--;
        delete [] elementi;
        elementi=pom; 
    }
    void pechatiVektor(){
        cout<<"(";
        for (int i=0; i<dolzina-1; i++)
            cout<<elementi[i]<<", ";
        cout<<")"<<endl;
    }
};
Vektor soberi(const Vektor &a, const Vektor &b){
    if (a.dolzina!=b.dolzina) exit (-1);
    Vektor rez = a;
    for (int i=0; i<rez.dolzina; i++){
        rez.elementi[i]+=b.elementi[i];
    }
    return rez;
}
Vektor odzemi (const Vektor &a, const Vektor &b){
    if (a.dolzina!=b.dolzina) exit (-1);
    Vektor rez = a; 
    for (int i=0; i<rez.dolzina; i++){
        rez.elementi[i]-=b.elementi[i];
    }
    return rez;
}
double proizvod (const Vektor &a, const Vektor &b){
    if (a.dolzina!=b.dolzina) exit (-1);
    double rez;
    for (int i=0; i<a.dolzina; i++){
        rez += a.elementi[i] * b.elementi[i]; 
    }
    return rez;
}
int main() {
double elementi1[7] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8 };
double elementi2[7] = { 7.8, 6.7, 5.6, 4.5, 3.4, 2.3, 1.2 };
Vektor vek1 = Vektor(elementi1, 7);
Vektor vek2 = Vektor(elementi2, 7);
cout << "Vek1 = "; vek1.pechatiVektor();
Vektor sumv = soberi(vek1, vek2);
cout << "Sumata e: "; sumv.pechatiVektor();
Vektor razv = odzemi(vek2, vek1);
cout << "Razlikata e: "; razv.pechatiVektor();
vek1.izvadiElement();
vek1.dodadiElement(9.1);
cout << "Vek1 = "; vek1.pechatiVektor();
double proiz = proizvod(vek1, vek2);
cout << "Skalarniot proizvod e: " << proiz << endl;
return 0;
}