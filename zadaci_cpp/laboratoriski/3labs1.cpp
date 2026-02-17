/******************************************************************************

Да се имплементира функција која како аргументи добива единечно поврзана листа, а чија 
задача е да ги заротира елементите на парна и непарна позиција (да се смета дека почетниот 
елемент е на позиција 0). При промените да не се креираат и бришат јазли туку постојните јазли 
да се прераспределат. Да се смета дека листата има парен број на елементи. 
Како дел од програмата да се напишат структури за имплементација на јазол и листа заедно 
со функциите за поддршка на листата: функции за иницијализација, додавање и бришење на 
елемент на почеток од листата, додавање и бришење на елемент на крај од листата, бришење на 
цела листа, бришење на даден јазол (јазолот се добива како аргумент во функцијата) и печатење 
на елементите од листата. Како дел од програмата да се напише main функција во која ќе се 
дефинира и иницијализира листата, и ќе се пополни со елементи кои се внесуваат преку тастатура. 
Во main функцијата потоа да се повика функцијата за печатење на листата, по што ќе се повика 
бараната функција (која треба да се имплементира) и на крај ќе се испечати листата после 
модификацијата.  
Пример: 
list = |12|->|7|->|5|->|13|->|5|->|9|->NULL 
Решение: 
list = |7|->|12|->|13|->|5|->|9|->|5|->NULL
*******************************************************************************/
#include <iostream>
using namespace std;
struct jazol{
    int info;
    jazol *link;
};
struct lista{ 
    jazol *head;
    void init(){
        head==NULL;
    }
    void nova(int e){
        head = new jazol; 
        head -> info = e;
        head -> link = NULL;
    }
    void dodadiPrv(int prv){
        jazol *p = new jazol;
        p -> info = prv; 
        p -> link = head;
        head = p; 
    }
    void dodadiPosleden (int posleden){
        jazol *p = new jazol; 
        p -> info = posleden;
        p -> link = NULL; 
        if (head==NULL){
            head == p; 
        }
        else {
            jazol *dvizhenje = head;
            while (dvizhenje -> link != NULL){
                dvizhenje = dvizhenje -> link; 
            }
            dvizhenje -> link = p;
        }
    }
    void brishiPrv(){
        if (head!=NULL){
            jazol *p = head;
            head = head -> link;
            delete p;
        }
    }
    void brishiPosleden(){
        if (head==NULL) return;
        if (head -> link == NULL){
            delete head;
            head = NULL;
        }
        else {
            jazol *dvizhenje = head; 
            while (dvizhenje->link->link != NULL) {
                dvizhenje = dvizhenje -> link; 
            }
            delete dvizhenje -> link;
            dvizhenje -> link = NULL; 
        }
    }
    void brishiJazol(jazol *j){
        if (j==NULL) return;
        if ( j==head ){
            brishiPrv();
            return;
        }
        jazol *prev = head;
        while (prev != NULL && prev->link!=j) prev = prev -> link ; 
        if (prev!=NULL){
            prev->link = j->link;
            delete j;
        }
    }
    void brishiLista(){
        while (head != NULL)
        {
            brishiPrv();
        }
    }
    void pechati (){
        for (jazol *j=head; j->link!=NULL; j=j->link){
            cout<<j->info<<" ";
        }
        cout<<"NULL"<<endl;
    }
    void rotiraj(){
        if (head == NULL || head->link==NULL) return;
        jazol *prev=head;
        jazol *current=head->link;
        while (current!=NULL && current->link!=NULL){
            int temp = prev->info;
            prev->info = current->info;
            current->info=temp;
            prev=current->link;
            current=prev->link;
        }
        if (current!=NULL){
            int temp = prev->info;
            prev->info = current->info;
            current->info = temp;
        }
    }
};
int main()
{
    int n, element;
    lista L;
    L.init();
    cout<<"vnesi go brojot na elementi vo listata:";
    cin>>n;
    if (n%2==0) {
        cout<<"listata mora da ima paren broj na elementi."<<endl;
        return 0;
    }
    cout<<"vnesi gi elementite na listata: ";
    for (int i=0; i<n; i++){
        cin>>element;
        if (i==0){
            L.nova(element);
        }
        else {
            L.dodadiPosleden(element);
        }
    }
    cout<<"lista pred modificiranje: ";
    L.pechati();
    L.rotiraj();
    cout<<"listata po modificiranje: ";
    L.pechati();
    L.brishiLista();
    return 0;
}