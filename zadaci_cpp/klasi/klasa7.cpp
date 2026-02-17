//kreveti 8.2
#include <iostream>
using namespace std;
class Krevet{
private:
    string ime;
    bool drvo;
    int osCena;
public:
    Krevet (string ime="", bool drvo = 0, int osCena = 0){
        this->ime=ime;
        this->drvo=drvo;
        this->osCena=osCena;
    }
    int cenaSoDostava(int CenaDostava=0) const {
        if (drvo) return (osCena + 12000 + CenaDostava);
        else return (osCena + CenaDostava);
    }
    friend bool operator>(const Krevet &k1, const Krevet &k2){
        if (k1.cenaSoDostava() > k2.cenaSoDostava()) return true;
        else return false;
    }
    friend bool operator>(int k1, const Krevet &k2){
        if (k1 > k2.cenaSoDostava()) return true;
        else return false;
    }
    friend bool operator>(const Krevet k1, int k2){
        if (k1.cenaSoDostava() > k2) return true;
        else return false;
    }
    bool operator==(const Krevet k){
        if (cenaSoDostava()==k.cenaSoDostava())
        return true;
        return false;
    }
    bool operator!=(const Krevet k){
        if (cenaSoDostava()!=k.cenaSoDostava()) return true;
        else return false;
    }
    Krevet &operator++(int){
        Krevet vrati(*this);
        osCena+=1000;
        return *this;
    }
    Krevet &operator+=(int x){
        
    }
};