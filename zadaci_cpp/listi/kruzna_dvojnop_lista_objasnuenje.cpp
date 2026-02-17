/*Листата нема крај (NULL) (завртена е во јамка)
◼ Може да се итерира во двете насоки
◼ Структурата на јазолот останува иста како кај двојната
поврзана листа
◼ Има „два краја“ (подеднакво лесно може да се додаваат и
бришат елементи и од почетокот и од крајот на листата) но
мора да се внимава дека крајот има линк поле кое води до
почениот јазол*/
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//deklariranje i kreiranje:
typedef int info_t;
struct node {
    info_t info;
    node *next;
    node *prev;
};
struct CDLList {
        node *head;
        node *tail;
        void init();
        void ins_first(info_t x);
        void ins_last(info_t x);
        void mk_link_list(int n);
        void del_first();
        void del_last();
        node *find_first(info_t x);
        void printlist();
        void free_link_list();
    };

void CDLList::init() {
    head = tail = NULL;
}

//pechatenje:
void CDLList::printlist(){
    void printnode(node *p);
    node *p;
    for (p = head; p != tail; p = p->next) {
        printnode(p);
        cout << "<->";
    }
    printnode(p);
    cout<<endl;
    }

void printnode(node *p)
    {
    cout<<p->info;
}

//dodavanje na jazol na pochetok
void CDLList::ins_first(info_t data){
    node *p_ptr = new node;
    p_ptr->info = data;
    if(head == NULL){
    tail = head = p_ptr;
    p_ptr->prev =
    p_ptr->next = p_ptr;
    }else{
    p_ptr->next = head;
    p_ptr->prev = tail;
    tail->next = p_ptr;
    head->prev = p_ptr;
    head = p_ptr;
 }
}

//dodavanje na jazol na kraj
void CDLList::ins_last(info_t data){
    node* p_ptr = new node;
    p_ptr->info = data;
    if (head == NULL) {
    tail = head = p_ptr;
    p_ptr->prev =
    p_ptr->next = p_ptr;
    }else {
    p_ptr->prev = tail;
    p_ptr->next = head;
    tail->next = p_ptr;
    head->prev = p_ptr;
    tail = p_ptr;
 }
}

//kreiranje na dvojno povrzana kruzna lista
void CDLList::mk_link_list(int n)
{
    info_t data;
    init();

    while (n--)
    {
    cin>>data;
    ins_first(data);
    }
}
/*
Што ќе се испечати за внес 10 5 6 9 1
povik vo main:
//Повик во main():
CDLList D;
D.mk_link_list(5);
D.printlist(); 
1<->9<->6<->5<->10
*/

//brishenje na posleden jazol
void CDLList::del_last(){
    if (head != NULL){
    if (head == tail){
    delete head;
    head = tail = NULL;
    }
    else{
    node *pom = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete pom;
    }
    }
}

//brishenje na prv jazol
void CDLList::del_first() {
    if (head != NULL){
    if (head->next == head){
    delete head;
    head = tail = NULL;
    }
    else{
    node *pom = head;
    tail->next = head->next;
    head = head->next;
    head->prev = tail;

    delete pom;
    }
    }
}

//naogjanje na element:
node *CDLList::find_first(info_t x){
    node *l;
    for (l = head; l != tail && l->info != x; l = l->next);
    if(l==tail && l->info !=x)
    l = NULL;
    return l;
}

//brishenje na listata
void CDLList::free_link_list()
{
    while (head != NULL)
    del_first();
}

/*upotreba na listata:
int main(){
 CDLList D;
 D.init();
 D.ins_first(10); D.ins_last(9);
 D.ins_last(8); D.ins_first(6);
 D.printlist();
 D.ins_last(11);
 D.printlist();
 D.del_first();
 D.del_last();
 D.printlist();
 D.free_link_list();
 return 0;
}
pechatenje: 6<->10<->9<->8
6<->10<->9<->8<->11
10<->9<->8
*/