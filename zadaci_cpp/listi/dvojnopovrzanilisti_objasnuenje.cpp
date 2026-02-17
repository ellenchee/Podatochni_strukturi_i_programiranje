#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
//deklariranje:
typedef int info_t;
struct node
{
    info_t info;
    node *next;
    node *prev;
};
struct DLList {
        node *head;
        node *tail;
        void init();
        void ins_after(node *l_ptr,info_t x);
        void ins_before(node *l_ptr,info_t x);
        void ins_first(info_t x);
        node *node_on_position(int n);
        void mk_link_list(int n);
        void del_first();
        void del_last();
        node *find_first(info_t x);
        node *find_last(info_t x);
        void printlist();
        void free_link_list();
        void ins_in_order(info_t x);
        };
    void DLList::init(){
    head = tail = NULL;
}

//dodavanje na jazol po daden jazol                         //Вметнување на јазол во средина на листа веднаш после јазолот на кој покажува l_ptr
void DLList::ins_after(node *l_ptr, info_t x){              //Потребно е да се ажурираат 4 линка
    node *pom_ptr = new node;
    pom_ptr->info = x;
    pom_ptr->prev = l_ptr;
    pom_ptr->next = l_ptr->next;
    if(l_ptr->next == NULL)
        tail = pom_ptr;
    else
        l_ptr->next->prev = pom_ptr;
    l_ptr->next = pom_ptr;
}

//vmetnuvanje na jazol pred daden jazol                 //Вметнување на јазол во средина на листа веднаш пред јазолот на кој покажува l_ptr
void DLList::ins_before(node *l_ptr, info_t x){
    node *pom_ptr = new node;
    pom_ptr->info = x;
    pom_ptr->next = l_ptr;
    pom_ptr->prev = l_ptr->prev;
    if(l_ptr->prev == NULL)
        head = pom_ptr;
    else
        l_ptr->prev->next = pom_ptr;
        l_ptr->prev = pom_ptr;
}

//dodavanje na jazol na pochetok na listata 
void DLList::ins_first(info_t data){                //Повик во main():
    node *pom_ptr = new node;                       //DLList L1;
    pom_ptr->info = data;                           //L1.init();
    pom_ptr->prev = NULL;                           //L1.ins_first(5);
    pom_ptr->next = head;                           //L1.ins_first(7);
    if(head == NULL)                                //L1.ins_first(3);
        tail = pom_ptr;
    else
        head->prev = pom_ptr;
    head = pom_ptr;
}

//pechatenje 
void DLList::printlist()
{
    void printnode(node *p);
    node *p;
    for (p = head; p != NULL; p = p->next)
    printnode(p);
    cout<<endl;
}
void printnode(node *p)
{
    cout<<p->info<<" ";
}

//vrakjanje na adresa na jazol na pozicija vo lista
node* DLList::node_on_position(int n) {
    node* pom_ptr = head;
    for (int i = 0; i < n && pom_ptr != NULL; i++)
        pom_ptr = pom_ptr->next;
    return pom_ptr;
}
/*povik vo main:
//Повик во main():
DLList D;
D.init();
D.ins_first(10);D.ins_first(9);
D.ins_first(8);D.ins_first(6);
D.printlist();
node* pom = D.node_on_position(2);
D.ins_before(pom, 4);
D.printlist();
D.ins_after(pom, 12);
D.printlist();

kje se ispechati:
6 8 9 10
6 8 4 9 10
6 8 4 9 12 10
*/

//vnesuvanje na dvojno povrzana lista 
void DLList::mk_link_list(int n)            //broj na elementi vo listata koja se kreira
{
    info_t data;
    init();
    while (n--)
    {
        cin>>data;
        ins_first(data);
    }
}

//brishenje na prv jazol vo listata
void DLList::del_first(){
    if (head != NULL){
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *pom = head;
            head = head->next;
            head->prev = NULL;
            delete pom;
        }
    }
}

//brishenje na posleden jazol vo listata
void DLList::del_last(){
    if (head != NULL) {
        if (head->next == NULL)
            {
            delete head;
            head = tail = NULL;
            }
        else
            {
            node *pom = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete pom;
            }
    }
}

//naogjanje na element vo listata:
node *DLList::find_first(info_t x){
    node *l;
    for (l = head; l != NULL && l->info != x; l = l->next);
    return (l != NULL ? l : NULL);
}
node *DLList::find_last(info_t x){
    node *l;
    for (l = tail; l != NULL && l->info != x; l = l->prev);
    return (l != NULL ? l : NULL);
}
//Враќа покажувач кон јазолот во кој е пронајдена вредноста или NULL ако не е пронајдена

//vmetnuvanje na element vo vekje podredena lista na soodvetno mesto
void DLList::ins_in_order(info_t x){
    node *p = head;
    if (x <= p->info) /* vmetni na chelo */
        ins_first(x);
    else /* najdi mu go mestoto */
    {
        while (p != NULL && p->info < x)
            p = p->next;
            if(p == NULL)
                ins_after(tail, x);
            else
                ins_before(p, x);
    }
} 

//brishenje na dvojno povrzana lista:
void DLList::free_link_list()
{
    while (head != NULL)
    del_first();
}
//mainot:
/*int main(){
DLList D;
D.init();
D.ins_first(10); D.ins_first(9);
 D.ins_first(8); D.ins_first(6);
D.printlist();
D.ins_in_order(7); D.printlist();
 D.del_first(); D.del_last();
D.printlist();
D.free_link_list();
}*/


